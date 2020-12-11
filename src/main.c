#include "radixTree.h"

int main()
{
    struct RadixTree *node = NULL;
    node = radixTreeInsert(node, "hello", "345");
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");
    printf("-----------\n");

    node = radixTreeInsert(node, "helloword", "999");

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
    printf("-----------\n");

    node = radixTreeInsert(node, "hellowordyou", "333");
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    n = node->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    struct RadixTree *m = n->child;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);

    printf("\n");
    printf("-----------\n");

    node = radixTreeInsert(node, "helloguy", "895");
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    n = node->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    struct RadixTree *s = n->sibling;
    printf("%p\n", s);
    printf("node->string:%s\n", s->string);
    printf("node->value:%s\n", s->value);
    printf("node->sibling:%p\n", s->sibling);
    printf("node->child:%p\n", s->child);

    printf("\n");
    printf("-----------\n");
    printf("\n");

    node = radixTreeInsert(node, "hel", "134");
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    n = node->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    m = n->child;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);

    printf("\n");
    printf("-----------\n");
    printf("\n");

    node = radixTreeInsert(node, "hel", "1345");
    printf("node->string:%s\n", node->string);
    printf("node->value:%s\n", node->value);
    printf("node->sibling:%p\n", node->sibling);
    printf("node->child:%p\n", node->child);

    printf("\n");

    n = node->child;
    printf("%p\n", n);
    printf("node->string:%s\n", n->string);
    printf("node->value:%s\n", n->value);
    printf("node->sibling:%p\n", n->sibling);
    printf("node->child:%p\n", n->child);

    printf("\n");

    m = n->child;
    printf("%p\n", m);
    printf("node->string:%s\n", m->string);
    printf("node->value:%s\n", m->value);
    printf("node->sibling:%p\n", m->sibling);
    printf("node->child:%p\n", m->child);
    return 0;
}