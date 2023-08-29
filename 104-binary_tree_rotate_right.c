#include "binary_trees.h"

/**
 * binary_tree_rotate_right - gggggggggggginary tree
 * @tree: a pogggggggggggggggggghe tree to check
 *
 * Return: Pointer to the new rhhhhhhhhhhhhhhhhrotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *stmp = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);
	stmp = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		stmp->left = tree->right;
		tree->right->parent = stmp;
	}
	else
		stmp->left = NULL;
	stmp->parent = tree;
	tree->right = stmp;
	if (parent)
		parent->left = tree;
	tree->parent = parent;
	return (tree);
}
