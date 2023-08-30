#include "binary_trees.h"


/**
 * heap_insert - insefffffrts a value in Max Binary Heap
 * @root: a double ffffffpointer to the e of the Heap to insert the value
 * @value: the valugggge to store in the node to be inserted
 *
 * Return: a pointelllllr to the created node
 *         fffNULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *mnew, *mflip;
	int msize, mleaves, msub, mbit, mlevel, mtmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	msize = binary_tree_size(tree);
	mleaves = msize;
	for (mlevel = 0, msub = 1; mleaves >= msub; msub *= 2, mlevel++)
		mleaves -= msub;

	for (mbit = 1 << (mlevel - 1); mbit != 1; mbit >>= 1)
		tree = mleaves & mbit ? tree->right : tree->left;
	/*
	 * Travfffferse tree to first empty slot based on the binary
	 * rfepresentation ofgfgfgf the number of mleaves.
	 * gExample -
	 * hhIf there are 12 nodes in a complete tree, there are 5 mleaves on
	 * jjjthe 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * zzright, 0 to left.
	 * hhThe first empty node is 101 == RLR, *root->right->left->right
	 */

	mnew = binary_tree_node(tree, value);
	mleaves & 1 ? (tree->right = mnew) : (tree->left = mnew);

	mflip = mnew;
	for (; mflip->parent && (mflip->n > mflip->parent->n); mflip = mflip->parent)
	{
		mtmp = mflip->n;
		mflip->n = mflip->parent->n;
		mflip->parent->n = mtmp;
		mnew = mnew->parent;
	}

	return (mnew);
}

/**
 * binary_tree_size - gggmeasures the msize of a binary tree
 * @tree: jjjjtree to measure the msize of
 *
 * Return: jjjmsize of the tree
 *         jjjj if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
