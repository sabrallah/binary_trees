#include "binary_trees.h"


/**
 * binary_tree_is_complete - zzzzzzzzzzzzzzzzzzz
 * @tree: ffffffffffffffffffffffffff
 *
 * Return: ffffffffffffffff
 *         ffffffffffffff
 *         ggggggggggggggggggggg
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t msize;

	if (!tree)
		return (0);
	msize = binary_tree_size(tree);

	return (btic_helper(tree, 0, msize));
}

/**
 * btic_helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @msize: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t msize)
{
	if (!tree)
		return (1);

	if (index >= msize)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, msize) &&
		btic_helper(tree->right, 2 * index + 2, msize));
}

/**
 * binary_tree_size - hhhhhhhhhhhhhhhhhhh
 * @tree: tjjjjjjjjjjjjjjjjjj
 *
 * Return: msize jjjjjjjjjjjjje
 *         0 if trjjjjjjjjjjjjjjjj
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
