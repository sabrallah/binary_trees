#include "binary_trees.h"

/**
 * bst_search - suuuuuuuuuuuuuuuuy Search Tree
 * @tree: fffffffffffffffffsearch
 * @value: thhhhhhhhhhhhhhtree
 * Return: fffffffffffffffffual to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *rnode = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (rnode)
	{
		if (value == rnode->n)
			return (rnode);
		if (value < rnode->n)
			rnode = rnode->left;
		else if (value > rnode->n)
			rnode = rnode->right;
	}

	return (NULL);
}
