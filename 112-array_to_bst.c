#include "binary_trees.h"

/**
 * array_to_bst - fffffffffffffff an array
 * @array: pfffffffffffff array to be converted
 * @size: hhhhhhhhhhhhhhhhhhh
 * Return: jjjjjjjjjjjjjjjjjjjted BST
 *         rrrrrrrrrrrrrrrrrrre
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int s;
	bst_t *sroot = NULL;

	for (s = 0; s < size; s++)
		bst_insert(&sroot, array[s]);

	return (sroot);
}
