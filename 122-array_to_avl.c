#include "binary_trees.h"


/**
 * array_to_avl - builds ahhhhhn AVL tree from an array
 * @array: hhhharray to create from
 * @size: ttttsize of the array
 *
 * Return: a pointer gggggggto the mroot node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int y;
	avl_t *mroot = NULL;

	for (y = 0; y < size; y++)
		avl_insert(&mroot, array[y]);

	return (mroot);
}
