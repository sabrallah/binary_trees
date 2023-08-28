#include "binary_trees.h"


/**
 * binary_tree_inorder - parcourt arbre binaire utilisant parcours dans ordre
 * @tree: parcourt un arbre binaire en utilisant un parcours dans l'ordre
 * @func: parcourt un arbre binaire en utilisant un parcours dans l'ordre
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
