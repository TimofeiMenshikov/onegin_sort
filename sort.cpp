#include <stdio.h>
#include "include/sort.h"
#include "include/string_compare.h"
#include "include/string_compare.h"
#include "include/print.h"
#include "include/printf_debug.h"




void my_qsort(char **arr, const ssize_t first, const ssize_t last, enum comp_two_str (*comparator)(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2), ssize_t* string_lengths)
{
    if (first < last)
    {
        ssize_t left = first;
        ssize_t right = last;
        char* middle = arr[(first + last) / 2];
        ssize_t middle_len = string_lengths[(first + last) / 2];
        SORT_DUMP(print_state(arr, last - first + 1, left, right));

        SORT_DUMP(printf("middle is <%s>\n", middle));

        do
        {
            while (comparator(arr[left], middle, string_lengths[left], middle_len) == FIRST_IS_LEFT)
            {
            	left++;	
                SORT_DUMP(print_state(arr, last - first + 1, left, right));	
            }


            while (comparator(arr[right], middle, string_lengths[right], middle_len) == FIRST_IS_RIGHT)
            {
            	right--;
                SORT_DUMP(print_state(arr, last - first + 1, left, right));
            }

            
            if (left <= right)
            {
            	swap_strings(arr + right, arr + left);
                swap_str_lens(string_lengths + left, string_lengths + right);

                left++;
                right--;

                SORT_DUMP( print_state(arr, last - first + 1, left, right));
            }


        } while (left <= right);

        my_qsort(arr, first, right, comparator, string_lengths);
        my_qsort(arr, left, last, comparator, string_lengths);
    }

    return;
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