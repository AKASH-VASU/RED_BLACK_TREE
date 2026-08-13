#include "red_black.h"

/* Create Node */
RB_Node *create_node(int data)
{
    RB_Node *newNode = (RB_Node *)malloc(sizeof(RB_Node));

    if (newNode == NULL)
    {
        printf("INFO : FAILURE : Node not created!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->color = RED;

    newNode->left_subtree = NIL;
    newNode->right_subtree = NIL;
    newNode->parent = NIL;

    return newNode;
}


/* Find Parent */
RB_Node *find_parent(int data, RB_Node *root)
{
    RB_Node *tempNode = root;
    RB_Node *prev = NIL;

    while (tempNode != NIL)
    {
        prev = tempNode;

        if (data < tempNode->data)
        {
            tempNode = tempNode->left_subtree;
        }
        else if (data > tempNode->data)
        {
            tempNode = tempNode->right_subtree;
        }
        else
        {
            return DUPLICATE;
        }
    }

    return prev;
}


/* Fix Insertion */
int fix_insertion(RB_Node **root, RB_Node *childNode)
{
    if (childNode == *root)
    {
        (*root)->color = BLACK;
        return SUCCESS;
    }

    if (*root == childNode->parent)
    {
        childNode->parent->color = BLACK;
        return SUCCESS;
    }

    RB_Node *parentNode = childNode->parent;
    RB_Node *grandParentNode = parentNode->parent;
    RB_Node *uncleNode;

    if (parentNode == grandParentNode->left_subtree)
    {
        uncleNode = grandParentNode->right_subtree;
    }
    else
    {
        uncleNode = grandParentNode->left_subtree;
    }

    /* Recolor */
    if (parentNode->color == RED &&
        uncleNode != NIL &&
        uncleNode->color == RED)
    {
        parentNode->color = BLACK;
        uncleNode->color = BLACK;
        grandParentNode->color = RED;

        fix_insertion(root, grandParentNode);

        return SUCCESS;
    }

    /* Rotations */
    else if (parentNode->color == RED &&
             (uncleNode == NIL || uncleNode->color == BLACK))
    {
        if (parentNode == grandParentNode->left_subtree &&
            childNode == parentNode->left_subtree)
        {
            /* LL */
            left_left_rotation(root, grandParentNode, parentNode);
        }
        else if (parentNode == grandParentNode->right_subtree &&
                 childNode == parentNode->right_subtree)
        {
            /* RR */
            right_right_rotation(root, grandParentNode, parentNode);
        }
        else if (parentNode == grandParentNode->left_subtree &&
                 childNode == parentNode->right_subtree)
        {
            /* LR */
            left_right_rotation(root, grandParentNode, parentNode);
        }
        else if (parentNode == grandParentNode->right_subtree &&
                 childNode == parentNode->left_subtree)
        {
            /* RL */
            right_left_rotation(root, grandParentNode, parentNode);
        }
    }

    (*root)->color = BLACK;

    return SUCCESS;
}


/* Right Rotation */
void right_rotate(RB_Node **root, RB_Node *grand)
{
    RB_Node *parent = grand->left_subtree;
    RB_Node *temp = parent->right_subtree;

    grand->left_subtree = temp;

    if (temp != NIL)
    {
        temp->parent = grand;
    }

    parent->right_subtree = grand;

    parent->parent = grand->parent;

    if (grand->parent == NIL)
    {
        *root = parent;
    }
    else if (grand == grand->parent->left_subtree)
    {
        grand->parent->left_subtree = parent;
    }
    else
    {
        grand->parent->right_subtree = parent;
    }

    grand->parent = parent;
}


/* Left Rotation */
void left_rotate(RB_Node **root, RB_Node *grand)
{
    RB_Node *parent = grand->right_subtree;
    RB_Node *temp = parent->left_subtree;

    grand->right_subtree = temp;

    if (temp != NIL)
    {
        temp->parent = grand;
    }

    parent->left_subtree = grand;

    parent->parent = grand->parent;

    if (grand->parent == NIL)
    {
        *root = parent;
    }
    else if (grand == grand->parent->left_subtree)
    {
        grand->parent->left_subtree = parent;
    }
    else
    {
        grand->parent->right_subtree = parent;
    }

    grand->parent = parent;
}


/* LL Rotation */
void left_left_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent)
{
    right_rotate(root, grand);

    parent->color = BLACK;
    grand->color = RED;
}


/* RR Rotation */
void right_right_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent)
{
    left_rotate(root, grand);

    parent->color = BLACK;
    grand->color = RED;
}


/* LR Rotation */
void left_right_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent)
{
    left_rotate(root, parent);
    right_rotate(root, grand);

    grand->parent->color = BLACK;
    grand->color = RED;
}


/* RL Rotation */
void right_left_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent)
{
    right_rotate(root, parent);
    left_rotate(root, grand);

    grand->parent->color = BLACK;
    grand->color = RED;
}