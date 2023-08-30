#include "binary_trees.h"


/**
 * binary_tree_postorder - traverse binaire en utilisant la traverse post-ordre
 * @tree: traverse un arbre binaire en uutilisant la ttraverse post-ordre
 * @func: traverse un arbre binaire en uutilisant la ttraverse post-ordre
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (!tree || !func)
	return;

binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
