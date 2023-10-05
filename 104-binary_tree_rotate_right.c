#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates right the binary tree
 * @tree:is a pointer to the root node to rotate
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pvt = tree->left;
	tree->left = pvt->right;
	if (pvt->right != NULL)
	{
		pvt->right->parent = tree;
	}
	pvt->right = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}
