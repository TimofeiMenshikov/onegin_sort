#include <stdio.h>
#include "sort.h"
#include "string_compare.h"


void print_state( char** arr, const ssize_t size, const ssize_t left, const ssize_t right)
{
    for (size_t number = 0; number < size; number++)
    {
        //printf("number is %zd\n", number);
        printf("%zd", number);


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


void sort_strings(char** const text, size_t n_strings, ssize_t* string_lengths, bool reverse)
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



void my_qsort(char **arr, const ssize_t first, const ssize_t last)
{
    if (first < last)
    {
        ssize_t left = first;
        ssize_t right = last;
        char* middle = arr[(first + last) / 2];

        do
        {
            while (compare_two_strings(arr[left], middle) == FIRST_IS_LEFT)
            {

            	left++;		
            } 

            while (compare_two_strings(arr[right], middle) == FIRST_IS_RIGHT)
            {
            	right--;
            }
            
            if (left <= right)
            {
            	swap_strings(arr + right, arr + left);

                left++;
                right--;
            }

        } while (left <= right);

        my_qsort(arr, first, right);
        my_qsort(arr, left, last);
    }

    return;
}



void my_qsort_reversed(char** arr, const ssize_t first, const ssize_t last, ssize_t* string_lengths)
{
    if (first < last)
    {
        ssize_t left = first;
        ssize_t right = last;
        char* middle = arr[(first + last) / 2];
        ssize_t middle_len = string_lengths[(first + last) / 2];
        printf("first is %zd last is %zd\n", first, last);

        do
        {
            while (compare_two_strings_reversed(arr[left], middle, string_lengths[left], middle_len) == FIRST_IS_RIGHT)
            {
                print_state(arr, last - first + 1, left, right);
                //printf("left : %zd  right : %zd \n", left, right);
                left++;     
                
                if (left > last)
                {
                    break;
                }
            } 

            //printf("before while 2\n");
            //printf("left : %zd  right : %zd \n", left, right);
            while (compare_two_strings_reversed(middle, arr[right], middle_len, string_lengths[right]) == FIRST_IS_RIGHT)
            {
                print_state(arr, last - first + 1, left, right);
                right--;
                if (right < first)
                {
                    break;
                }
            }
            
            if (left <= right)
            {
                swap_strings(arr + right, arr + left);
                //print_state(arr, last - first + 1, left, right);
                left++;
                right--;
            }

        } while (left <= right);

        my_qsort(arr, first, right);
        my_qsort(arr, left, last);
    }

    return;
}



// сортировка по символам с конца храним значения длин строк и при перестановке строк переставляем и их

void sort_ptrs(char** const text, size_t n_strings, ssize_t* string_lengths)
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


void swap_str_lens(ssize_t* len_1_ptr, ssize_t* len_2_ptr)
{
	size_t temp = *len_1_ptr;
	*len_1_ptr = *len_2_ptr;
	*len_2_ptr = temp;
}