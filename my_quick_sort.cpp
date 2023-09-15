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


/*int* my_quick_sort(int*  arr, const ssize_t size)
{
	if (size <= 1)
	{
		return arr;
	}

	//printf("size %zu \n", size);
	putchar('\n');

	ssize_t left = 0;
	ssize_t right = size - 1;

	ssize_t sep_position = size / 2;

	ssize_t left_sort_pos = -1;

	ssize_t right_sort_pos = -1;

	while (left < right)
	{
		print_state(arr, size, left, right, sep_position);

		printf("left %zu\n", left);
		printf("right %zu\n", right);

		//printf("sep_position: %zu\n", sep_position);

		/* size_t is_jump_left = 0;

		size_t is_jump_right = 0;

		if (arr[left] >= arr[sep_position])
		{
			left_sort_pos = left;
			is_jump_left = 0;
		}
		else
		{
			is_jump_left = 1;
		}


		if (arr[right] <= arr[sep_position])
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

			sep_position = change_sep_position(sep_position, left_sort_pos, right_sort_pos);


			// последующие if нужны для того, чтобы не было бесконечных замен разделяющего элемента и элемента, равного ему
			if (arr[right_sort_pos] == arr[sep_position] && arr[left_sort_pos] == arr[sep_position])
			{
				is_jump_left = 1;
				is_jump_right = 0; // если сделать переход одновременно и вправо и влево, то элемент, равный разделяющему будет проигнорирован


				sep_position = change_sep_position(sep_position, left_sort_pos, right_sort_pos);
				printf("reverse swap is done\n");
			}
			else
			{
				is_jump_left = 0;
				is_jump_right = 0;
			}



			right_sort_pos = -1;
			left_sort_pos = -1;
		}

		left += is_jump_left;
		right -= is_jump_right; 

		while (arr[left] < arr[sep_position])
		{
			left++;

			print_state(arr, size, left, right, sep_position);
		}

		while (arr[right] > arr[sep_position])
		{
			right--;
			printf("right");

			print_state(arr, size, left, right, sep_position);
		}

		if (right >= left)
		{
			swap_numbers(arr + left, arr + right);
			left++;
			right++;
		} while(left <= right);
	
	}

	int* src = my_quick_sort(arr, sep_position);

	arr_int_ncpy(arr, src, sep_position);

	src = my_quick_sort(arr + sep_position + 1, size - sep_position - 1);

	arr_int_ncpy(arr + sep_position + 1, src, size - sep_position - 1);

	return arr;
}*/

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