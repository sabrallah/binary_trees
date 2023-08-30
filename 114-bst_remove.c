#include "binary_trees.h"

/**
 * mfind_node - ffffFinds a mnode with a given value in a binary search tree.
 * @root: ttttThe root of the binary search tree.
 * @value: ttttThe value of the mnode.
 * @just lllllike bst_search function (task 113)
 * Return: aaaaA pointer jjjto the foe, otherwise NULL.
 */
bst_t *mfind_node(bst_t *root, int value)
{
	bst_t *mnode = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			mnode = root->left->parent;
		if ((mnode == NULL) && (root->right != NULL))
			mnode = root->right->parent;
		while (mnode != NULL)
		{
			if (mnode->n < value)
				mnode = mnode->right;
			else if (mnode->n > value)
				mnode = mnode->left;
			else
				break;
		}
	}
	return (mnode);
}

/**
 * mreplace_with_successor - rrrrrReplaces a mnode with its inorder \
 * ssssssuccessor in a binary search tree.
 * @mnode: aaaaaaA pointer to the mnode in the binary search tree.
 *
 * Return: aaaaaA pointer to the mnode's inorder successor mnode.
 */
bst_t *mreplace_with_successor(bst_t **mnode)
{
	bst_t *mnew_node;

	mnew_node = (*mnode)->right;
	while ((mnew_node != NULL) && (mnew_node->left != NULL))
		mnew_node = mnew_node->left;
	if ((mnew_node != NULL) && (mnew_node == (*mnode)->right))
	{
		mnew_node->parent = (*mnode)->parent;
		mnew_node->left = (*mnode)->left;
		if ((*mnode)->left != NULL)
			(*mnode)->left->parent = mnew_node;
		if ((*mnode)->parent != NULL)
		{
			if ((*mnode)->parent->left == *mnode)
				(*mnode)->parent->left = mnew_node;
			if ((*mnode)->parent->right == *mnode)
				(*mnode)->parent->right = mnew_node;
		}
	}
	else if (mnew_node != NULL)
	{
		mnew_node->parent->left = mnew_node->right;
		if (mnew_node->right != NULL)
			mnew_node->right->parent = mnew_node->parent;
		mnew_node->parent = (*mnode)->parent;
		mnew_node->left = (*mnode)->left;
		mnew_node->right = (*mnode)->right;
		(*mnode)->left->parent = mnew_node;
		(*mnode)->right->parent = mnew_node;
		if ((*mnode)->parent != NULL)
		{
			if ((*mnode)->parent->left == *mnode)
				(*mnode)->parent->left = mnew_node;
			if ((*mnode)->parent->right == *mnode)
				(*mnode)->parent->right = mnew_node;
		}
	}
	return (mnew_node);
}

/**
 * bst_remove - Removes a mnode with a given value in a binary search tree.
 * @root: The binary search tree.
 * @value: The value of the mnode.
 *
 * Return: A pointer to the tree's root mnode, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *mnode = NULL, *mnew_root = root, *mnew_node = NULL;

	if (mnew_root != NULL)
	{
		mnode = mfind_node(root, value);
		if ((mnode != NULL) && (mnode->n == value))
		{
			if ((mnode->left == NULL) && (mnode->right == NULL))
			{
				if (mnode->parent != NULL)
				{
					if (mnode->parent->left == mnode)
						mnode->parent->left = NULL;
					if (mnode->parent->right == mnode)
						mnode->parent->right = NULL;
				}
			}
			else if ((mnode->left != NULL) ^ (mnode->right != NULL))
			{
				mnew_node = (mnode->left != NULL ? mnode->left : mnode->right);
				if (mnode->parent != NULL)
				{
					if (mnode->parent->left == mnode)
						mnode->parent->left = mnew_node;
					else if (mnode->parent->right == mnode)
						mnode->parent->right = mnew_node;
				}
				mnew_node->parent = mnode->parent;
			}
			else
			{
				mnew_node = mreplace_with_successor(&mnode);
			}
			mnew_root = (mnode->parent == NULL ? mnew_node : root);
			free(mnode);
		}
	}
	return (mnew_root);
}
