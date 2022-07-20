//
// Created by kid on 7/18/22.
//

#include "AVLtree.h"
#include "iostream"
#include "BST.h"
#include "node.h"

using namespace std;
//init

node *AVL_LL(node *root);

node *AVL_RR(node *root);

node *AVL_LR(node *root);

node *AVL_RL(node *root);

node *AVLtreeInsert(node *root, int v) {
    if (root == nullptr) {
        root = new node(v);
    } else if (root->val > v) {
        root->l = AVLtreeInsert(root->l, v);
        root = AVLBalance(root);
    } else if (root->val < v) {
        root->r = AVLtreeInsert(root->r, v);
        root = AVLBalance(root);
    }
    return root;

}


node *AVLtreeCreate(int a[], int n) {
    node *head = nullptr;
    for (int i = 0; i < n; i++) {
        head = AVLtreeInsert(head, a[i]);
    }
    return head;
}


//balance
node *AVLBalance(node *root) {
    int balance = getbalance(root);
    if (balance > 1) {
        if (getbalance(root->l) > 0) {
            root = AVL_LL(root);
        } else {
            root = AVL_LR(root);
        }
    } else if (balance < -1) {
        if (getbalance(root->r) < 0) {
            root = AVL_RR(root);
        } else {
            root = AVL_RL(root);
        }
    }
    return root;

}

node *AVL_LL(node *root) {
    node *t = root->l;//left son -> father change left to right
    root->l = t->r;
    t->r = root;
    return t;
}

node *AVL_RR(node *root) {
    node *t = root->r;//right son -> father change right to left
    root->r = t->l;
    t->l = root;
    return t;
}

node *AVL_LR(node *root) {//LL+RR-->RR+LL
    node *t = root->l;//left son -> father
    root->l = AVL_RR(t);
    return AVL_LL(root);
}

node *AVL_RL(node *root) {
    node *t = root->r;//left son -> father
    root->r = AVL_LL(t);
    return AVL_RR(root);
}

int getdepth(node *root) {
    if (root == nullptr)return 0;
    return max(getdepth(root->l), getdepth(root->r)) + 1;
}

int getbalance(node *root) {
    return getdepth(root->l) - getdepth(root->r);
}


