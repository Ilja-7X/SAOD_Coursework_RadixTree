#include "radixTree.h"

int main()
{
    struct RadixTree *node = NULL;
    /*node = radixTreeInsert(node, "admiral", "007");
    printf("%p\n", node);
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");
    printf("-----------\n");

    node = radixTreeInsert(node, "add", "035");

    printf("%p\n", node);
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    struct RadixTree *n = node->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    struct RadixTree *m = n->sibling;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);

    printf("\n");
    printf("-----------\n");
    printf("\n");

    node = radixTreeInsert(node, "bag", "404");
    printf("%p\n", node);
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    struct RadixTree *r = node->sibling;
    printf("%p\n", r);
    printf("node->string:%s\n", r->string);
    printf("node->value:%s\n", r->value);
    printf("node->sibling:%p\n", r->sibling);
    printf("node->child:%p\n", r->child);

    printf("\n");

    n = r->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    m = n->sibling;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);

    printf("\n");
    printf("-----------\n");
    printf("\n");

    node = radixTreeInsert(node, "admir", "777");
    printf("%p\n", node);
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    r = node->sibling;
    printf("%p\n", r);
    printf("node->string:%s\n", r->string);
    printf("node->value:%s\n", r->value);
    printf("node->sibling:%p\n", r->sibling);
    printf("node->child:%p\n", r->child);

    printf("\n");

    n = r->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    m = n->sibling;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);

    printf("\n");

    struct RadixTree *b = m->child;
    printf("%p\n", b);
    printf("node->string:%s\n", b->string);
    printf("node->value:%s\n", b->value);
    printf("node->sibling:%p\n", b->sibling);
    printf("node->child:%p\n", b->child);

    printf("\n");
    printf("-----------\n");
    printf("\n");*/

    //node = radixTreeInsert(node, "addition", "3634");

    node = radixTreeInsert(node, "admiral", "777");
    node = radixTreeInsert(node, "admire", "792");
    node = radixTreeInsert(node, "admires", "046");
    node = radixTreeInsert(node, "admiralty", "257");
    node = radixTreeInsert(node, "add", "001");
    node = radixTreeInsert(node, "addres", "1517");
    node = radixTreeInsert(node, "addition", "054");
    node = radixTreeInsert(node, "additive", "200");
    node = radixTreeInsert(node, "hello", "000");
    node = radixTreeInsert(node, "helloworld", "009");
    node = radixTreeInsert(node, "ad", "002");

    radixTreePrint(node, 0, 1);

    char *value = radixTreeLookup(node, "admiral");
    printf("\n%s\n", value);
    return 0;
}