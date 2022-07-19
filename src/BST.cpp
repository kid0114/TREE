//
// Created by kid on 7/14/22.
//
#include "iostream"
#include "BST.h"
treenode* BST::BSTinsert(treenode* root, int x){
    if(root == nullptr){
        return new treenode(x);
    }
    if(x==root->val)return root;
    //左边小右边大
    if(x<root->val){
        root->l= BSTinsert(root->l,x);
    }else{
        root->r= BSTinsert(root->r,x);
    }
    return root;
}
treenode* BSTfind(treenode* root,int x){
    if(root== nullptr)return nullptr;
    if(x==root->val)return root;
    if(x<root->val)return BSTfind(root->l,x);
    else return BSTfind(root->r,x);
}
treenode* BST::BSTcreate(int a[],int n){
    treenode *head= nullptr;
    for(int i=0;i<n;i++){
        head=BSTinsert(head,a[i]);
    }
    return head;
}
treenode* BSTfindmax(treenode *head){
    if(head->r)return BSTfindmax(head->r);
    else return head;
}
treenode* BSTdeletemax(treenode *head){
    if(head->r){
        head->r=BSTdeletemax(head->r);
        return head;
    }else{
        treenode* t = head->l;
        delete head;
        return t;
    }

}
treenode* BSTfindmin(treenode *head){
    if(head->l)return BSTfindmin(head->l);
    else return head;
}
treenode* BST::BSTdelete_x(treenode* head,int x){
    if(head== nullptr)return nullptr;
    if(x<head->val){
        head->l= BSTdelete_x(head->l,x);
        return head;
    }else if(x>head->val){
        head->r= BSTdelete_x(head->r,x);
        return head;
    }else{
        if(head->l== nullptr){
            delete head;
            return head->r;
        }else if(head->r== nullptr){
            delete head;
            return head->l;
        }else {
            treenode* t= BSTfindmax(head->l);
            treenode_swap(head,t);
            head->l=BSTdeletemax(head->l);
            return head;
        }

    }
}
treenode* BSTfind_father(treenode* head,int x){
    if(head==nullptr)return nullptr;
    if(head->val==x)return nullptr;
    return father(head,x);
}
treenode* father(treenode* head,int x){
    if(head->l){
        if(head->l->val==x)return head->l;
        else return father(head->l,x);
    }
    if(head->r){
        if(head->r->val==x)return head->r;
        else return father(head->r,x);
    }
    return nullptr;
}