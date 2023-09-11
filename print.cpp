#include <stdio.h>
#include "sort.h"
#include "print.h"


void print_text(const char* const * const text, const size_t n_strings, FILE* outputfile)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		//printf("string number %zu: <%s>\n", n_string, text[n_string]);
		fputs(text[n_string], outputfile);
		fputs("\n", outputfile);
	}
}


void print_and_sort(char** const text, const size_t n_strings, size_t* string_lengths, FILE* outputfile)
{
	print_text(text, n_strings, outputfile);

	print_string_lenghts(string_lengths, n_strings);

	printf("_._._._._._._\n");

	printf("sorted strings: \n");

	sort_strings(text, n_strings, string_lengths, false);

	fclose(outputfile);

	outputfile = fopen("output_sorted.txt", "w");

	print_text(text, n_strings, outputfile);	

	print_string_lenghts(string_lengths, n_strings);

	printf("------------------\n");

	printf("sorted strings reversed: \n");

	sort_strings(text, n_strings, string_lengths, true);

	fclose(outputfile);

	outputfile = fopen("output_sorted_reversed.txt", "w");

	print_text(text, n_strings, outputfile);	

	print_string_lenghts(string_lengths, n_strings);

	printf("-_-_-_-_-_-_-_-_-_-\n");	

	printf("returned back: \n");

	sort_ptrs(text, n_strings, string_lengths);

	fclose(outputfile);

	outputfile = fopen("output_returned.txt", "w");

	print_text(text, n_strings, outputfile);

	print_string_lenghts(string_lengths, n_strings);
}


void print_string_lenghts(const size_t* const string_lengths, const size_t n_strings)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		//printf("string number: %zu, string length: %zu\n", n_string, string_lengths[n_string]);
	}
}

void print_reversed_str(const char* const str, const size_t str_length)
{
	for (ssize_t char_number = str_length - 1; char_number >= 0; char_number--)
	{
		putchar(str[char_number]);
	}
}

