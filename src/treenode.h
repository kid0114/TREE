//
// Created by kid on 7/13/22.
//

#ifndef TREE_TREENODE_H
#define TREE_TREENODE_H


class treenode{
public:
    int val;
    treenode *l;
    treenode *r;
    treenode(int x){
        val=x;
        l= nullptr;
        r= nullptr;
    }
    treenode(){
        val=0;
        l= nullptr;
        r= nullptr;
    }


};
treenode *createTree_level(int a[], int size, int &t);
void freeTree(treenode* head);

//check ways
void check_front(treenode* head);
void check_mid(treenode *head);
void check_back(treenode *head);
void check_level(treenode *head);

//find node
treenode* find_x_d(treenode* head,int x);
treenode* find_x_b(treenode* head,int x);
//treenode* find_father(treenode* head,int x);
int find_depth(treenode* head,int &x);
//swap val
void treenode_swap(treenode* a,treenode *b);

#endif //TREE_TREENODE_H
