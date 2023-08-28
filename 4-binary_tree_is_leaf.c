#include "binary_trees.h"


/**
 * binary_tree_is_leaf - verifie si un nœud est une feuille
 * @node: verifie si un nœud est une feuille
 *
 * Return: 1 vérifie si un nœud est une feuille
 *         0 vérifie si un nœud est une feuille
 *         0 vérifie si un nœud est une feuille
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
