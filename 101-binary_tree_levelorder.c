#include "binary_trees.h"

/**
 * binary_tree_levelorder - aaaaaaaaaaaaaaaaaaaaaaa
 * @tree: aaaaaaaaaaaaaaaaaaaaa
 * @func: aaaaaaaaaaaaaaaaaaaaaaaaaaaa
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t mlevel, smaxlevel;

	if (!tree || !func)
		return;

	smaxlevel = binary_tree_height(tree) + 1;

	for (mlevel = 1; mlevel <= smaxlevel; mlevel++)
		mbtlo_helper(tree, func, mlevel);
}

/**
 * mbtlo_helper - aaaaaaaaaaaaaaaaaaaaaaa
 * @tree: fffffffffffffffffffffff
 * @func: hhhhhhhhhhhhhhhhhhhhhhh
 * @mlevel: jjjjjjjjjjjjjjjjjjjjjjjjjjj
 */
void mbtlo_helper(const binary_tree_t *tree, void (*func)(int), size_t mlevel)
{
	if (mlevel == 1)
		func(tree->n);
	else
	{
		mbtlo_helper(tree->left, func, mlevel - 1);
		mbtlo_helper(tree->right, func, mlevel - 1);
	}
}

/**
 * binary_tree_height - fffffffffffffff
 * @tree: gggggggggggggggggggggg
 *
 * Return: ggggggggggggggge
 *         0 ggggggggggggggggggg
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t mheight_l = 0;
	size_t mheight_r = 0;

	if (!tree)
		return (0);

	mheight_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	mheight_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (mheight_l > mheight_r ? mheight_l : mheight_r);
}
