#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert- Inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *swt;
	int size, lv, sub, b, lvl, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	lv = size;

	for (lvl = 0, sub = 1; lv >= sub; sub *= 2, lvl++)
		lv -= sub;
	for (b = 1 << (lvl - 1); b != 1; b >>= 1)
		tree = lv & b ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	lv & 1 ? (tree->right = new) : (tree->left = new);

	swt = new;
	for (; swt->parent && (swt->n > swt->parent->n); swt = swt->parent)
	{
		temp = swt->n;
		swt->n = swt->parent->n;
		swt->parent->n = temp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the tree to be measured
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
