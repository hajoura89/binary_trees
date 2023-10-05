#include "binary_trees.h"
size_t binary_tree__height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t tl, tr;

	if (!tree)
		return (0);
	tl = binary_tree__height(tree->left);
	tr = binary_tree__height(tree->right);

	return (tl - tr);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: the height (the longest path possible)
 */
size_t binary_tree__height(const binary_tree_t *tree)
{
	size_t h_right, h_left;

	if (!tree)
		return (-1);
	h_right = (tree->right) ? 1 + binary_tree__height(tree->right) : 0;
	h_left	= (tree->left) ? 1 + binary_tree__height(tree->left) : 0;
	if (h_right >= h_left)
		return (h_right);
	else
		return (h_left);
}

