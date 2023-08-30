#include "binary_trees.h"


/**
 * binary_tree_preorder - parcourt un arbre binaire le parcours de pre-commande
 * @tree: parcourt un arbre binaire en utilisant le parcours de precommande
 * @func: parcourt un arbre binaire en utilisant le parcours de precommande
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
			if (!tree || !func)
				return;

			func(tree->n);
			binary_tree_preorder(tree->left, func);
			binary_tree_preorder(tree->right, func);
}
