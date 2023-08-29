#include "binary_trees.h"

/**
 * binary_tree_is_perfect - aaaaaaaaaaaaaaaa
 * @tree: aaaaaaaaaaaaaa
 *
 * Return: 1 taaaaaaaaaaaaaaa
 *         0 aaaaaaaaaaaaaaaaaa
 *         0 aaaaaaaaaaaaaaaaaa
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t heights = 0;
	size_t nodess = 0;
	size_t powers = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	heights = binary_tree_height(tree);
	nodess = binary_tree_size(tree);

	powers = (size_t)_pow_recursion(2, heights + 1);
	return (powers - 1 == nodess);
}

/**
 *_pow_recursion - aaaaaaaaaaaaaaaaaaa
 *@x: aaaaaaaaaaaaa
 *@y: aaaaaaaaaaaaaa
 *Return: aaaaaaaaaaaaaaaaaa
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - aaaaaaaaaaaaaaa
 * @tree: aaaaaaaaaaaaaaaaaa
 *
 * Return: aaaaaaaaaaaaaaaaaa
 *         0 aaaaaaaaaaaaaaaa
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - aaaaaaaaaaaaaaaaaaa
 * @tree: aaaaaaaaaaaaaaaaaaaaa
 *
 * Return: aaaaaaaaaaaaaaaa
 *         0  aaaaaaaaaaaaaa
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
