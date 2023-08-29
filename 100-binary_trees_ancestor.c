#include "binary_trees.h"

/**
 * binary_trees_ancestor - aaaaaaaaaaaaaa
 * @first: aaaaaaaaaaaaaaaaaa
 * @second: aaaaaaaaaaaaaa
 *
 * Return: aaaaaaaaaaa
 *         taaaaaaaaaaaaaaaa
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t mdepth_first, mdepth_second;

	if (!first || !second)
		return (NULL);

	mdepth_first = binary_tree_depth(first);
	mdepth_second = binary_tree_depth(second);

	while (mdepth_first > mdepth_second)
	{
		first = first->parent;
		mdepth_first--;
	}
	while (mdepth_second > mdepth_first)
	{
		second = second->parent;
		mdepth_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - aaaaaaaaaaaaaaaaaa
 * @tree: aaaaaaaaaaaaaaaaaaa
 *
 * Return: aaaaaaaaaaaaaa
 *         0 iaaaaaaaaaaaaaa
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t mdepth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		mdepth++;
		tree = tree->parent;
	}

	return (mdepth);
}
