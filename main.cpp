#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include <assert.h>
#include "string_func.h"
#include "string_compare.h"
#include "sort.h"
#include "print.h"


void link_text_and_buf(char** const text,  char* const buffer, const size_t buffer_size)
{
	text[0] = buffer; // присваиваем первому указателю text ссылку на первый элемент buffer, то есть на первую строку

	size_t text_pos = 1; // позция в "массиве" text

	for (size_t char_number = 0; char_number < buffer_size - 1; char_number++) // buffer_size - 1, чтобы не считывало последний \0
	{
		//printf("pos %zu: %c(%d)\n", char_number, buffer[char_number], buffer[char_number]);
		if (buffer[char_number] == '\0')
		{
			text[text_pos] = buffer + char_number + 1; // находим конец строки и присваеваем адрес следующего элемента элементу массива 
			//printf("added link number %zu: read element %c(%d) next element %c(%d)\n", text_pos, buffer[char_number], buffer[char_number], buffer[char_number + 1], buffer[char_number + 1]);
			text_pos++;
		}
	}

	for (size_t i = 0; i < text_pos; i++)
	{
		//printf("addres number %zu is %p\n", i, text[i]);
	}
}


void free_all(char** text, char* buffer, ssize_t* string_lengths)
{
	/* free buffer */
	free(buffer);
	buffer = 0;
	printf("buffer is free\n");
	/* free buffer */

	/* free text */
	free(text);
	printf("text is free\n");
	text = 0;
	/* free text*/

	/* free string_lenghts */
	free(string_lengths);
	printf("string_lenghts is free\n");
	string_lengths = 0;
	/* free string_lenghts */
}


ssize_t* find_str_lens(const char* const * const text, size_t n_strings)
{
	ssize_t* string_lengths = (ssize_t*) calloc(n_strings, sizeof(ssize_t)); 

	printf("calloc string_lengths\n");

	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		string_lengths[n_string] = strlen(text[n_string]);
		//printf("find strlen %zu\n", n_string);
	}

	printf("prepare to return string_lengths\n");

	return string_lengths;
}


size_t find_max_str(ssize_t* string_lengths, size_t n_strings)
{
	size_t maxlen = 0;

	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		if (maxlen < string_lengths[n_string])
		{
			maxlen = string_lengths[n_string];
		}		
	}

	return maxlen;
}


int main()
{
	struct stat buffer_info;

	char inputfile_name[] = "txt/input/onegin.txt";

	stat(inputfile_name, &buffer_info);

	FILE* inputfile = fopen(inputfile_name, "r");

	assert(inputfile);

	char* buffer = (char*) calloc(buffer_info.st_size / sizeof(char) + 1, sizeof(char));

	size_t buffer_size = fread(buffer, sizeof(char), buffer_info.st_size, inputfile);

	fclose(inputfile);

	size_t n_strings = find_n_strings(buffer, buffer_info.st_size);

	printf("the number of strings is: %zu\n", n_strings);

	char** text = (char**) calloc(n_strings, sizeof(char*));

	printf("calloc text \n");

	link_text_and_buf(text, buffer, buffer_size);

	ssize_t* string_lengths = find_str_lens(text, n_strings); // запуск строго после find_n_strings, так как использует \0 при расчете длин строк

	//ssize_t maxlen = find_max_str(string_lengths, n_strings);

	//printf("the biggest len of string is %zu\n", maxlen);

	print_and_sort(text, n_strings, string_lengths);

	free_all(text, buffer, string_lengths);
}