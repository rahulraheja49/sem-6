#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    int c;
    struct node* p;
    struct node* r;
    struct node* l;
};

struct node* root = NULL;
struct node* t1 = NULL;
struct node* t2 = NULL;

struct node* bst(struct node* trav, struct node* temp) {
    if (trav == NULL) return temp;

    if (temp->d < trav->d) {
        trav->l = bst(trav->l, temp);
        trav->l->p = trav;
    } else if (temp->d > trav->d) {
        trav->r = bst(trav->r, temp);
        trav->r->p = trav;
    }
    return trav;
}

void rightrotate(struct node* temp) {
    struct node* left = temp->l;
    temp->l = left->r;
    if (temp->l) temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p) root = left;
    else if (temp->p->l == temp) temp->p->l = left;
    else temp->p->r = left;
    left->r = temp;
    temp->p = left;
}

void leftrotate(struct node* temp) {
    struct node* right = temp->r;
    temp->r = right->l;
    if (temp->r) temp->r->p = temp; // if newnode has left child, give it to temp's right
    right->p = temp->p; // mark newnodes parent as curr grandparent
    if (!temp->p) root = right; // if temp is root
    else if (temp == temp->p->l) temp->p->l = right; // if temp is left child
    else temp->p->r = right; // if temp is right child
    right->l = temp;
    temp->p = right;
}

void fixup(struct node* root, struct node* pt) {
    struct node* parent_pt = NULL;
    struct node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->c != 0) && (pt->p->c == 1)){ // point not root yet, point not black yet, point's parent not red
        parent_pt = pt->p;
        grand_parent_pt = pt->p->p;

        //  parent pt is left child of grandparent
        if (parent_pt == grand_parent_pt->l) {
            struct node* uncle_pt = grand_parent_pt->r;

            // uncle is also red
            if (uncle_pt != NULL && uncle_pt->c == 1) {
                grand_parent_pt->c = 1;
                parent_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_parent_pt;
            } else { // uncle black
                if (parent_pt->r == pt) { // point is right child of parent 
                    // left right
                    leftrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->p;
                } // left left
                rightrotate(grand_parent_pt);
                int t = parent_pt->c;
                parent_pt->c = grand_parent_pt->c;
                grand_parent_pt->c = t;
                pt = parent_pt;
            }
        } else {
            struct node* uncle_pt = grand_parent_pt->r;
            
            if ((uncle_pt != NULL) && uncle_pt->c == 1){
                grand_parent_pt->c = 1;
                parent_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->l) {
                    rightrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->p;
                }
                leftrotate(grand_parent_pt);
                int t = parent_pt->c;
                parent_pt->c = grand_parent_pt->c;
                grand_parent_pt->c = t;
                pt = parent_pt;
            }
        }
    }
    root->c = 0;
}

void inorder(struct node* trav) {
    if (trav == NULL) return;
    inorder(trav->l);
    printf("%d ", trav->d);
    inorder(trav->r);
}

int main() {
    int input = 0;

    while (1) {
        printf("Enter value to insert or -1 to exit: ");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        struct node* temp = (struct node*) malloc(sizeof(struct node));
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->d = input;
        temp->c = 1;
        root = bst(root, temp);
        fixup(root, temp);
        inorder(root);
        printf("\n\n");
    }

    printf("Inorder Traversal of Created Tree\n");
    inorder(root);
    printf("\n\n");

    return 0;
}




/*
        10
    5         15
3                   16

*/