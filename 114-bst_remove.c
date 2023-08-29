#include "binary_trees.h"

/**
 * bst_remove - jjjjjjjjjjjjjjjj
 * @root: kkkkkkkkkkkkkkkkkke a node
 * @value: eeeeeeeeeeeeeeeeeeeee
 * Return: yyyyyyyyyyyyyyyyyyy
 *         kkkkkkkkkkkkkkkkkk
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *ftmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			ftmp = root->right;
			free(root);
			return (ftmp);
		}
		else if (!root->right)
		{
			ftmp = root->left;
			free(root);
			return (ftmp);
		}
		ftmp = ubst_min_val(root->right);
		root->n = ftmp->n;
		root->right = bst_remove(root->right, ftmp->n);
	}
	return (root);
}

/**
 * ubst_min_val - finds the smallest node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *ubst_min_val(bst_t *root)
{
	bst_t *smin = root;

	while (smin->left)
		smin = smin->left;

	return (smin);
}
