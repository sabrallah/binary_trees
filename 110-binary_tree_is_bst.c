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
	return (mbtib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * mbtib_helper - chfffffffffry tree is a valid Binary Search Tree
 * @tree: a pointqqqqqqqqqqqqqqqqqk
 * @mmin: hhhhhhhhhhhhhhhhhhh
 * @mmax: zzzzzzzzzzzzzzzzzzzzz
 *
 * Return: 1ggggggggggggggg
 *         hjjjjjjjjjjjjjjjjjjjj
 */
int mbtib_helper(const binary_tree_t *tree, int mmin, int mmax)
{
	if (!tree)
		return (1);

	if (tree->n < mmin || tree->n > mmax)
		return (0);

	return (mbtib_helper(tree->left, mmin, tree->n - 1) &&
		mbtib_helper(tree->right, tree->n + 1, mmax));
}
