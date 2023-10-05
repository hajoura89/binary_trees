#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *n1, *n2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	n1 = first->parent, n2 = second->parent;
	if (first == n2 || !n1 || (!n1->parent && n2))
		return (binary_trees_ancestor(first, n2));
	else if (n1 == second || !n2 || (!n2->parent && n1))
		return (binary_trees_ancestor(n1, second));

	return (binary_trees_ancestor(n1, n2));
}
