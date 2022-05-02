#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *temp = NULL, *newnode, *root = NULL, *par = NULL;

void traversal(int choice, struct node *temp)
{
    if (choice == 1)
    {
        if (temp != NULL)
        {
            traversal(1, temp->left);
            printf("%d    ", temp->data);
            traversal(1, temp->right);
        }
    }
    else if (choice == 2)
    {
        if (temp != NULL)
        {
            printf("%d    ", temp->data);
            traversal(2, temp->left);
            traversal(2, temp->right);
        }
    }
    else
    {
        if (temp != NULL)
        {
            traversal(3, temp->left);
            traversal(3, temp->right);
            printf("%d    ", temp->data);
        }
    }
}

void create()
{
    int n, counter, val;
    printf("Creation of the BST structure: \n");
    printf(" Enter the number of nodes: ");
    scanf(" %d", &n);
    counter = n - 1;
    //ROOT NODE
    newnode = (struct node *)malloc(sizeof(struct node));
    printf(" Enter the value: ");
    scanf(" %d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    root = newnode;
    //OTHER NODES
    while (counter >= 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf(" Enter the value: ");
        scanf(" %d", &val);
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        temp = root;

        while (temp != NULL)
        {
            par = temp;
            if (temp->data > val)
                temp = temp->left;

            else
                temp = temp->right;
        }

        if (val > par->data)
            par->right = newnode;

        else
            par->left = newnode;

        counter--;
    }
}

void insert()
{
    int val;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    new_node->data = val;
    temp = root;
    par = temp;
    while (temp != NULL)
    {
        par = temp;
        if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (val < par->data)
    {
        par->left = new_node;
        new_node->left = NULL;
        new_node->right = NULL;
        printf("%d inserted.\n", val);
    }
    else
    {
        par->right = new_node;
        new_node->left = NULL;
        new_node->right = NULL;
        printf("%d inserted.\n", val);
    }
}

void delete ()
{
    int val;
    struct node *remove, *parent;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    temp = root;
    par = temp;
    while (temp->data != val)
    {
        par = temp;
        if (temp->data > val)
        {
            temp = temp->left;
        }
        else if (temp->data < val)
        {
            temp = temp->right;
        }
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == par->left)
        {
            par->left = NULL;
        }
        else
        {
            par->right = NULL;
        }
        printf("%d deleted\n", val);
        free(temp);
    }
    else if (temp->left == NULL && temp->right != NULL)
    {
        if (root->data == val)
        {
            temp = root;
            root = root->right;
        }
        else
        {
            if (temp == par->left)
            {
                par->left = temp->right;
            }
            else
            {
                par->right = temp->right;
            }
        }
        printf("%d deleted\n", val);
        free(temp);
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        if (root->data == val)
        {
            temp = root;
            root = root->left;
        }
        else
        {
            if (temp == par->left)
            {
                par->left = temp->left;
            }
            else
            {
                par->right = temp->left;
            }
        }
        printf("%d deleted\n", val);
        free(temp);
    }
    else
    {
        remove = temp;
        parent = remove;
        remove = remove->left;
        if (remove->right == NULL)
        {
            temp->data = remove->data;
            temp->left = NULL;
        }
        else
        {
            while (remove->right != NULL)
            {
                parent = remove;
                remove = remove->right;
            }
            temp->data = remove->data;
            parent->right = NULL;
        }
        printf("%d deleted\n", val);
        free(remove);
    }
}

void main()
{
    int choice = 1;
    create();
    while (choice != 0)
    {
        printf(" Traversal \n  1 - Inorder\n  2 - Preorder\n  3 - Postorder\n 4 - Delete \n 5 - Insert \n 0 - Exit\n Enter your choice: ");
        scanf("%d", &choice);
        printf(" ");
        switch (choice)
        {
        case 1:
            traversal(1, root);
            printf("\n");
            break;
        case 2:
            traversal(2, root);
            printf("\n");
            break;
        case 3:
            traversal(3, root);
            printf("\n");
            break;
        case 4:
            delete ();
            break;
        case 5:
            insert();
            break;

        default:
            break;
        }
    }
}