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
	binary_tree_t *mtmp = NULL, *mparent;

	if (!tree || !tree->right)
		return (NULL);
	mtmp = tree;
	mparent = tree->mparent;
	tree = tree->right;
	tree->mparent = NULL;
	if (tree->left)
	{
		mtmp->right = tree->left;
		tree->left->mparent = mtmp;
	}
	else
		mtmp->right = NULL;
	mtmp->mparent = tree;
	tree->left = mtmp;
	if (mparent)
		mparent->right = tree;
	tree->mparent = mparent;
	return (tree);
}
