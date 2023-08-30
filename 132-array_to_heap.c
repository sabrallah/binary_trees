#include "binary_trees.h"

/**
 * array_to_heap - gggggbuilds a Max Binary Heap tree from an array
 * @array: hhhha pointer to the first element of the array to be converted
 * @size: eeeeeethe number of element in the array
 *
 * Return: aaaaaa pointer to the mroot node of the created Binary Heap
 *         jjjjNULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int y;
	heap_t *mroot = NULL;

	for (y = 0; y < size; y++)
		heap_insert(&mroot, array[y]);

	return (mroot);
}
