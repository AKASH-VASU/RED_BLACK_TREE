#include "red_black.h"

void inorder(RB_Node *root)
{
    if (root == NIL)
    {
        return;
    }

    inorder(root->left_subtree);

    printf("%d(", root->data);

    if (root->color == RED)
    {
        printf("RED --> 0");
    }
    else
    {
        printf("BLACK --> 1");
    }

    printf(") -> ");

    inorder(root->right_subtree);

}