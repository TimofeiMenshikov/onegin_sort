#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include <assert.h>
#include "string_func.h"
#include "string_compare.h"
#include "sort.h"


size_t find_n_strings( char* const buffer, const size_t buffer_size);  // find count of string and replace '\n' to '\0'


void link_text_and_buf(char** const text,  char* const buffer, const size_t buffer_size)
{
	text[0] = buffer; // присваиваем первому указателю text ссылку на первый элемент buffer, то есть на первую строку

	size_t text_pos = 1; // позция в "массиве" text

	for (size_t char_number = 0; char_number < buffer_size - 1; char_number++) // buffer_size - 1, чтобы не считывало последний \0
	{
		printf("pos %zu: %c(%d)\n", char_number, buffer[char_number], buffer[char_number]);
		if (buffer[char_number] == '\0')
		{
			text[text_pos] = buffer + char_number + 1; // находим конец строки и присваеваем адрес следующего элемента элементу массива 
			printf("added link number %zu: read element %c(%d) next element %c(%d)\n", text_pos, buffer[char_number], buffer[char_number], buffer[char_number + 1], buffer[char_number + 1]);
			text_pos++;
		}
	}

	for (size_t i = 0; i < text_pos; i++)
	{
		printf("addres number %zu is %p\n", i, text[i]);
	}
}


void free_all(char** text, char* buffer, size_t* string_lengths)
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


void print_text(const char* const * const text, const size_t n_strings)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		printf("string number %zu: <%s>\n", n_string, text[n_string]);
	}
}


void print_and_sort(char** const text, const size_t n_strings)
{
	print_text(text, n_strings);

	printf("_._._._._._._\n");

	printf("sorted strings: \n");

	sort_strings(text, n_strings);

	print_text(text, n_strings);	

	printf("------------------\n");

	printf("returned back: \n");

	sort_ptrs(text, n_strings);

	print_text(text, n_strings);
}



size_t* find_str_lens(const char* const * const text, size_t n_strings)
{
	size_t* string_lengths = (size_t*) calloc(n_strings, sizeof(size_t)); 

	printf("calloc string_lengths\n");

	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		//string_lengths[n_string] = strlen(text[n_string]);
		printf("find strlen %zu\n", n_string);
	}

	printf("prepare to return string_lengths\n");

	return string_lengths;
}


int main()
{
	struct stat buffer_info;

	stat("onegin.txt", &buffer_info);

	FILE *inputfile = fopen("onegin.txt", "r");

	assert(inputfile);

	char* buffer = (char*) calloc(buffer_info.st_size / sizeof(char) + 1, sizeof(char));

	fread(buffer, sizeof(char), buffer_info.st_size, inputfile);

	size_t buffer_size = buffer_info.st_size / sizeof(char) + 1;

	buffer_size = find_real_buf_size(buffer, buffer_size); // запуск строго до find_n_strings, так как просчет количества символов до \0, а find_n_string меняет \n на \0

	size_t n_strings = find_n_strings(buffer, buffer_info.st_size);

	printf("the number of strings is: %zu\n", n_strings);

	char** text = (char**) calloc(n_strings, sizeof(char*));

	printf("calloc text \n");

	size_t* string_lengths = find_str_lens(text, n_strings);



	link_text_and_buf(text, buffer, buffer_size);

	print_and_sort(text, n_strings);


	free_all(text, buffer, string_lengths);
}