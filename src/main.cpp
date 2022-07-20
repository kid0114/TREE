#include "iostream"
#include "queue"
#include "treenode.h"
#include "BST.h"
#include "AVLtree.h"
#include "node.h"
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

int main() {

    int a[] = {12, 13, 55, 66, 44, 77, 99, 33, 46, 79};
    int b[] = {1, 2, 3, 4, 5, 6, 12};
    cout << "AVL:\n";
    AVLtree *avl = new AVLtree(b, 6);
    avl->AVLroot->check_tree();


    avl->AVLfree();
    cout << "\n";

    cout << "BST:\n";

    BST *bst = new BST(a, 10);

    bst->BSTroot->check_tree();
    bst->BSTfree();

    /*
     *
     *
     *
     *
     *
     */

    return 0;
}
