#include <stdio.h>
#include <malloc.h>

#include "my_quick_sort.h"

void print_arr(const int* const arr,  const size_t arr_len)
{
	for (size_t int_number = 0; int_number < arr_len; int_number++)
	{
		printf("%d ", arr[int_number]);
	}

	putchar('\n');
}

void scan_arr(int* const arr, const size_t arr_len, FILE* inputfile)
{
	for (size_t int_number = 0; int_number < arr_len; int_number++)
	{
		fscanf(inputfile, "%d", &arr[int_number]);
	}	
}

void read_test(int* const arr, int* const right_arr, const size_t arr_len, FILE* inputfile)
{
	scan_arr(arr, arr_len, inputfile);
	scan_arr(right_arr, arr_len, inputfile);


}


bool is_equal(int* arr1, int* arr2, size_t arr_len)
{
	for (size_t int_number = 0; int_number < arr_len; int_number++)
	{
		if (arr1[int_number] != arr2[int_number])
		{
			return false;
		}
	}

	return true;
}




int main()
{
	FILE* inputfile = fopen("test_sort.txt", "r");

	size_t n_tests = 0;

	fscanf(inputfile, "%zu", &n_tests);

	printf("number of tests is %zu\n", n_tests);

	size_t arr_len = 0;

	for (size_t n_test = 0; n_test < n_tests; n_test++)
	{
		arr_len = 0;

		fscanf(inputfile, "%zu", &arr_len);

		int* arr = (int*) calloc(arr_len, sizeof(int));
		int* right_arr = (int*) calloc(arr_len, sizeof(int));

		printf("test %zu: array len is %zu\n", n_test, arr_len);
		read_test(arr, right_arr, arr_len, inputfile);

		qs(arr, 0, arr_len - 1);

		if (is_equal(arr, right_arr, arr_len))
		{
			printf("test %zu: OK\n", n_test);
		}
		else
		{
			printf("test %zu: Failed\n", n_test);

			print_arr(arr, arr_len);
			print_arr(right_arr, arr_len);
		}


		free(arr);
		free(right_arr);

	}
}