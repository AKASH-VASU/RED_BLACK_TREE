#include "red_black.h"


RB_Node *NIL = NULL;

int main()
{
    RB_Node *root = NULL;

    NIL = (RB_Node *)malloc(sizeof(RB_Node));

    if (NIL == NULL)
    {
        printf("Memory Allocation Failed\n");
        return FAILURE;
    }

    NIL->color = BLACK;
    NIL->left_subtree = NIL;
    NIL->right_subtree = NIL;
    NIL->parent = NIL;

    root = NIL;

    int option;

    do
    {
        printf("\n-: MAIN MENU :-\n");
        printf("1. Create a tree\n");
        printf("2. Display\n");
        printf("3. Search a node\n");
        printf("4. Find Maximum node in Tree\n");
        printf("5. Find Minimum node in Tree\n");
        printf("6. Deletion\n");
        printf("7. Delete Minimum node\n");
        printf("8. Delete Maximum node\n");
        printf("9. Exit\n");

        printf("\nEnter the Choice : ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                if (create_tree(&root) == SUCCESS)
                {
                    printf("INFO : SUCCESS : Tree Created !!\n");
                }
                else
                {
                    printf("INFO : FAILURE : Tree Not Created !!\n");
                }
                break;
            }

            case 2:
            {
                printf("\nDisplay : ");
                inorder(root);
                printf("%d -> root \n",root->data);
                printf("\n");
                break;
            }

            case 3:
            {
                search(root);
                break;
            }

            case 4:
            {
                RB_Node *max = find_max(root);

                if (max != NIL)
                {
                    printf("Maximum Node : %d (%s -> %d)\n",
                           max->data,
                           (max->color == RED) ? "RED" : "BLACK",
                           max->color);
                }
                else
                {
                    printf("INFO : Tree is Empty\n");
                }

                break;
            }

            case 5:
            {
                RB_Node *min = find_min(root);

                if (min != NIL)
                {
                    printf("Minimum Node : %d (%s -> %d)\n",
                           min->data,
                           (min->color == RED) ? "RED" : "BLACK",
                           min->color);
                }
                else
                {
                    printf("INFO : Tree is Empty\n");
                }

                break;
            }

            case 6:
            {
                if (delete_node(&root) == SUCCESS)
                {
                    printf("Node deleted successfully.\n");

                    printf("\nCurrent Red-Black Tree:\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("Node not found.\n");
                }

                break;
            }

            case 7:
            {
                if (delete_min(&root) == SUCCESS)
                {
                    printf("INFO : SUCCESS : Minimum node deleted successfully.\n");

                    printf("\nCurrent Red-Black Tree:\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("INFO : FAILURE : Tree is Empty.\n");
                }

                break;
            }

            case 8:
            {
                if (delete_max(&root) == SUCCESS)
                {
                    printf("INFO : SUCCESS : Maximum node deleted successfully.\n");

                    printf("\nCurrent Red-Black Tree:\n");
                    inorder(root);
                    printf("\n");
                }
                else
                {
                    printf("INFO : FAILURE : Tree is Empty.\n");
                }

                break;
            }

            case 9:
            {
                printf("Exiting...\n");

                free(NIL);

                return SUCCESS;
            }

            default:
            {
                printf("INFO : Invalid Option\n");
                break;
            }
        }

    } while (1);

    return SUCCESS;
}