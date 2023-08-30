#include "binary_trees.h"


/**
 * binary_tree_is_root - verifie si un nœud est une racine
 * @node: verifie si un nœud est une racine
 *
 * Return: 1 node is a root
 *         0 not a root
 *         0 node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
		return ((!node || node->parent) ? 0 : 1);
}
