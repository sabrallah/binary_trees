#include "binary_trees.h"

/**
 * bst_insert - ingggggggggggggggg Tree
 * @tree: a double poggggggggggggggST to insert the value
 * @value: thehhhhhhhhhhhhhhhhhhhhinserted
 * Return: A pkkkkkkkkkkkkkkk
 *         eeeeeeeeeeeeeeeeeeee
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *stmp = NULL;
	bst_t *second = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	stmp = *tree;
	while (stmp)
	{
		second = stmp;
		if (value < stmp->n)
			stmp = stmp->left;
		else if (value > stmp->n)
			stmp = stmp->right;
		else if (value == stmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}
