#include "radixTree.h"

struct RadixTree *radixTreeCreate(int size)
{
    struct RadixTree *node;

    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;
    if ((node->key = malloc((size + 1) * sizeof(char))) == NULL)
        return NULL;
    node->value = NULL;
    node->sibling = NULL;
    node->child = NULL;
    return node;
}

struct RadixTree *radixTreeInsert(struct RadixTree *root, char *key, char *value)
{
    struct RadixTree *node, *parent, *list;
    int *count;

    parent = NULL;
    list = root;

    *count = 0;

    return radixTreeInsertRecurs(root, parent, key, count, value);
}

struct RadixTree *radixRreeInsertRecurs(struct RadixTree *currentNode, struct RadixTree *parent, char *key, int *count, char *value)
{

    struct RadixTree *node, *list;
    list = currentNode;

    for (node = list; node != NULL; node = node->sibling)
    {
    }
}
