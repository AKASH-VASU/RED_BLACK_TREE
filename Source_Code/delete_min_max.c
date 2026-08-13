#include "red_black.h"

int delete_min(RB_Node **root)
{
    RB_Node *minNode;

    if (*root == NIL)
        return FAILURE;

    minNode = find_min(*root);

    if (minNode == NIL)
        return FAILURE;

    printf("Deleting Minimum Node : %d (", minNode->data);

    if (minNode->color == RED)
        printf("RED --> 0");
    else
        printf("BLACK --> 1");

    printf(")\n");

    return perform_delete(root, minNode->data);
}

int delete_max(RB_Node **root)
{
    RB_Node *maxNode;

    if (*root == NIL)
        return FAILURE;

    maxNode = find_max(*root);

    if (maxNode == NIL)
        return FAILURE;

    printf("Deleting Maximum Node : %d (", maxNode->data);

    if (maxNode->color == RED)
        printf("RED --> 0");
    else
        printf("BLACK --> 1");

    printf(")\n");

    return perform_delete(root, maxNode->data);
}