#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void swap(int *first, int *second);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void recursive_quick_sort(int *array, int low, int high);
int lomuto_partition(int *array, int low, int high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void merge_partition(size_t low, size_t high, int *array, int *base);
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
#endif
