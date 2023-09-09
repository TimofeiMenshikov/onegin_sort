#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include "string_func.h"


void link_text_and_buf(char** text, char* buffer, size_t buffer_size)
{
	text[0] = buffer; // присваиваем первому указателю text ссылку на первый элемент buffer, то есть на первую строку

	size_t text_pos = 1; // позция в "массиве" text

	for (size_t char_number = 0; char_number < buffer_size; char_number++)
	{
		printf("pos %zu: %c(%d)\n", char_number, buffer[char_number], buffer[char_number]);
		if (buffer[char_number] == '\0')
		{
			text[text_pos] = buffer + char_number + 1; // находим конец строки и присваеваем адрес следующего элемента элементу массива 
			text_pos++;
		}
	}

	for (size_t i = 0; i < text_pos; i++)
	{
		printf("addres number %zu is %p\n", i, text[i]);
	}
}


void free_all(char** text, char* buffer, size_t n_strings)
{
	/* free buffer */
	free(buffer);
	/* free buffer */

	/* free text */
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		free(text[n_string]);
	}
	free(text);
	text = 0;
	/* free text*/
}


void swap_strings(char** pos_1_ptr, char** pos_2_ptr)
{
	char* temp = *pos_1_ptr;
	*pos_1_ptr = *pos_2_ptr;
	*pos_2_ptr = temp; 
}


void print_text(char** text, size_t n_strings)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		printf("string number %zu: <%s>\n", n_string, text[n_string]);
	}
}


enum comp_two_str compare_two_strings(char* str1, char* str2)
{
	for (size_t char_number = 0;;char_number++)
	{
		if (str1[char_number] == '\0' && str2[char_number] == '\0')
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number] < str2[char_number])
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number] > str2[char_number])
		{
			return FIRST_IS_RIGHT;
		}
	}

	return FIRST_IS_LEFT;
}



void sort_strings(char** text, size_t n_strings)
{
	for (size_t i = 0; i < n_strings; i++)
	{
		for (size_t j = i + 1; j < n_strings; j++)
		{
			if (compare_two_strings(text[i], text[j]) == FIRST_IS_RIGHT)
			{
				swap_strings(text + i, text + j);
			}
		}
	}
}

int main()
{
	struct stat buffer_info;

	stat("onegin.txt", &buffer_info);

	FILE *inputfile = fopen("onegin.txt", "r");

	char* buffer = (char*) calloc(buffer_info.st_size / sizeof(char) + 1, sizeof(char));

	fread(buffer, sizeof(char), buffer_info.st_size, inputfile);

	size_t buffer_size = buffer_info.st_size / sizeof(char) + 1;

	size_t n_strings = find_n_strings(buffer, buffer_info.st_size);

	printf("the number of strings is: %zu\n", n_strings);

	buffer_size = find_real_buf_size(buffer, buffer_size);

	char** text = (char**) calloc(1 + n_strings, sizeof(char*));

	link_text_and_buf(text, buffer, buffer_size);

	sort_strings(text, n_strings);

	print_text(text, n_strings);

	free_all(text, buffer, n_strings);
}