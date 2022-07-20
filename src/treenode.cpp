//
// Created by kid on 7/13/22.
//

#include "treenode.h"
#include "queue"
#include "iostream"
#include "queue"
#include "node.h"

using namespace std;

void freeTree(node *head) {
    if (head == nullptr)return;
    if (head->l)freeTree(head->l);
    if (head->r)freeTree(head->r);
    delete head;
}

// front
void treenode::check_front(node *head) {
    cout << head->val << " ";
    if (head->l)check_front(head->l);
    if (head->r)check_front(head->r);
}

//middle
void treenode::check_mid(node *head) {
    if (head->l)check_mid(head->l);
    cout << head->val << " ";
    if (head->r)check_mid(head->r);
}

//back
void treenode::check_back(node *head) {
    if (head->l)check_back(head->l);
    if (head->r)check_back(head->r);
    cout << head->val << " ";
}

//level
void treenode::check_level(node *head) {
    queue<node *> q;
    node *t = head;
    q.push(t);
    while (!q.empty()) {
        node *t = q.front();
        q.pop();
        cout << t->val << " ";
        if (t->l)q.push(t->l);
        if (t->r)q.push(t->r);
    }
    cout << "\n";
}

node *createTree_level(int a[], int size, int &t) {
    queue<node *> q;
    node *root = new node(a[t++]);
    q.push(root);
    while (t < size) {
        node *x = q.front();
        q.pop();
        if (t < size) {
            x->l = new node(a[t++]);
            q.push(x->l);
        }
        if (t < size) {
            x->r = new node(a[t++]);
            q.push(x->r);
        }
    }
    return root;
}

void node_swap(node *a, node *b) {
    int t = a->val;
    a->val = b->val;
    b->val = t;
}