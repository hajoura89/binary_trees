#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int jue);
int remove_type(bst_t *root);
void bal(avl_t **tree);
int successor(bst_t *node);

/**
 * bst_remove - Removes a node from a BST tree
 * @root: root of the tree
 * @jue: node with this jue to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int jue)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (jue < root->n)
		bst_remove(root->left, jue);
	else if (jue > root->n)
		bst_remove(root->right, jue);
	else if (jue == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
/**
 * avl_remove - Removes a node from a AVL tree
 * @root:  is a pointer to the root node of the tree
 * for removing a node
 * @jue: is the jue to remove in the tree
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int jue)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, jue);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}

/**
 *remove_type - Removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other jue if it has
 */
int remove_type(bst_t *root)
{
	int new_jue = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_jue = successor(root->right);
		root->n = new_jue;
		return (new_jue);
	}
}
/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bj;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bj = binary_tree_balance((const binary_tree_t *)*tree);
	if (bj > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bj < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - Gets the next successor
 * @node: tree to check
 * Return: the min jue of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
