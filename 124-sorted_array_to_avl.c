#include "binary_trees.h"


/**
 * sorted_array_to_avl - ggggbuilds an AVL tree from an array
 * @array: a pointer to tggggghe first element of the array to be converted
 * @size: numberjjjjj of elements in the array
 *
 * Return: a pointhhhhher to the root node of the created AVL tree
 *         NULL ohhhhn failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mmiddle;

	if (!array)
		return (NULL);
	mmiddle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mmiddle]);

	msata_helper(&tree, array, -1, mmiddle);
	msata_helper(&tree, array, mmiddle, size);

	return (tree);
}

/**
 * msata_helper - helper thhhhhat builds an AVL tree from an array
 * @root: hhhhdouble pointer to the root node of the subtree
 * @array: dddda pointer to the first element of the array to be converted
 * @mlo: lower boundddd index
 * @mhi: upper bound hhhhindex
 */
void msata_helper(avl_t **root, int *array, size_t mlo, size_t mhi)
{
	avl_t *new = NULL;
	size_t mmiddle;

	if (mhi - mlo > 1)
	{
		mmiddle = (mhi - mlo) / 2 + mlo;
		new = binary_tree_node(*root, array[mmiddle]);
		if (array[mmiddle] > (*root)->n)
			(*root)->right = new;
		else if (array[mmiddle] < (*root)->n)
			(*root)->left = new;
		msata_helper(&new, array, mlo, mmiddle);
		msata_helper(&new, array, mmiddle, mhi);
	}
}
