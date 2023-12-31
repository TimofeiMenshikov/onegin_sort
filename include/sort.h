#ifndef SORT_H
#define SORT_H

#include "string_compare.h"

void sort_strings(char** const text, size_t n_strings, ssize_t* string_lengths, bool reverse);
void swap_strings(char** const pos_1_ptr, char** const pos_2_ptr);
void swap_str_lens(ssize_t* len_1_ptr, ssize_t* len_2_ptr);

void sort_ptrs(char** const text, size_t n_strings, ssize_t* string_lengths);
void qsort_ptrs(char** const text, ssize_t first, ssize_t last, ssize_t* string_lengths);


void my_qsort(char **arr, const ssize_t first, const ssize_t last, enum comp_two_str (*comparator)(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2), ssize_t* string_lengths);
void my_qsort_reversed(char **arr, const ssize_t first, const ssize_t last, ssize_t* string_lengths);

#endif /* SORT_H */