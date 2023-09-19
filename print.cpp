#include <stdio.h>
#include <assert.h>
#include "include/sort.h"
#include "include/print.h"


void print_text(const char* const * const text, const size_t n_strings, FILE* outputfile)
{
	for (size_t n_string = 0; n_string < n_strings; n_string++)
	{

		//printf("string number %zu: <%s>\n", n_string, text[n_string]);
		fputs(text[n_string], outputfile);
		//printf("%s", text[n_string]);
		fputs("\n", outputfile);
		//putchar('\n');
	}
}


void print_and_sort(char** const text, const size_t n_strings, ssize_t* string_lengths)
{
	FILE* outputfile = fopen("txt/output/output.txt", "w");

	assert(outputfile);

	print_text(text, n_strings, outputfile);

	print_string_lenghts(string_lengths, n_strings);

	printf("_._._._._._._\n");

	printf("sorted strings: \n");

	//sort_strings(text, n_strings, string_lengths, false);

	my_qsort(text, 0, n_strings - 1, compare_two_strings, string_lengths);

	fclose(outputfile);

	outputfile = fopen("txt/output/output_sorted.txt", "w");

	print_text(text, n_strings, outputfile);	

	print_string_lenghts(string_lengths, n_strings);

	printf("------------------\n");

	printf("sorted strings reversed: \n");

	//sort_strings(text, n_strings, string_lengths, true);


	fclose(outputfile);

	outputfile = fopen("txt/output/output_sorted_reversed.txt", "w");

	my_qsort(text, 0, n_strings - 1, compare_two_strings_reversed, string_lengths);

	print_text(text, n_strings, outputfile);	

	print_string_lenghts(string_lengths, n_strings);

	printf("-_-_-_-_-_-_-_-_-_-\n");	

	printf("returned back: \n");


	my_qsort(text, 0, n_strings - 1, compare_two_ptrs, string_lengths);

	fclose(outputfile);

	outputfile = fopen("txt/output/output_returned.txt", "w");

	print_text(text, n_strings, outputfile);

	print_string_lenghts(string_lengths, n_strings);

	fclose(outputfile);
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
        //printf("number is %zd\n", number);
        //printf("%zd", number);


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
