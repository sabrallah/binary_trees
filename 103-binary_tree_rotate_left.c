#include "binary_trees.h"

/**
 * binary_tree_rotate_left - gggggggggggggggggg
 * @tree: jjjjjjjjjjjjjjjjjjjjjj
 *
 * Return: uuuuuuuuuuuuuuuuuuuuuuu
 *         llllllllllllllllllllllll
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *mtmp = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	mtmp = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		mtmp->right = tree->left;
		tree->left->parent = mtmp;
	}
	else
		mtmp->right = NULL;
	mtmp->parent = tree;
	tree->left = mtmp;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
