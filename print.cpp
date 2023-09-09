#include <stdio.h>
#include "sort.h"
#include "print.h"


void print_text(const char* const * const text, const size_t n_strings)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		printf("string number %zu: <%s>\n", n_string, text[n_string]);
	}
}


void print_and_sort(char** const text, const size_t n_strings, size_t* string_lengths)
{
	print_text(text, n_strings);

	print_string_lenghts(string_lengths, n_strings);

	printf("_._._._._._._\n");

	printf("sorted strings: \n");

	sort_strings(text, n_strings, string_lengths, false);

	print_text(text, n_strings);	

	print_string_lenghts(string_lengths, n_strings);

	printf("------------------\n");

	printf("sorted strings reversed: \n");

	sort_strings(text, n_strings, string_lengths, true);

	print_text(text, n_strings);	

	print_string_lenghts(string_lengths, n_strings);

	printf("-_-_-_-_-_-_-_-_-_-\n");	

	printf("returned back: \n");

	sort_ptrs(text, n_strings, string_lengths);

	print_text(text, n_strings);

	print_string_lenghts(string_lengths, n_strings);
}


void print_string_lenghts(const size_t* const string_lengths, const size_t n_strings)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		printf("string number: %zu, string length: %zu\n", n_string, string_lengths[n_string]);
	}
}

void print_reversed_str(const char* const str, const size_t str_length)
{
	for (ssize_t char_number = str_length - 1; char_number >= 0; char_number--)
	{
		putchar(str[char_number]);
	}
}

