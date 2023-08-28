#include "binary_trees.h"


/**
 * binary_tree_uncle - hhhhhhhhhhhhhhhh
 * @node: jjjjjjjjjjjjjjjjjj
 *
 * Return: dddddddddddddddddddd
 *         ssssssssssssssssssssss
 *         zzzzzzzzzzzzzzzzzzzzzz
 *         fffffffffffffffffffffff
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - fffffffffffffffffff
 * @node: fffffffffffffffffffffffffffff
 *
 * Return: xxxxxxxxxxxxxxxxxxxxxx
 *         cccccccccccccccccccccccc
 *         qqqqqqqqqqqqqqqqqqqqqqq
 *         wwwwwwwwwwwwwwwwwwwwwww
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
