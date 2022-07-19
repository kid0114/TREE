//
// Created by kid on 7/13/22.
//

#include "treenode.h"
#include "queue"
#include "iostream"
using namespace std;
void freeTree(treenode* head){
    if(head== nullptr)return;
    if(head->l)freeTree(head->l);
    if(head->r)freeTree(head->r);
    delete head;
}
// front
void check_front(treenode *head){
    cout<<head->val<<" ";
    if(head->l)check_front(head->l);
    if(head->r)check_front(head->r);
}
//middle
void check_mid(treenode *head){
    if(head->l)check_mid(head->l);
    cout<<head->val<<" ";
    if(head->r)check_mid(head->r);
}
//back
void check_back(treenode *head){
    if(head->l)check_back(head->l);
    if(head->r)check_back(head->r);
    cout<<head->val<<" ";
}
//level
void check_level(treenode *head){
    queue<treenode*> q;
    treenode* t=head;
    q.push(t);
    while(!q.empty()){
        treenode *t=q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->l)q.push(t->l);
        if(t->r)q.push(t->r);
    }
    cout<<"\n";
}
treenode *createTree_level(int a[], int size, int &t){
    queue<treenode*> q;
    treenode *root=new treenode(a[t++]);
    q.push(root);
    while(t<size){
        treenode* x=q.front();
        q.pop();
        if(t<size){
            x->l=new treenode(a[t++]);
            q.push(x->l);
        }
        if(t<size){
            x->r=new treenode(a[t++]);
            q.push(x->r);
        }
    }
    return root;
}
int find_depth(treenode* head,int &x,int &t){
    if(head== nullptr)return t=max(t,x);
    if(head->l!= nullptr)return find_depth(head,x,t);
    if(head->r!= nullptr)return find_depth(head,x,t);
}
void treenode_swap(treenode* a,treenode *b){
    int t=a->val;
    a->val=b->val;
    b->val=t;
}