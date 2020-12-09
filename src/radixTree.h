#ifndef RADIXTREE_H
#define RADIXTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RadixTree
{
    char *value;
    char *key;
    struct trie *sibling;
    struct trie *child;
};

struct RadixTree *radixTreeCreate(int size);

#endif
