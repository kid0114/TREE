//
// Created by kid on 7/18/22.
//

#include "AVLtree.h"
#include "iostream"
using namespace std;
treenode* AVLtreeInsert(treenode* root, int v){
    if(root== nullptr){
        root= new treenode(v);
    }else if(root->val>v){
        root->l= AVLtreeInsert(root->l,v);
        root= AVLBalance(root);
    }else if(root->val<v){
        root->r= AVLtreeInsert(root->r,v);
        root= AVLBalance(root);
    }
    return root;
}
treenode* AVLtreeCreate(int a[], int n){
    treenode *head= nullptr;
    for(int i=0;i<n;i++){
        head= AVLtreeInsert(head, a[i]);
    }
    return head;
}


//balance
treenode* AVLBalance(treenode* root){
    int balance= getbalance(root);
    if(balance>1){
        if(getbalance(root->l)>0){
            root= AVL_LL(root);
        }else{
            root= AVL_LR(root);
        }
    }else if(balance<-1){
        if(getbalance(root->r)<0){
            root= AVL_RR(root);
        }else{
            root= AVL_RL(root);
        }
    }
    return root;

}
treenode* AVL_LL(treenode* root){
    treenode *t=root->l;//left son -> father change left to right
    root->l=t->r;
    t->r=root;
    return t;
}
treenode* AVL_RR(treenode* root){
    treenode *t=root->r;//right son -> father change right to left
    root->r=t->l;
    t->l=root;
    return t;
}

treenode* AVL_LR(treenode* root){//LL+RR-->RR+LL
    treenode *t=root->l;//left son -> father
    root->l= AVL_RR(t);
    return AVL_LL(root);
}
treenode* AVL_RL(treenode* root){
    treenode *t=root->r;//left son -> father
    root->r= AVL_LL(t);
    return AVL_RR(root);
}

int getdepth(treenode* root){
    if(root== nullptr)return 0;
    return max(getdepth(root->l), getdepth(root->r))+1;
}
int getbalance(treenode* root){
    return getdepth(root->l)- getdepth(root->r);
}