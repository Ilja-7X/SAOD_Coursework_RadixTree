#ifndef RADIXTREE_H
#define RADIXTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RadixTree
{
    char *value;
    char *string;
    struct RadixTree *sibling;
    struct RadixTree *child;
};

struct RadixTree *radixTreeCreate(int size);
struct RadixTree *radixTreeInsert(struct RadixTree *root, char *key, char *value);
struct RadixTree *split(struct RadixTree *node, char *prefix);
void radixTreePrint(struct RadixTree *root, int level, int check);
char *radixTreeLookup(struct RadixTree *root, char *key);
struct RadixTree *radixTreeDelete(struct RadixTree *root, char *key);
struct RadixTree *radixTreeDeleteDfs(struct RadixTree *root, struct RadixTree *parent, char *key);
void nodesMerge(struct RadixTree *node);
void func(struct RadixTree *node);

#endif
