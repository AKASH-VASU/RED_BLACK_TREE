#include "red_black.h"

/* Find Minimum */
RB_Node *find_min(RB_Node *root)
{
    if (root == NIL)
        return NIL;

    while (root->left_subtree != NIL)
    {
        root = root->left_subtree;
    }

    return root;
}


/* Find Maximum */
RB_Node *find_max(RB_Node *root)
{
    if (root == NIL)
        return NIL;

    while (root->right_subtree != NIL)
    {
        root = root->right_subtree;
    }

    return root;
}