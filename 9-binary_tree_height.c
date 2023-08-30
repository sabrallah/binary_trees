#include "binary_trees.h"



/**
 * binary_tree_height - hauteur tttt d'un arbre binaire
 * @tree: eur d'un arbretttt binaire
 *
 * Return: hauteur tttd'un arbre binaire
 *         mesure d'un gggarbre binaire
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t height_lef = 0;
size_t height_rig = 0;

if (!tree)
return (0);

height_lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
height_rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;
return (height_lef > height_rig ? height_lef : height_rig);
}
