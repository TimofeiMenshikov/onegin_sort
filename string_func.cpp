#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include "string_func.h"

size_t find_real_buf_size(char*  buffer, size_t buffer_size) // отбрасывает все \0 справа, кроме одного если \0 нет, то ставит \0 как дополнительный символ
{
	printf("buffer size is before for %zu \n", buffer_size);

	size_t char_number = 0;

	for (char_number = 0; buffer[char_number] != '\0'; char_number++); // просчитываем все значения char до '\0'

	buffer_size = char_number;

	buffer_size = buffer_size + 1; // добавляем один элемент для окончания строки (\n или \0)

	buffer[buffer_size] = '\0';

	printf("buffer size now is %zu \n", buffer_size);

	return buffer_size;
}


size_t find_n_strings( char* const buffer, const size_t buffer_size)  // find count of string and replace '\n' to '\0'
{
	size_t n_strings = 0;
	for (size_t char_number = 0; char_number < buffer_size; char_number++)
	{
		if (buffer[char_number] == '\n')
		{
			n_strings++;
			buffer[char_number] = '\0';
		}
	}
	return n_strings + 1; // последний элемент \0 - конец строки, а ы его не посчитали
}


void string_research(const char* const string)
{
	for (size_t string_number = 0; string[string_number] != '\0'; string_number++)
	{
		printf("%c(%d)", string[string_number], string[string_number]);
	}
	printf("%c(%d)", '\0', '\0');
	printf("\n");
}
