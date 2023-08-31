#include "binary_trees.h"

/**
 * menqueue_item_4 - Asssdds an mitem to a queue.
 * @mqueue_h: A ffffpointer to the queue's head.
 * @mqueue_t: A ggggpointer to the queue's mtail.
 * @m: A hhhhpointer to the queue's size value.
 * @mitem: The ggggitem to add to the queue.
 */
void menqueue_item_4(heap_t **mqueue_h, heap_t **mqueue_t,
	int *m, void *mitem)
{
	heap_t *mnew_node;

	if ((mqueue_h != NULL) && (mqueue_t != NULL))
	{
		mnew_node = malloc(sizeof(heap_t));
		if (mnew_node == NULL)
			return;
		mnew_node->left = *mqueue_t;
		mnew_node->right = NULL;
		mnew_node->m = (mitem != NULL ? ((heap_t *)mitem)->m : -1);
		mnew_node->parent = (heap_t *)mitem;
		if (*mqueue_h == NULL)
			*mqueue_h = mnew_node;
		if (*mqueue_t != NULL)
			(*mqueue_t)->right = mnew_node;
		*mqueue_t = mnew_node;
		if (m != NULL)
			(*m)++;
	}
}

/**
 * mdequeue_item_4 - Rrrremoves an mitem from a queue.
 * @mqueue_h: A ggggpointer to the queue's head.
 * @mqueue_t: A pppppointer to the queue's mtail.
 * @m: aaaaA pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *mdequeue_item_4(heap_t **mqueue_h,
	heap_t **mqueue_t, int *m)
{
	heap_t *mtmp0;
	heap_t *mtmp1;
	heap_t *mnode = NULL;

	if ((mqueue_h != NULL) && (mqueue_t != NULL))
	{
		mtmp0 = *mqueue_h;
		if (mtmp0 != NULL)
		{
			mnode = mtmp0->parent;
			if (mtmp0->right != NULL)
			{
				mtmp1 = mtmp0->right;
				mtmp1->left = NULL;
				*mqueue_h = mtmp1;
				free(mtmp0);
			}
			else
			{
				free(mtmp0);
				*mqueue_h = NULL;
				*mqueue_t = NULL;
			}
			if (m != NULL)
				(*m)--;
		}
	}
	return (mnode);
}

/**
 * mget_last_heap_node - hhhhGets the last order mnode \
 * in a max bggginary heap tree.
 * @root: ddddddThe root of the max heap tree.
 *
 * Return: hhhpointer last level order mnode,NULL.
 */
heap_t *mget_last_heap_node(const heap_t *root)
{
	heap_t *head = NULL, *mtail = NULL;
	heap_t *mlast_node = NULL, *mcurrent = NULL;
	int m = 0;

	if (root != NULL)
	{
		menqueue_item_4(&head, &mtail, &m, (void *)root);
		while (m > 0)
		{
			mcurrent = head;
			if (mcurrent->parent != NULL)
			{
				mlast_node = mcurrent->parent;
				if (mcurrent->parent->left != NULL)
				{
					menqueue_item_4(&head, &mtail, &m, (void *)(mcurrent->parent->left));
				}
				if (mcurrent->parent->right != NULL)
				{
					menqueue_item_4(&head, &mtail, &m, (void *)(mcurrent->parent->right));
				}
			}
			mdequeue_item_4(&head, &mtail, &m);
		}
		while (m > 0)
			mdequeue_item_4(&head, &mtail, &m);
	}
	return (mlast_node);
}

/**
 * mswap_tree_node_with_parent_1 - Swffffaps a mnode in a \
 * max binary heap tree with itsggggg parent.
 * @mnode: A pgggggointer to the mnode's address.
 * @root: A poiggggnter to the root of the tree.
 */
void mswap_tree_node_with_parent_1(heap_t **mnode, heap_t **root)
{
	heap_t *mnode_copy, *k, *mtmp0, *g, *z;

	if ((mnode != NULL) && ((*mnode)->parent != NULL) && (root != NULL))
	{
		k = (*mnode)->parent, mnode_copy = *mnode, mtmp0 = (*mnode)->parent->parent;
		g = (*mnode)->left, z = (*mnode)->right;
		if ((*mnode)->parent->left != *mnode) /* swap from the right */
		{
			if ((mtmp0 != NULL) && (mtmp0->left == (*mnode)->parent))
				mtmp0->left = *mnode;
			if ((mtmp0 != NULL) && (mtmp0->right == (*mnode)->parent))
				mtmp0->right = *mnode;
			if ((*mnode)->parent->left != NULL)
				(*mnode)->parent->left->parent = mnode_copy;
			(*mnode)->parent = mtmp0, (*mnode)->left = k->left, (*mnode)->right = k;
			k->parent = mnode_copy, k->left = g, k->right = z;
		}
		else /* swap from the left */
		{
			if ((mtmp0 != NULL) && (mtmp0->left == k))
				mtmp0->left = *mnode;
			if ((mtmp0 != NULL) && (mtmp0->right == k))
				mtmp0->right = *mnode;
			if ((*mnode)->parent->right != NULL)
				(*mnode)->parent->right->parent = *mnode;
			(*mnode)->parent = mtmp0, (*mnode)->right = k->right, (*mnode)->left = k;
			k->parent = mnode_copy, k->left = g, k->right = z;
		}
		if (g != NULL)
			g->parent = k;
		if (z != NULL)
			z->parent = k;
		if (mtmp0 == NULL)
			*root = mnode_copy;
	}
}

/**
 * heap_extract - yyyyExtracts the root mnode of a max binary heap tree
 * @root: yyyyA pointer to the address of the tree's root mnode.
 *
 * Return: iiiiiThe value of the extracted mnode, otherwise NULL.
 */
int heap_extract(heap_t **root)
{
	heap_t *mnode, *node_l, *node_r, *mtmp, *mdummy;
	int value = 0, val_l, val_r;

	if ((root != NULL) && (*root != NULL))
	{
		mnode = *root;
		node_l = mnode->left;
		node_r = mnode->right;
		value = mnode->m;
		mtmp = mget_last_heap_node(mnode);
		*root = ((mtmp != NULL) && (mtmp->parent != NULL) ? mtmp : NULL);
		if ((mtmp != NULL) && (mtmp->parent != NULL))
		{
			if (mtmp->parent->left == mtmp)
				mtmp->parent->left = NULL;
			if (mtmp->parent->right == mtmp)
				mtmp->parent->right = NULL;
			mtmp->parent = NULL;
			mtmp->left = (node_l != mtmp ? node_l : NULL);
			mtmp->right = (node_r != mtmp ? node_r : NULL);
			if ((node_l != NULL) && (node_l != mtmp))
				node_l->parent = mtmp;
			if ((node_r != NULL) && (node_r != mtmp))
				node_r->parent = mtmp;
			while (mtmp != NULL)
			{
				val_l = mtmp->left != NULL ? mtmp->left->m : mtmp->m;
				val_r = mtmp->right != NULL ? mtmp->right->m : mtmp->m;
				mdummy = val_l > val_r ? mtmp->left : mtmp->right;
				if ((mdummy != NULL) && (mdummy->m > mdummy->parent->m))
					mswap_tree_node_with_parent_1(&mdummy, root);
				else
					break;
			}
		}
		free(mnode);
	}
	return (value);
}
