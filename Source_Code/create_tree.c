#include "red_black.h"

int create_tree(RB_Node **root)
{
    int data;
    char choice;

    do
    {
        printf("\nEnter the Element : ");
        scanf("%d", &data);

        /* First Node */
        if (*root == NIL)
        {
            RB_Node *newNode = create_node(data);

            if (newNode == NULL)
                return FAILURE;

            newNode->color = BLACK;
            *root = newNode;

            printf("\nBefore Balancing Red Black Tree is :\n");
            inorder(*root);
            printf("\n");

            printf("Now Tree is Balance\n");
            inorder(*root);
            printf("\n");
        }
        else
        {
            /* Find Parent */
            RB_Node *parentNode = find_parent(data, *root);

            /* Duplicate */
            if (parentNode == DUPLICATE)
            {
                printf("\nINFO : FAILURE : Duplicate element not allowed.\n");

                printf("\nDo you want to continue (Y/N) : ");
                scanf(" %c", &choice);

                continue;
            }

            if (parentNode == NULL)
                return FAILURE;

            /* Create New Node */
            RB_Node *newNode = create_node(data);

            if (newNode == NULL)
                return FAILURE;

            newNode->parent = parentNode;

            /* BST Insertion */
            if (data > parentNode->data)
                parentNode->right_subtree = newNode;
            else
                parentNode->left_subtree = newNode;

            printf("\nBefore Balancing Red Black Tree is :\n");
            inorder(*root);
            printf("\n");

            /* Parent BLACK */
            if (parentNode->color == BLACK)
            {
                printf("Now Tree is Balance\n");
                inorder(*root);
                printf("\n");
            }
            else
            {
                if (fix_insertion(root, newNode) != SUCCESS)
                    return FAILURE;

                printf("Now Tree is Balance\n");
                inorder(*root);
                printf("\n");
            }
        }

        printf("\nDo you want to continue (Y/N) : ");
        scanf(" %c", &choice);

    } while (choice != 'N' && choice != 'n');

    return SUCCESS;
}