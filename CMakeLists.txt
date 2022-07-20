cmake_minimum_required(VERSION 3.22)
project(TREE)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TREE
        src/AVLtree.cpp
        src/AVLtree.h
        src/BST.cpp
        src/BST.h
        src/main.cpp
        src/RBtree.cpp
        src/RBtree.h
        src/treenode.cpp
        src/treenode.h src/node.cpp src/node.h)
