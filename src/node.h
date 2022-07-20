//
// Created by kid on 7/20/22.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H


class node {
public:
    int val;
    node *l;
    node *r;

    node(int x) {
        val = x;
        l = nullptr;
        r = nullptr;
    }

    node() {
        val = 0;
        l = nullptr;
        r = nullptr;
    }
};


#endif //TREE_NODE_H
