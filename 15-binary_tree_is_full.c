#include "binary_trees.h"


/**
 * binary_tree_is_full - if a binary tree is full
 * @tree: the root node of the tree to check
 *
 * Return: the tree is full
 *         the tree is not full
 *         tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
