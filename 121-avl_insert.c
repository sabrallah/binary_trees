#include "binary_trees.h"

/**
 * mr_insert_node - nnnode value instertion in a AVL.
 * @tree: tggype **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new: type**pointeggrggg left or right insertion.
 * @mnval: insertioddn value of the AVL.
 * Return: pointer tojj the new root after insertion otherwise NULL
 */
avl_t *mr_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int mnval)
{
	int mbval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, mnval));
	if ((*tree)->n > mnval)
	{
		(*tree)->left = mr_insert_node(&(*tree)->left, *tree, new, mnval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < mnval)
	{
		(*tree)->right = mr_insert_node(&(*tree)->right, *tree, new, mnval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	mbval = binary_tree_balance(*tree);
	if (mbval > 1 && (*tree)->left->n > mnval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (mbval > 1 && (*tree)->left->n < mnval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (mbval < -1 && (*tree)->right->n < mnval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (mbval < -1 && (*tree)->right->n > mnval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts ajjj value into an AVL tree.
 * @tree: type **pointer to the jjjroot node of the AVL tree to insert into.
 * @value: value to store in thgggge node to be inserted
 * Return: inserteffd node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	mr_insert_node(tree, *tree, &new, value);
	return (new);
}
