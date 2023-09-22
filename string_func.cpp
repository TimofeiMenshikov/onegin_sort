#include <stdio.h>
#include <sys/stat.h>
#include <malloc.h>
#include "include/string_func.h"


size_t find_n_strings(const char* const buffer, const size_t buffer_size)  /// find count of string 
{
	size_t n_strings = 0;
	for (size_t char_number = 0; (char_number < buffer_size) && (buffer[char_number] != '\0'); char_number++)
	{
		if (buffer[char_number] == '\n')
		{
			n_strings++;
		}
	}
	return n_strings + 1; // последний элемент \0 - конец строки, а мы его не посчитали
}


void nulled_buffer(char* const buffer, const size_t buffer_size) /// function, that replaces '\n' to '\0'
{
	for (size_t char_number = 0; char_number < buffer_size; char_number++)
	{
		if (buffer[char_number] == '\n')
		{
			buffer[char_number] = '\0';
		}
	}	
}


void string_research(const char* const string) /// function that allows you to view invisible chars in string
{
	for (size_t string_number = 0; string[string_number] != '\0'; string_number++)
	{
		printf("%c(%d)", string[string_number], string[string_number]);
	}
	printf("%c(%d)", '\0', '\0');
	printf("\n");
}
