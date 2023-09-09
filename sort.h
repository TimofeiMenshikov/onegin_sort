#ifndef SORT_H
#define SORT_H

void sort_strings(char** const text, size_t n_strings, size_t* string_lengths);
void swap_strings(char** const pos_1_ptr, char** const pos_2_ptr);
void swap_str_lens(size_t* len_1_ptr, size_t* len_2_ptr);

void sort_ptrs(char** const text, size_t n_strings, size_t* string_lengths);

#endif /* SORT_H */