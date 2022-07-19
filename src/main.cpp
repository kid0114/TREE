#include "iostream"
#include "queue"
#include "treenode.h"
#include "BST.h"
#include "AVLtree.h"
using namespace std;



/*
 * 1
 * 23
 * 4567
 *      1
 *     2 3
 *   4 5 6 7
 *
 * 1 2 3 4 5 6 7
 * 4 5 2 1 5 7 3
 *
 *        1
 *    2     3
 *  4  5   6
 *    7 8


 */

/*
 *    2
 *  1   4
 *   7  3  6
 *  5
 */
void check_tree(treenode* head){
    cout<<"level: ";
    check_level(head);
    cout<<"front: ";
    check_front(head);
    cout<<"\n";
    cout<<"middle: ";
    check_mid(head);
    cout<<"\n";
    cout<<"back: ";
    check_back(head);
    cout<<"\n";
}
int main() {

    int a[] = {12, 13, 55, 66, 44, 77, 99,33,46,79};
    int b[] = {6, 7, 8, 9, 10, 11, 12};
    treenode *head= AVLtreeCreate(b,6);
    check_tree(head);
    freeTree(head);
    /*
    BST *bst = new BST();
    treenode *head = bst->BSTcreate(a, 10);
    int t = 0;
    //treenode *head= createTree_level(a, 7, t);
    check_tree(head);

    treenode *x=BSTfind(head,5);
    cout<<x->val<<" "<<x->l->val<<"\n";
    bst->BSTdelete_x(head,5);
    check_tree(head);
    bst->BSTfree();
     */

    return 0;
}
