#include <stdio.h>
#include <string.h>


void swap_numbers(int* num_1, int* num_2)
{
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}


void arr_int_ncpy(int* const dest, const int* const src, size_t n)
{
	for (size_t int_number = 0; int_number < n; int_number++)
	{
		dest[int_number] = src[int_number];
	}
}


size_t change_sep_position(size_t sep_position, const size_t left_sort_pos, const size_t right_sort_pos)
{			
	if (sep_position == left_sort_pos)
	{
		sep_position = right_sort_pos;

		//printf("sep_position is changed \n");
	}
	else if (sep_position == right_sort_pos)
	{
		sep_position = left_sort_pos;

		//printf("sep_position is changed \n");			
	}

	return sep_position;

}


void print_state(const int* const  arr, const size_t size, const size_t left, const size_t right, const size_t sep_position)
{
	for (size_t number = 0; number < size; number++)
	{
		if (number == left)
		{
			putchar('<');
		}
		else
		{
			putchar(' ');
		}

		if (number == sep_position)
		{
			putchar('[');
		}
		else
		{
			putchar(' ');
		}

		printf("%d", arr[number]);

		if (number == sep_position)
		{
			putchar(']');
		}
		else
		{
			putchar(' ');
		}

		if (number == right)
		{
			putchar('>');
		}
		else
		{
			putchar(' ');
		}

	}
	putchar('\n');
}


void my_qsort(int *arr, ssize_t first, ssize_t last)
{
    if (first < last)
    {
        ssize_t left = first;
        ssize_t right = last;
        ssize_t middle = arr[(first + last) / 2];

        do
        {
            while (arr[left] < middle)
            {
            	//print_state(arr, last + 1, left, right, middle);
            	left++;		
            } 

            while (arr[right] > middle)
            {
            	//print_state(arr, last + 1, left, right, middle);
            	right--;
            }
            
            if (left <= right)
            {
            	swap_numbers(arr + right, arr + left);

                left++;
                right--;
            }

        } while (left <= right);

        my_qsort(arr, first, right);
        my_qsort(arr, left, last);
    }
}


int main()
{
	//int arr[] = {1, 8, 3, 5, 6, 7};
	//const size_t size = 6;

	//int arr[] = {5, 2, 15, 3, 1, 16, 10, 5, 10, 13, 4, 12, 6, 6, 22, 20};
	//const size_t size = 16;

	//int arr[] = {5, 2, 15, 3, 1, 16, 10, 5, 10, 3, 4, 12, 6, 6, 22, 20};
	//const size_t size = 16;

	//int arr[] = {9, 8, 7, 1, 5, 4, 3};
	//const size_t size = 7;

	//int arr[] = {1, 5};
	//const size_t size = 2;

	//int arr[] = {2, 1, 1, 1, 1, 1, 1, 1};
	//const size_t size = 8;

	//int arr[] = {5, 6, 7, 5, 8, 1, 3, 4, 5, 4, 9, 8, 5, 9, 6, 1, 4, 5, 4, 9, 5, 7, 8, 7, 6, 4, 1, 3};
	//const size_t size = 28;

	int arr[] = {4, 3, 1, 4, 4, 1, 3};
	const size_t size = 7;


	my_qsort(arr, 0, size - 1);

	for (size_t int_number = 0; int_number < size; int_number++)
	{
		printf("%d ", arr[int_number]);
	}
}