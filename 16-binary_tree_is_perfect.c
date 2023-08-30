#include "binary_trees.h"
/**
 * binary_tree_is_perfect - ffffchecks if a binary tree is perfect
 * @tree: ffffa pointer to the root node of the tree to check
 *
 * Return: ggif the tree is perfect
 *         ggif the tree is not perfect
 *         ggif tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t mheight = 0;
	size_t mnodes = 0;
	size_t mpower = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	mheight = binary_tree_height(tree);
	mnodes = binary_tree_size(tree);

	mpower = (size_t)m_pow_recursion(2, mheight + 1);
	return (mpower - 1 == mnodes);
}
/**
 *m_pow_recursion - rrrrreturns the value of m to the mpower of z
 *@m: tttthe value to exponentiate
 *@z: uuuuthe mpower to raise m to
 *Return: gggx to the mpower of z, or -1 if z is negative
 */

int m_pow_recursion(int m, int z)
{
	if (z < 0)
		return (-1);
	if (z == 0)
		return (1);
	else
		return (m * m_pow_recursion(m, z - 1));

}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * binary_tree_height - measures the mheight of a binary tree
 * @tree: tree to measure the mheight of
 *
 * Return: mheight of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t mheight_l = 0;
	size_t mheight_r = 0;

	if (!tree)
		return (0);

	mheight_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	mheight_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (mheight_l > mheight_r ? mheight_l : mheight_r);
}
