#include "binary_trees.h"

/**
 * binary_tree_is_bst - chhhhhhhhhhha valid Binary Search Tree
 * @tree: a pointer to thhhhhhhhhhhhhhhto check
 *
 * Return: jjjjjjjjjj
 *         ddddddddddddddd
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - chfffffffffry tree is a valid Binary Search Tree
 * @tree: a pointqqqqqqqqqqqqqqqqqk
 * @min: hhhhhhhhhhhhhhhhhhh
 * @max: zzzzzzzzzzzzzzzzzzzzz
 *
 * Return: 1ggggggggggggggg
 *         hjjjjjjjjjjjjjjjjjjjj
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
