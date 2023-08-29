#include "binary_trees.h"

/**
 * binary_tree_is_avl - hhhhhhhhhhhhhhh
 * @tree: ttttttttttttttttttttt
 *
 * Return: oooooooooooooooo
 *         llllllllllllllllll
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - ggggggggggggggggggg
 * @tree: jjjjjjjjjjjjjjjjjjjjjjj
 * @min: hhhhhhhhhhhhhh
 * @max: rrrrrrrrrrrrrrrrrrrrr
 *
 * Return: yyyyyyyyyyyyyyyyyy
 *         iiiiiiiiiiiiiiiiiii
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_lef, path_rig;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_lef - path_rig) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

/**
 * binary_tree_height - hhhhhhhhhhhhhhhhhe
 * @tree: tddddddddddddddddd
 *
 * Return: zzzzzzzzzzzzzzz
 *         bbbbbbbbbbbbbbbbb
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_rig = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_rig ? height_left : height_rig);
}
