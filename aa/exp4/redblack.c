#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    struct node *par;
    struct node *left;
    struct node *right;
    int data;
    int color;
};

struct node *temp = NULL, *newnode, *root = NULL, *par = NULL, *grpar = NULL;

int balance(struct node *nodeptr) {
    if(nodeptr->par->color == 1 && nodeptr->color == 1){
        if(nodeptr->par->par->right->color == 1 && nodeptr->par->par->left->color == 1){
            nodeptr->par->par->right->color == 0;
            nodeptr->par->par->left->color == 0;
            nodeptr->par->par->color == 1;
            return 0;
        } else if((nodeptr->par->par->right->color == 0 && nodeptr->par->par->left->color == 1) || (nodeptr->par->par->right->color == 1 && nodeptr->par->par->left->color == 0)){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void traversal(struct node *temp) {
    if (temp != NULL) {
        traversal(temp->left);
        printf("%d    ", temp->data);
        traversal(temp->right);
    }
}

void insert() {
    int val, res;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->color = 1;
    if(root == NULL){
        new_node->color = 0;
        root = new_node;
        new_node->par = NULL;
    } else {
        temp = root;
        par = temp;
        grpar = par;
        while (temp != NULL) {
            grpar = par;
            par = temp;
            if (temp->data > val){
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        new_node->par = par;
        if (val < par->data) {
            par->left = new_node;
        } else {
            par->right = new_node;
        }
        new_node->left = NULL;
        new_node->right = NULL;
        res = balance(new_node);
        printf("%d inserted.\n", val);
    }
}

void main() {
    int choice = 0;
    while(choice!=-1) {
        scanf("%d", &choice);
        if(choice == 1){
            insert();
        } else if (choice == 2) {
            traversal(root);
        } else if (choice == -1) {
            break;
        } else {
            continue;
        }
    }
}


/*
if(grpar->right->color == 1 && grpar->left->color == 1){
    grpar->right->color = 0;
    grpar->left->color = 0;
    grpar->color = 1;
    if(grpar->par->color == 1){

    }
}
*/