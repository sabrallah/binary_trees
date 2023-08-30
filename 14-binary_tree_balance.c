#include "binary_trees.h"
/**
 * binary_tree_balance - factor of a binary tree
 * @tree: the root node of the tree to measure the balance factor
 *
 * Return: the factor
 *         0 tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_lef, height_rig;

	if (!tree)
		return (0);

	height_lef = tree->left ? (int)binary_tree_height(tree->left) : -1;
	height_rig = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (height_lef - height_rig);
}
/**
 * binary_tree_height - height of a binary tree
 * @tree: measure the height of
 *
 * Return: of the tree
 *         0 tree is NULL
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
