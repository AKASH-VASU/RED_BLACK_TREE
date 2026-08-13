#include "red_black.h"

void fix_deletion(RB_Node **root, RB_Node *doubleBlackNode)
{
    RB_Node *parentNode;
    RB_Node *siblingNode;
    RB_Node *nearChild;
    RB_Node *farChild;

    /* Case 2 : Double Black is Root */

    if (doubleBlackNode == *root)
    {
        doubleBlackNode->color = BLACK;
        return;
    }

    parentNode = doubleBlackNode->parent;

    /* Finding Sibling */

    if (parentNode->left_subtree == doubleBlackNode)
    {
        siblingNode = parentNode->right_subtree;
    }
    else
    {
        siblingNode = parentNode->left_subtree;
    }

    /* Finding Near Child and Far Child */

    if (parentNode->left_subtree == doubleBlackNode)
    {
        nearChild = siblingNode->left_subtree;
        farChild = siblingNode->right_subtree;
    }
    else
    {
        nearChild = siblingNode->right_subtree;
        farChild = siblingNode->left_subtree;
    }

    /* Case 3 : Sibling is BLACK and both children are BLACK */

    if (siblingNode->color == BLACK &&
        siblingNode->left_subtree->color == BLACK &&
        siblingNode->right_subtree->color == BLACK)
    {
        siblingNode->color = RED;

        if (parentNode->color == RED)
        {
            parentNode->color = BLACK;
            return;
        }

        fix_deletion(root, parentNode);
        return;
    }

    /* Case 4 : Sibling is RED */

    if (siblingNode->color == RED)
    {
        Colors temp = parentNode->color;
        parentNode->color = siblingNode->color;
        siblingNode->color = temp;

        if (parentNode->left_subtree == doubleBlackNode)
        {
            left_rotate(root, parentNode);
        }
        else
        {
            right_rotate(root, parentNode);
        }

        fix_deletion(root, doubleBlackNode);
        return;
    }

    /* Case 5 : Sibling BLACK, Near Child RED, Far Child BLACK */

    if (siblingNode->color == BLACK &&
        nearChild->color == RED &&
        farChild->color == BLACK)
    {
        Colors temp = siblingNode->color;
        siblingNode->color = nearChild->color;
        nearChild->color = temp;

        if (parentNode->left_subtree == doubleBlackNode)
        {
            right_rotate(root, siblingNode);
        }
        else
        {
            left_rotate(root, siblingNode);
        }

        fix_deletion(root, doubleBlackNode);
        return;
    }

    /* Case 6 : Sibling BLACK, Far Child RED */

    if (siblingNode->color == BLACK &&
        farChild->color == RED)
    {
        Colors temp = parentNode->color;
        parentNode->color = siblingNode->color;
        siblingNode->color = temp;

        farChild->color = BLACK;

        if (parentNode->left_subtree == doubleBlackNode)
        {
            left_rotate(root, parentNode);
        }
        else
        {
            right_rotate(root, parentNode);
        }

        return;
    }
}











































