#include <stdio.h>
#include "sort.h"
#include "string_compare.h"


void sort_strings(char** const text, size_t n_strings)
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


void sort_ptrs(char** const text, size_t n_strings)
{
	for (size_t i = 0; i < n_strings; i++)
	{
		for (size_t j = i + 1; j < n_strings; j++)
		{
			if (text[i] > text[j])
			{
				swap_strings(text + i, text + j);
			}
		}
	}
}


void swap_strings(char** const pos_1_ptr, char** const pos_2_ptr)
{
	char* temp = *pos_1_ptr;
	*pos_1_ptr = *pos_2_ptr;
	*pos_2_ptr = temp; 
}