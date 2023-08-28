#include "binary_trees.h"


/**
 * binary_tree_insert_left - inserer un node a gauche de autre node
 * @parent: valeur à stocker dans le nouveau nœudvaleur
 * @value: valeur à stocker dans le nouveau nœud
 *
 * Return: valeur à stocker dans le nouveau nœud
 *         valeur à stocker dans le nouveau nœud
 *         valeur à stocker dans le nouveau nœud
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;
	if (new->left)
		new->left->parent = new;
	return (new);
}
