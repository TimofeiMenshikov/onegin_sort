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

void print_state(const int* const  arr, const size_t size, const size_t left, const size_t right, const size_t sep_postition)
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

		if (number == sep_postition)
		{
			putchar('[');
		}
		else
		{
			putchar(' ');
		}

		printf("%d", arr[number]);

		if (number == sep_postition)
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


int* my_quick_sort(int*  arr, const size_t size)
{
	if (size <= 1)
	{
		return arr;
	}

	//printf("size %zu \n", size);
	putchar('\n');

	size_t left = 0;
	size_t right = size - 1;

	size_t sep_postition = size / 2;

	ssize_t left_sort_pos = -1;

	ssize_t right_sort_pos = -1;

	while (left < right)
	{
		print_state(arr, size, left, right, sep_postition);

		printf("sep_postition: %zu\n", sep_postition);

		size_t is_jump_left = 0;

		size_t is_jump_right = 0;

		if (arr[left] >= arr[sep_postition])
		{
			left_sort_pos = left;
			is_jump_left = 0;
		}
		else
		{
			is_jump_left = 1;
		}


		if (arr[right] <= arr[sep_postition])
		{
			right_sort_pos = right;
			is_jump_right = 0;
		}
		else
		{
			is_jump_right = 1;
		}

		if ((right_sort_pos != -1) && (left_sort_pos != -1))
		{
			swap_numbers(arr + left_sort_pos, arr + right_sort_pos);

			if (sep_postition == left_sort_pos)
			{
				sep_postition = right_sort_pos;

				//printf("sep_postition is changed \n");
			}
			else if (sep_postition == right_sort_pos)
			{
				sep_postition = left_sort_pos;

				//printf("sep_postition is changed \n");			
			}

			right_sort_pos = -1;
			left_sort_pos = -1;

			is_jump_left = 0;
			is_jump_right = 0;

		}

		left += is_jump_left;
		right -= is_jump_right;
	
	}

	char* src = my_quick_sort(arr, sep_postition);

	arr_int_ncpy(arr, src, sep_postition);

	src = my_quick_sort(arr + sep_postition + 1, size - sep_postition - 1);

	arr_int_ncpy(arr + sep_postition + 1, src, size - sep_postition - 1);

	return arr;
}


int main()
{
	int arr[] = {1, 8, 3, 5, 6, 7};
	const size_t size = 6;

	//int arr[] = {5, 2, 15, 3, 1, 16, 10, 5, 10, 13, 4, 12, 6, 6, 22, 20};
	//const size_t size = 16;

	//int arr[] = {5, 2, 15, 3, 1, 16, 10, 5, 10, 3, 4, 12, 6, 6, 22, 20};
	//const size_t size = 16;

	//int arr[] = {9, 8, 7, 1, 5, 4, 3};
	//const size_t size = 7;

	my_quick_sort(arr, size);
}