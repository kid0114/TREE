//
// Created by kid on 7/14/22.
//
#include "iostream"
#include "BST.h"

node *BSTinsert(node *root, int x) {
    if (root == nullptr) {
        return new node(x);
    }
    if (x == root->val)return root;
    //左边小右边大
    if (x < root->val) {
        root->l = BSTinsert(root->l, x);
    } else {
        root->r = BSTinsert(root->r, x);
    }
    return root;
}

node *BSTfind(node *root, int x) {
    if (root == nullptr)return nullptr;
    if (x == root->val)return root;
    if (x < root->val)return BSTfind(root->l, x);
    else return BSTfind(root->r, x);
}

void BST::BSTcreate(int a[], int n) {
    for (int i = 0; i < n; i++) {
        BSTroot->root = BSTinsert(BSTroot->root, a[i]);
    }
}

node *BSTfindmax(node *head) {
    if (head->r)return BSTfindmax(head->r);
    else return head;
}

node *BSTdeletemax(node *head) {
    if (head->r) {
        head->r = BSTdeletemax(head->r);
        return head;
    } else {
        node *t = head->l;
        delete head;
        return t;
    }

}

node *BSTfindmin(node *head) {
    if (head->l)return BSTfindmin(head->l);
    else return head;
}

node *BSTfind_father(node *head, int x) {
    if (head == nullptr)return nullptr;
    if (head->val == x)return nullptr;
    return father(head, x);
}

node *father(node *head, int x) {
    if (head->l) {
        if (head->l->val == x)return head->l;
        else return father(head->l, x);
    }
    if (head->r) {
        if (head->r->val == x)return head->r;
        else return father(head->r, x);
    }
    return nullptr;
}

node *BSTdelete(node *head, int x) {
    node *tx = BSTfind(head, x);
    if (tx != nullptr) {
        if (tx->l == nullptr) {
            delete tx;
        } else if (head->r == nullptr) {
            delete tx;
        } else {
            node *t = BSTfindmax(tx->l);
            node_swap(tx, t);
            tx->l = BSTdeletemax(tx->l);
        }
    }
    return head;

}
