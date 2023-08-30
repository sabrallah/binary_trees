#include "binary_trees.h"

/**
 * bst_insert - iggggggearch Tree
 * @tree: a double poingggggggge of the BST to insert the value
 * @value: the value to storuuuuuuuuuue to be inserted
 * Return: A poinuuuuuuated node
 *         NULL onuuuuuuuuuu failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *mtmp = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (mtmp)
	{
		second = mtmp;
		if (value < mtmp->n)
			mtmp = mtmp->left;
		else if (value > mtmp->n)
			mtmp = mtmp->right;
		else if (value == mtmp->n)
			return (NULL);
	}

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

/**
 * avl_insert - inserts a vhhhhhhalue in an AVL Tree
 * @tree: a double pointer tkkkkkkko the root node of the AVL tree
 * @value: value tokkkkkkkk insert
 *
 * Return: a pointer llllllllllto the created node
 *         NULL onlllllll failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int mbalance = 0;
	avl_t *node = bst_insert(tree, value);

	mbalance = binary_tree_balance(*tree);

	if (mbalance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (mbalance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (mbalance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (mbalance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}
