//
// Created by kid on 7/18/22.
//

#ifndef TREE_RBTREE_H
#define TREE_RBTREE_H
#include "treenode.h"

class RBtree : treenode {
private:
    int color;
public:
    RBtree(int color) {
        color = 0;//0 black 1 red
    }

    int getcolor() {
        return color;
    }

    void changecolor(int v) {
        color = v;
    }
};


#endif //TREE_RBTREE_H
