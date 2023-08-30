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

	return (mbtic_helper(tree, 0, msize));
}

/**
 * mbtic_helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @mindex: node index to check
 * @msize: number of nodes in the tree
 *
 * Return: if the tree is complete
 *         if the tree is not complete
 *         if tree is NULL
 */
int mbtic_helper(const binary_tree_t *tree, size_t mindex, size_t msize)
{
	if (!tree)
		return (1);

	if (mindex >= msize)
		return (0);

	return (mbtic_helper(tree->left, 2 * mindex + 1, msize) &&
		mbtic_helper(tree->right, 2 * mindex + 2, msize));
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
