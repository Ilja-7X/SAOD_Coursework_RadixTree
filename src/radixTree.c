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
            else if ((*prefix != '\0') && (*string == '\0'))
            {
                split(node, prefix);
                flag = 0;
                break;
            }

            else if (*prefix != *string)
            {
                if (prefix != node->string)
                {
                    parent = node;
                    node = split(node, prefix);
                    list = node;
                }
                list = node;
            }
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

struct RadixTree *split(struct RadixTree *node, char *prefix)
{
    struct RadixTree *newNode = radixTreeCreate(strlen(prefix) + 1);
    strcpy(newNode->string, prefix);

    *prefix = '\0';

    node->string = realloc(node->string, prefix - node->string + 1);
    if (node->value != NULL)
    {
        newNode->value = node->value;
        node->value = NULL;
    }
    newNode->child = node->child;
    node->child = newNode;
    return newNode;
}

void trie_print(struct RadixTree *root, int level, int check)
{
    struct RadixTree *node;
    int i;

    for (node = root; node != NULL; node = node->sibling)
    {
        if (check == 1)
        {
            for (i = 0; i < level; i++)
            {
                printf(" ");
            }
            check = 0;
        }
        if (node->value != NULL)
        {
            printf("%s - %s\n", node->string, node->value);
            check = 1;
        }
        else
        {
            printf("%s", node->string);
        }
        if (node->child != NULL)
        {
            trie_print(node->child, level + 1, check);
        }
        check = 1;
    }
}
