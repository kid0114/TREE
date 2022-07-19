cmake_minimum_required(VERSION 3.22)
project(tree)
set(CMAKE_CXX_STANDARD 14)

add_executable(tree main.cpp treenode.cpp treenode.h BST.cpp BST.h AVLtree.cpp AVLtree.h RBtree.cpp RBtree.h)
