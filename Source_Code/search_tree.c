#include "red_black.h"

int search(RB_Node *root)
{
    int key;

    if (root == NIL)
    {
        printf("INFO : FAILURE : Tree is Empty\n");
        return FAILURE;
    }

    printf("Enter the element to search : ");
    scanf("%d", &key);

    RB_Node *temp = root;

    while (temp != NIL)
    {
        if (key == temp->data)
        {
            printf("Node Found : %d (%s -> %d)\n",
                    key,
                    (temp->color == RED) ? "RED" : "BLACK",
                    temp->color);

            return SUCCESS;
        }
        else if (key < temp->data)
        {
            temp = temp->left_subtree;
        }
        else
        {
            temp = temp->right_subtree;
        }
    }

    printf("INFO : FAILURE : Element %d not found\n", key);

    return FAILURE;
}