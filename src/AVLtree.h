//
// Created by kid on 7/18/22.
//

#ifndef TREE_AVLTREE_H
#define TREE_AVLTREE_H
#include "treenode.h"
#include "BST.h"
class AVLtree: treenode{
public:
    void AVLfree(){
        freeTree(this);
    }

};
treenode* AVLtreeInsert(treenode* root, int v);
treenode* AVLtreeCreate(int a[], int n);


//balance
treenode* AVLBalance(treenode* root);
treenode* AVL_LL(treenode* root);
treenode* AVL_RR(treenode* root);

treenode* AVL_LR(treenode* root);
treenode* AVL_RL(treenode* root);

int getdepth(treenode* root);
int getbalance(treenode* root);
#endif //TREE_AVLTREE_H
