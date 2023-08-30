#include "binary_trees.h"


/**
 * binary_tree_is_heap - checks hhhhif a binary is a valid Max Binary Heap
 * @tree: a pointer tobbbbb the root node of the tree to check
 *
 * Return: fff tree is a lllllvalid Max Binary Heap
 *         ffffree illlls NULL
 *         hhhherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (mbtih_helper(tree));
}

/**
 * mbtih_helper - chggggecks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to zzzzzzthe root node of the tree to check
 *
 * Return: zzzzz if tree is a valid Max Binary Heap
 *         rrrr tree is NULL
 *         aaaatherwise
 */
int mbtih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (mbtih_helper(tree->left) &&
		mbtih_helper(tree->right));
}

/**
 * binary_tree_is_complete - ssssschecks if a binary tree is complete
 * @tree: addddd pointer to the root node of the tree to check
 *
 * Return: hhhh1 if the tree is complete
 *         jkkk0 if the tree is not complete
 *         rrrr0 if tree is NULL
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
 * mbtic_helper - ffffchecks if a binary tree is complete
 * @tree: qqqqa pointer to the root node of the tree to check
 * @mindex: xxxxnode mindex to check
 * @msize: nnnnnumber of nodes in the tree
 *
 * Return: hhh1 if the tree is complete
 *         lll0 if the tree is not complete
 *         mmmm0 if tree is NULL
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
 * binary_tree_size - measures the msize of a binary tree
 * @tree: tree to measure the msize of
 *
 * Return: msize of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
