//
// Created by kid on 7/18/22.
//

#ifndef TREE_AVLTREE_H
#define TREE_AVLTREE_H

#include "treenode.h"
#include "BST.h"

node *AVLtreeInsert(node *root, int v);

node *AVLBalance(node *root);

//treenode* AVLBalanceAll(treenode* root);
node *AVLtreeCreate(int a[], int n);

node *AVLtreeDelete(node *root, int x);

class AVLtree {


public:
    treenode *AVLroot;

    void AVLfree() {
        freeTree(AVLroot->root);
    }

    AVLtree(int a[], int n) {
        AVLroot = new treenode();
        AVLroot->root = AVLtreeCreate(a, n);
    }

    void insert(int x) {
        AVLroot->root = AVLtreeInsert(AVLroot->root, x);
    }

    //balance
    treenode *getAVLroot() {
        return AVLroot;
    }

};

int getdepth(node *root);

int getbalance(node *root);

#endif //TREE_AVLTREE_H
