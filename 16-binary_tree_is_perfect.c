#include "binary_trees.h"
#include "15-binary_tree_is_full.c"
#include "10-binary_tree_depth.c"
#include "9-binary_tree_height.c"
/**
 * tree_perfect - checks leaves of a binary tree are same level.
 * @tree: a pointer to the root node
 * @ht: the height of the tree
 * Return: 1 or 0
 */
int binary_leave_perfect(const binary_tree_t *tree, int ht)
{
	if (!tree->left && !tree->right)
		return (((int)(binary_tree_depth(tree)) == ht) ? 1 : 0);
	else
		return (binary_leave_perfect(tree->left, ht)
				* binary_leave_perfect(tree->right, ht));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node
 * Return: 0 If tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int hgt;

	if (!tree || !binary_tree_is_full(tree))
		return (0);
	hgt = (int)binary_tree_height(tree);
	return (binary_leave_perfect(tree, hgt));
}
