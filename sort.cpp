#include <stdio.h>
#include "sort.h"
#include "string_compare.h"


void sort_strings(char** const text, size_t n_strings, size_t* string_lengths, bool reverse)
{
	for (size_t i = 0; i < n_strings; i++)
	{
		for (size_t j = i + 1; j < n_strings; j++)
		{
			if (reverse == true)
			{
				if (compare_two_strings_reversed(text[i], text[j], string_lengths[i], string_lengths[j]) == FIRST_IS_RIGHT)
				{
					swap_strings(text + i, text + j);
					swap_str_lens(string_lengths + i, string_lengths + j);
				}
			}
			else
			{
				if (compare_two_strings(text[i], text[j]) == FIRST_IS_RIGHT)
				{
					swap_strings(text + i, text + j);
					swap_str_lens(string_lengths + i, string_lengths + j);
				}
			}
		}
	}
}

// сортировка по символам с конца храним значения длин строк и при перестановке строк переставляем и их

void sort_ptrs(char** const text, size_t n_strings, size_t* string_lengths)
{
	for (size_t i = 0; i < n_strings; i++)
	{
		for (size_t j = i + 1; j < n_strings; j++)
		{
			if (text[i] > text[j])
			{
				swap_strings(text + i, text + j);
				swap_str_lens(string_lengths + i, string_lengths + j);
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


void swap_str_lens(size_t* len_1_ptr, size_t* len_2_ptr)
{
	size_t temp = *len_1_ptr;
	*len_1_ptr = *len_2_ptr;
	*len_2_ptr = temp;
}