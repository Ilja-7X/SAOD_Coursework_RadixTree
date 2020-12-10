#include "radixTree.h"

struct RadixTree *radixTreeCreate(int size)
{
    struct RadixTree *node;

    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;
    if ((node->string = malloc((size + 1) * sizeof(char))) == NULL)
        return NULL;
    node->value = NULL;
    node->sibling = NULL;
    node->child = NULL;
    return node;
}

struct RadixTree *radixTreeInsert(struct RadixTree *root, char *key, char *value)
{
    struct RadixTree *node, *parent, *list;
    char *string, *prefix;

    parent = NULL;
    list = root;
    string = key;

    int flag = 1;

    while (flag == 1)
    {
        for (node = list; node != NULL; node = node->sibling)
        {
            prefix = node->string;
            for (; (*prefix != '\0') || (*string != '\0'); prefix++, string++) // проходит все одинаковые символы в обеих строках
            {
                if (*prefix != *string)
                    break;
            }

            if ((*prefix == '\0') && (*string == '\0'))
            {
                flag = 0;
                break;
            }
            else if ((*prefix == '\0') && (*string != '\0'))
            {
                break;
            }

            /*if ((*prefix == '\0') && (*string != '\0'))
                {
                    flag = 0;
                    break;
                }*/
            //if ((*prefix != '\0') && (*string == '\0'))
        }

        if (node == NULL)
        {
            node = radixTreeCreate(strlen(string));
            strcpy(node->string, string);
            node->sibling = list;
            if (parent != NULL)
                parent->child = node;
            else
                root = node;
            flag = 0;
        }
        else
        {
            list = node->child;
        }
        parent = node;
    }

    if (node->value != NULL)
        free(node->value);
    node->value = strdup(value);

    return root;
}

/*struct RadixTree *radixTreeInsert(struct RadixTree *root, char *key, char *value)
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
}*/
