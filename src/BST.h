//
// Created by kid on 7/14/22.
//

#ifndef TREE_BST_H
#define TREE_BST_H

#include "treenode.h"
#include "node.h"

class BST {
public:
    treenode *BSTroot;

    //node* BSTinsert(node* root, int x);
    BST(int a[], int n) {
        BSTroot = new treenode();
        BSTroot->root = nullptr;
        BSTcreate(a, n);
    }

    void BSTcreate(int a[], int n);

    void BSTfree() {
        freeTree(BSTroot->root);
    }

};

node *BSTfind(node *root, int x);

node *BSTfind_father(node *head, int x);

node *father(node *head, int x);

node *BSTdelete(node *head, int x);

node *BSTfindmax(node *head);

node *BSTdeletemax(node *head);

node *BSTfindmin(node *head);

#endif //TREE_BST_H
