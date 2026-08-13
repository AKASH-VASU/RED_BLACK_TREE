#ifndef RED_BLACK_H
#define RED_BLACK_H

#include <stdio.h>
#include <stdlib.h>

#define FAILURE -1
#define SUCCESS 0
#define DUPLICATE ((RB_Node *)-1)

/* Colour */
typedef enum
{
    RED,
    BLACK
} Colors;

/* Node for Red Black Tree */
typedef struct Node
{
    int data;
    Colors color;

    struct Node *left_subtree;
    struct Node *right_subtree;
    struct Node *parent;

} RB_Node;

/* Global NIL Node */
extern RB_Node *NIL;


/* Create Tree */
int create_tree(RB_Node **root);

/* Create Node */
RB_Node *create_node(int data);

/* Find Parent */
RB_Node *find_parent(int data, RB_Node *root);

/* Fix Insertion */
int fix_insertion(RB_Node **root, RB_Node *childNode);


/* Rotations */
void left_rotate(RB_Node **root, RB_Node *grand);
void right_rotate(RB_Node **root, RB_Node *grand);

void left_left_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent);
void right_right_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent);
void left_right_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent);
void right_left_rotation(RB_Node **root, RB_Node *grand, RB_Node *parent);


/* Search */
int search(RB_Node *root);


/* Find Minimum / Maximum */
RB_Node *find_min(RB_Node *root);
RB_Node *find_max(RB_Node *root);


/* Display */
void inorder(RB_Node *root);


/* Delete */
int delete_node(RB_Node **root);

int perform_delete(RB_Node **root, int data);

int bst_delete(RB_Node **root,int data,RB_Node **deletedNode,RB_Node **replacementNode);

void fix_deletion(RB_Node **root, RB_Node *doubleBlackNode);


/* Delete Min / Max */
int delete_min(RB_Node **root);
int delete_max(RB_Node **root);

#endif