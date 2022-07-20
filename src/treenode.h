//
// Created by kid on 7/13/22.
//

#ifndef TREE_TREENODE_H
#define TREE_TREENODE_H

#include "iostream"
#include "node.h"

using namespace std;

class treenode {
protected:
    void check_front(node *head);

    void check_mid(node *head);

    void check_back(node *head);

    void check_level(node *head);

public:
    node *root;

    treenode() {
        root = nullptr;
    }

    //check ways
    void check_tree() {
        cout << "level: ";
        check_level(root);
        cout << "front: ";
        check_front(root);
        cout << "\n";
        cout << "middle: ";
        check_mid(root);
        cout << "\n";
        cout << "back: ";
        check_back(root);
        cout << "\n";
    }
};

node *createTree_level(int a[], int size, int &t);

void freeTree(node *head);


//find node
treenode *find_x_d(treenode *head, int x);

treenode *find_x_b(treenode *head, int x);

//treenode* find_father(treenode* head,int x);
int find_depth(treenode *head, int &x);

//swap val
void node_swap(node *a, node *b);

#endif //TREE_TREENODE_H
