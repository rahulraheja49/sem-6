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

struct node* fixup(struct node* root, struct node* temp) {
    if (temp->p->c == 1) {          //parent red
        if (temp->p->p->l == temp->p) {   //left child temp's parent
            if (temp->p->p->r->c == 1 && temp->p->p->r->r->c == 0 && temp->p->p->r->l->c == 0) {    // uncle red and his children are black      
                temp->p->p->r->c = 0;
                temp->p->p->l->c = 0;
                if (temp->p->p != root){
                    temp->p->p->c = 1;
                }
                return root;
            } else {
                if (temp->p->l == temp && temp->p->p->l == temp->p) {   // left left
                    t1 = temp->p->r;
                    t2 = temp->p->p;
                    temp->p->p = temp->p->p->p;
                    temp->p->r = t2;
                    t2->c = 1;
                    temp->p->c = 0;
                    t2->l = t1;
                    temp->p->p->l = temp->p;
                } else { // left right
                    temp->p->p->l = temp;
                    temp->l = temp->p;
                    t1 = temp->p;
                    temp->p = temp->p->p;
                    t1->p = temp;
                    // left left again
                    t1 = temp->p->r;
                    t2 = temp->p->p;
                    temp->p->p = temp->p->p->p;
                    temp->p->r = t2;
                    t2->c = 1;
                    temp->p->c = 0;
                    t2->l = t1;
                    temp->p->p->l = temp->p;
                }
            }
        } else { //right child temp's parent
            if (temp->p->p->l->c == 1 && temp->p->p->l->r->c == 0 && temp->p->p->l->l->c == 0) {    // uncle red and his children are black      
                temp->p->p->r->c = 0;
                temp->p->p->l->c = 0;
                if (temp->p->p != root){
                    temp->p->p->c = 1;
                }
                return root;
            } else {
                if (temp->p->r == temp && temp->p->p->r == temp->p) {   // right right
                    t1 = temp->p->l;
                    t2 = temp->p->p;
                    temp->p->p = temp->p->p->p;
                    temp->p->l = t2;
                    t2->c = 1;
                    temp->p->c = 0;
                    t2->r = t1;
                    temp->p->p->r = temp->p;
                } else { // right left
                    temp->p->p->l = temp;
                    temp->l = temp->p;
                    t1 = temp->p;
                    temp->p = temp->p->p;
                    t1->p = temp;
                    // right right again
                    t1 = temp->p->r;
                    t2 = temp->p->p;
                    temp->p->p = temp->p->p->p;
                    temp->p->r = t2;
                    t2->c = 1;
                    temp->p->c = 0;
                    t2->l = t1;
                    temp->p->p->r = temp->p;
                }
            }
        }
    }
    root->c = 0;
    return root;
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
        if (root == NULL) {
            root = temp;
            return root;
        }
        fixup(root, temp);
        inorder(root);
    }

    printf("Inorder Traversal of Created Tree\n");
    inorder(root);

    return 0;
}




/*
        10
    5         15
3                   16

*/