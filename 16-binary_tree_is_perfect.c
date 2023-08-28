#include "binary_trees.h"


/**
 * binary_tree_is_perfect - ggggggggggg
 * @tree: zzzzzzzzzzzzzz
 *
 * Return: 1 jjjjjjjjj
 *         0 ihhhhhhhh
 *         0 kkkkkkkkkkkkk
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
 *m_pow_recursion - rtttttttttttt
 *@s: thhhhhhhhhhhh
 *@u: thhhhhhhhhhhhh
 *Return: jjjjjjjjjjjjj
 */

int m_pow_recursion(int s, int u)
{
	if (u < 0)
		return (-1);
	if (u == 0)
		return (1);
	else
		return (s * m_pow_recursion(s, u - 1));

}

/**
 * binary_tree_size - ooooooooooooooo
 * @tree: kkkkkkkkkkkkkkkk
 *
 * Return: shhhhhhhhhhh
 *         0 uuuuuuuuuuuuu
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - moooooooooooooooo
 * @tree: tnnnnnnnnnnnnnnnn
 *
 * Return: mhkkkkkkkkkkkkkkkkkk
 *         0 vvvvvvvvvvvvvvv
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lef = 0;
	size_t height_rig = 0;

	if (!tree)
		return (0);

	height_lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lef > height_rig ? height_lef : height_rig);
}
