#ifndef MY_QUICK_SORT_H
#define MY_QUICK_SORT_H


void swap_numbers(int* num_1, int* num_2);
void arr_int_ncpy(int* const dest, const int* const src, size_t n);
void print_state(const int* const  arr, const size_t size, const size_t left, const size_t right, const size_t sep_postition);
int* my_quick_sort(int*  arr, const size_t size);

#endif /* MY_QUICK_SORT_H */