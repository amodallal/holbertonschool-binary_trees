#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * power - Calculates exponentiation (base^exp)
 * @base: Base number
 * @exp: Exponent
 * Return: Result of base^exp
 */
size_t power(size_t base, size_t exp)
{
    size_t result = 1;

    while (exp > 0)
    {
        result *= base;
        exp--;
    }

    return (result);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, size;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);
    size = binary_tree_size(tree);

    return (size == power(2, height) - 1);
}
