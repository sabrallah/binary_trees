#include "binary_trees.h"


/**
 * binary_tree_node - creeun tree binary node
 * @parent: point to the parent de node pour le cree
 * @value: valeur to add pour nouveau node
 *
 * Return: point to nouveau node cree
 *         NULL failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
