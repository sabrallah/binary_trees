#include "binary_trees.h"

/**
 * mcheck_balance - checyyyks the mbalance of each node
 *
 * @node: pointer touuu the node
 * @mvalue: input miivalue
 * Return: no reeeturn
 */
void mcheck_balance(avl_t **node, int mvalue)
{
	int mbalance;

	mbalance = binary_tree_balance(*node);

	if (mbalance > 1 && mvalue < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (mbalance < -1 && mvalue > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (mbalance > 1 && mvalue > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (mbalance < -1 && mvalue < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * mavl_in - checks ttif node is inserted
 *
 * @tree: tree roeeot
 * @mvalue: node eemvalue
 * Return: pointer eeeto the new node
 */
avl_t *mavl_in(avl_t **tree, int mvalue)
{
	avl_t *node;

	if (mvalue < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, mvalue);
			return ((*tree)->left);
		}
		else
		{
			node = mavl_in(&((*tree)->left), mvalue);
			if (node)
				mcheck_balance(tree, mvalue);
			return (node);
		}
	}

	if (mvalue > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, mvalue);
			return ((*tree)->right);
		}
		else
		{
			node = mavl_in(&((*tree)->right), mvalue);
			if (node)
				mcheck_balance(tree, mvalue);
			return (node);
		}
	}

	return (NULL);
}

/**
 * avl_insert - insertsggg a mvalue in a AVL Tree
 *
 * @tree: tree roggggot
 * @value: node mggvalue
 * Return: pointer toggg the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = mavl_in(tree, value);

	return (node);
}
