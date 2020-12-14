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
                //list = node;
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

void radixTreePrint(struct RadixTree *root, int level, int check)
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
            radixTreePrint(node->child, level + strlen(node->string), check);
        }
        check = 1;
    }
}

char *radixTreeLookup(struct RadixTree *root, char *key)
{
    struct RadixTree *node, *list;
    char *string, *prefix;

    list = root;
    string = key;

    int flag = 1;

    while (flag == 1)
    {
        for (node = list; node != NULL; node = node->sibling)
        {
            prefix = node->string;
            for (; (*prefix != '\0') || (*string != '\0'); prefix++, string++)
            {
                if (*prefix != *string)
                    break;
            }

            if ((*prefix == '\0') && (*string == '\0'))
            {
                flag = 0;
                break;
            }
            if ((*prefix == '\0') && (*string != '\0'))
            {
                break;
            }
        }
        if ((node != NULL) && (flag != 0))
        {
            list = node->child;
        }
        else if (flag != 0)
            return NULL;
    }

    return node->value;
}

struct RadixTree *radixTreeDelete(struct RadixTree *root, char *key)
{
    return radixTreeDeleteDfs(root, NULL, key);
}

struct RadixTree *radixTreeDeleteDfs(struct RadixTree *root, struct RadixTree *parent, char *key)
{
    struct RadixTree *node, *prev = NULL;
    char *prefix;
    //\*found = (*key == '\0' && root == NULL) ? 1 : 0;
    //if (root == NULL || *key == '\0')
    //    return root;
    for (node = root; node != NULL; node = node->sibling)
    {
        prefix = node->string;
        for (; (*prefix != '\0') || (*key != '\0'); prefix++, key++)
        {
            if (*prefix != *key)
                break;
        }

        if ((*prefix == '\0') && (*key == '\0'))
        {
            printf("found:%p\n", node);
            if (node->value != NULL)
            {
                if (node->child != NULL)
                {
                    struct RadixTree *childNote = node->child;
                    if (childNote->sibling != NULL)
                    {
                        free(node->value);
                        node->value = NULL;
                        return root;
                    }
                    else
                    {
                        /*node->string = realloc(node->string, strlen(node->string) + strlen(childNote->string) + 1);
                        node->string = strcat(node->string, childNote->string);
                        free(node->value);
                        node->value = childNote->value;
                        node->child = childNote->child;
                        free(childNote->string);
                        free(childNote);*/
                        nodesMerge(node);
                        return root;
                    }
                }
                else
                {
                    if (prev != NULL)
                    {
                        printf("prev->sibling:%s\n", prev->string);
                        prev->sibling = node->sibling;
                    }
                    else
                        parent->child = node->sibling;
                    free(node->string);
                    free(node->value);
                    free(node);

                    if (parent->value != NULL)
                        return root;
                    else
                    {
                        node = parent->child;
                        if (node->sibling == NULL)
                        {
                            /*node->string = realloc(node->string, strlen(node->string) + strlen(childNote->string) + 1);
                            node->string = strcat(node->string, childNote->string);
                            free(node->value);
                            node->value = childNote->value;
                            node->child = childNote->child;
                            free(childNote->string);
                            free(childNote);*/
                            printf("---------------\n");
                            printf("parent:\n");
                            func(parent);
                            printf("node:\n");
                            printf("\n");
                            func(node);
                            printf("\n");

                            nodesMerge(parent);
                        }
                        return root;
                    }
                }
            }

            return root;
        }

        if ((*prefix != '\0') && (*key == '\0'))
        {
            printf("not found:%p\n", node);
            return root;
        }

        if ((*prefix == '\0') && (*key != '\0'))
        {
            break;
        }
        prev = node;
    }
    if (node == NULL)
        return root;

    radixTreeDeleteDfs(node->child, node, key);

    return root;
}

void nodesMerge(struct RadixTree *node)
{
    struct RadixTree *childNode = node->child;
    node->string = realloc(node->string, strlen(node->string) + strlen(childNode->string) + 1);
    node->string = strcat(node->string, childNode->string);
    if (node->value != NULL)
        free(node->value);
    node->value = childNode->value;
    node->child = childNode->child;
    free(childNode->string);
    free(childNode);
}

void func(struct RadixTree *node)
{
    printf("%p\n", node);
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n\n", node->child);
}