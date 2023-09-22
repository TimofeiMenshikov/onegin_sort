#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include <assert.h>
#include "include/string_func.h"
#include "include/string_compare.h"
#include "include/sort.h"
#include "include/print.h"
#include "include/main.h"
#include "include/printf_debug.h"



void link_text_and_buf(char** const text,  char* const buffer, const size_t buffer_size)
{
	text[0] = buffer; // присваиваем первому указателю text ссылку на первый элемент buffer, то есть на первую строку

	size_t text_pos = 1; // позция в "массиве" text

	for (size_t char_number = 0; char_number < buffer_size - 1; char_number++) // buffer_size - 1, чтобы не считывало последний \0
	{
		DEBUG_EXEC(printf("pos %zu: %c(%d)\n", char_number, buffer[char_number], buffer[char_number]));

		if (buffer[char_number] == '\0')
		{
			text[text_pos] = buffer + char_number + 1; // находим конец строки и присваеваем адрес следующего элемента элементу массива 

			DEBUG_EXEC(printf("added link number %zu: read element %c(%d) next element %c(%d)\n", text_pos, buffer[char_number], buffer[char_number], buffer[char_number + 1], buffer[char_number + 1]));

			text_pos++;
		}
	}

	for (size_t i = 0; i < text_pos; i++)
	{
		DEBUG_EXEC(printf("addres number %zu is %p\n", i, text[i]));
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


ssize_t* find_str_lens(const char* const * const text, ssize_t n_strings)
{
	ssize_t* string_lengths = (ssize_t*) calloc(n_strings, sizeof(ssize_t)); 

	DEBUG_EXEC(printf("calloc string_lengths\n"));


	for (ssize_t n_string = 0; n_string < n_strings; n_string++)
	{
		string_lengths[n_string] = strlen(text[n_string]);

		DEBUG_EXEC(printf("find strlen %zu/%zu string is %s\n", n_string, n_strings - 1, text[n_string]));
	}

	DEBUG_EXEC(printf("prepare to return string_lengths\n"));

	return string_lengths;
}


FILE* open_file(const char* const filename, const char* const modificator)
{
	FILE* inputfile = fopen(filename, modificator);

	assert(inputfile);

	return inputfile;
}


int main()
{
	struct stat buffer_info;

	char filename[] = "txt/input/onegin.txt";

	FILE* inputfile = open_file(filename, "r");

	stat(filename, &buffer_info);

	char* buffer = (char*) calloc(buffer_info.st_size / sizeof(char) + 1, sizeof(char));

	size_t buffer_size = fread(buffer, sizeof(char), buffer_info.st_size, inputfile) + 1;


	buffer[buffer_size - 1] = '\0';

	fclose(inputfile);

	size_t n_strings = find_n_strings(buffer, buffer_size);

	nulled_buffer(buffer, buffer_size);

	printf("the number of strings is: %zu\n", n_strings);

	char** text = (char**) calloc(n_strings, sizeof(char*));

	printf("calloc text \n");

	link_text_and_buf(text, buffer, buffer_size);

	ssize_t* string_lengths = find_str_lens(text, n_strings); // запуск строго после nulled_buffer, так как использует \0 при расчете длин строк

	print_and_sort(text, n_strings, string_lengths);

	free_all(text, buffer, string_lengths);
}