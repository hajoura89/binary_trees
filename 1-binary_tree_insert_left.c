#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: A pointer to the node to insert
 * @value: The value to store the newnode node
 * Return: A pointer to the created node, NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
        binary_tree_t *newnode;

        if (parent == NULL)
                return (NULL);

        newnode = binary_tree_node(parent, value);
        if (newnode == NULL)
                return (NULL);

        if (parent->left != NULL)
        {
                newnode->left = parent->left;
                parent->left->parent = newnode;
        }
        parent->left = newnode;

        return (newnode);
}
