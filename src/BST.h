//
// Created by kid on 7/14/22.
//

#ifndef TREE_BST_H
#define TREE_BST_H

#include "treenode.h"

class BST:treenode{
public:
    treenode* BSTinsert(treenode* root, int x);
    treenode* BSTcreate(int a[],int n);
    void BSTfree(){
        freeTree(this);
    }
    treenode* BSTdelete_x(treenode* head,int x);
};
treenode* BSTfind(treenode* root,int x);
treenode* BSTfind_father(treenode* head,int x);
treenode* father(treenode* head,int x);
treenode* BSTfindmax(treenode *head);
treenode* BSTdeletemax(treenode *head);
treenode* BSTfindmin(treenode *head);
#endif //TREE_BST_H
