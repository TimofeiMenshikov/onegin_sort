#include <stdio.h>
#include <assert.h>
#include "include/sort.h"
#include "include/print.h"
#include "include/main.h"


void print_text(const char* const * const text, const size_t n_strings, FILE* outputfile)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{
		fputs(text[n_string], outputfile);
		fputs("\n", outputfile);
	}
}


void print_one_sort(char** const text,  const size_t n_strings, ssize_t* string_lengths, char* filename,  enum comp_two_str (*comparator)(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2))
{
	FILE* outputfile = fopen(filename, "w");

	assert(outputfile);

	my_qsort(text, 0, n_strings - 1, comparator, string_lengths);

	print_text(text, n_strings, outputfile);

	print_string_lenghts(string_lengths, n_strings);



	fclose(outputfile);
}


void print_and_sort(char** const text, const size_t n_strings, ssize_t* string_lengths)
{
	print_one_sort(text, n_strings, string_lengths, "txt/output/output_sorted.txt", compare_two_strings);

	print_one_sort(text, n_strings, string_lengths, "txt/output/output_sorted_reversed.txt", compare_two_strings_reversed);

	print_one_sort(text, n_strings, string_lengths, "txt/output/output_returned.txt", compare_two_ptrs);
}


void print_string_lenghts(const ssize_t* const string_lengths, const size_t n_strings)
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


void print_state( char** arr, const ssize_t size, const ssize_t left, const ssize_t right)
{
    for (ssize_t number = 0; number < size; number++)
    {

        if (number == left)
        {
            putchar('{');
        }
        else
        {
            putchar(' ');
        }

 
        putchar(' ');


        printf("%s", arr[number]);


        putchar(' ');

        if (number == right)
        {
            putchar('}');
        }
        else
        {
            putchar(' ');
        }

    }
    putchar('\n');
}


void print_buffer(char* const buffer, const size_t buffer_size)
{
	for (size_t char_number = 0; char_number < buffer_size; char_number++)
	{
		printf("char number %zu: %c(%d)\n", char_number, buffer[char_number], buffer[char_number]);
	}
}