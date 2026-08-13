#include "red_black.h"

int delete_node(RB_Node **root)
{
    int data;

    printf("Enter the data to delete : ");
    scanf("%d", &data);
    printf("Before deletion of node -> Red-Black tree:\n");
    inorder(*root);

    return perform_delete(root, data);
}

int perform_delete(RB_Node **root, int data)
{
    RB_Node *deletedNode = NIL;
    RB_Node *replacementNode = NIL;

    if (bst_delete(root, data, &deletedNode, &replacementNode) == FAILURE)
    {
        return FAILURE;
    }

    /* Deleted node is RED */
    if (deletedNode->color == RED)
    {
        free(deletedNode);
        return SUCCESS;
    }

    /* Deleted node is BLACK */
    fix_deletion(root, replacementNode);

    free(deletedNode);

    return SUCCESS;
}

int bst_delete(RB_Node **root,
               int data,
               RB_Node **deletedNode,
               RB_Node **replacementNode)
{
    RB_Node *current = *root;
    RB_Node *parent = NIL;

    /* Search Node */
    while (current != NIL)
    {
        if (data == current->data)
        {
            break;
        }

        parent = current;

        if (data < current->data)
        {
            current = current->left_subtree;
        }
        else
        {
            current = current->right_subtree;
        }
    }

    if (current == NIL)
    {
        return FAILURE;
    }

    /* Case 1 : Leaf Node */

    if (current->left_subtree == NIL &&
        current->right_subtree == NIL)
    {
        *deletedNode = current;
        *replacementNode = NIL;

        NIL->parent = parent;

        if (parent == NIL)
        {
            *root = NIL;
        }
        else if (parent->left_subtree == current)
        {
            parent->left_subtree = NIL;
        }
        else
        {
            parent->right_subtree = NIL;
        }
    }

    /* Case 2 : Only Left Child */

    else if (current->right_subtree == NIL)
    {
        *deletedNode = current;
        *replacementNode = current->left_subtree;

        current->left_subtree->parent = parent;

        if (parent == NIL)
        {
            *root = current->left_subtree;
        }
        else if (parent->left_subtree == current)
        {
            parent->left_subtree = current->left_subtree;
        }
        else
        {
            parent->right_subtree = current->left_subtree;
        }
    }

    /* Case 3 : Only Right Child */

    else if (current->left_subtree == NIL)
    {
        *deletedNode = current;
        *replacementNode = current->right_subtree;

        current->right_subtree->parent = parent;

        if (parent == NIL)
        {
            *root = current->right_subtree;
        }
        else if (parent->left_subtree == current)
        {
            parent->left_subtree = current->right_subtree;
        }
        else
        {
            parent->right_subtree = current->right_subtree;
        }
    }

    /* Case 4 : Two Children */

    else
    {
        RB_Node *successor = find_min(current->right_subtree);
        RB_Node *successorParent = successor->parent;

        current->data = successor->data;

        *deletedNode = successor;
        *replacementNode = successor->right_subtree;

        successor->right_subtree->parent = successorParent;

        if (successorParent->left_subtree == successor)
        {
            successorParent->left_subtree = successor->right_subtree;
        }
        else
        {
            successorParent->right_subtree = successor->right_subtree;
        }
    }

    return SUCCESS;
}