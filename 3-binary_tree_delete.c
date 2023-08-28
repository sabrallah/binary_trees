#include "binary_trees.h"


/**
 * binary_tree_delete - supprime un arbre avec binaire entier
 * @tree: supprime un arbre binaire avec entier
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
