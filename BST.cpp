#include <iostream>
using namespace std;

struct Tree {
    int data;
    Tree *LC, *RC;
};

Tree *root = NULL;

void insert_node(int v);
void search_node(Tree *root, Tree *nn);
void pre_order(Tree *root);
void post_order(Tree *root);
void IN_order(Tree *root);

void insert_node(int v) {
    Tree *nn = new Tree;
    nn->data = v;
    nn->LC = NULL;
    nn->RC = NULL;

    if (root == NULL) {
        root = nn;
    } else {
        search_node(root, nn);
    }
}

void search_node(Tree *root, Tree *nn) {
    if (nn->data < root->data) {
        if (root->LC == NULL)
            root->LC = nn;
        else
            search_node(root->LC, nn);
    } else if (nn->data > root->data) {
        if (root->RC == NULL)
            root->RC = nn;
        else
            search_node(root->RC, nn);
    }
}

void pre_order(Tree *root) {
    if (root == NULL)
        return;
    cout << root->data << "->";
    pre_order(root->LC);
    pre_order(root->RC);
}

void post_order(Tree *root) {
    if (root == NULL)
        return;
    post_order(root->LC);
    post_order(root->RC);
    cout << root->data << "->";
}

void IN_order(Tree *root) {
    if (root == NULL)
        return;
    IN_order(root->LC);
    cout << root->data << "->";
    IN_order(root->RC);
}

int main() {
    insert_node(80);
    insert_node(75);
    insert_node(65);
    insert_node(76);
    insert_node(85);
    insert_node(83);
    insert_node(90);

    cout << "PRE ORDER: ";
    pre_order(root);
    cout << endl;

    cout << "POST ORDER: ";
    post_order(root);
    cout << endl;

    cout << "IN ORDER: ";
    IN_order(root);
    cout << endl;

    return 0;
}