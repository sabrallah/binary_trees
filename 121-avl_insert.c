#include "binary_trees.h"

/**
* mARGL - Itfff's todo.
* @tree: Igggt's todo.
* @value: It'shhh todo.
*/
void mARGL(avl_t **tree, int value)
{
	int m;

	m = binary_tree_balance(*tree);
	if (m > 1)
	{
		if (value < (*tree)->left->n)
		{
			*tree = binary_tree_rotate_right(*tree);
			return;
		}
		if (value > (*tree)->left->n)
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
			return;
		}
	}
	if (m < -1)
	{
		if (value > (*tree)->right->n)
		{
			*tree = binary_tree_rotate_left(*tree);
			return;
		}
		if (value < (*tree)->right->n)
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
			return;
		}
	}
}

/**
* mavlAux - It's ihhnserts a value in an AVL Tree.
* @tree: It's pointer tojjj root of the AVL tree for inserting the value.
* @value: It's value llllto store in node to be inserted.
* Return: It's pointerrrrr to the created node, or NULL on failure.
*/
avl_t *mavlAux(avl_t **tree, int value)
{
	avl_t *mndo;

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			mndo = mavlAux(&((*tree))->left, value);
			if (mndo)
				mARGL(tree, value);
			return (mndo);
		}
	}
	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			mndo = mavlAux(&((*tree))->right, value);
			if (mndo)
			{
				mARGL(tree, value);
				return (mndo);
			}
		}
	}
	return (NULL);
}

/**
* avl_insert - It's infffserts a value in an AVL Tree.
* @tree: It's double fffpointer to root of the AVL tree for inserting the value.
* @value:  It's value to fffstore in the node to be inserted.
* Return: It's poiggggnter to the created node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	return (mavlAux(tree, value));
}
