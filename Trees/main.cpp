//
//  main.cpp
//  Trees
//
//  Created by Nitin K on 3/1/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <iostream>
#include "BinaryTree.cpp"
#include "BSTree.cpp"
#include "AVLTree.cpp"
#include "Heap.cpp"
#include <queue>
using namespace std;

// ***** PROTOTYPES ***** //
void testBinaryTree();
void testBSTree();
void testAVLTree();
void testHeap();

// ***** MAIN ***** //
int main()
{
//    testBinaryTree();
//    testBSTree();
//    testAVLTree();
    
    return 0;
}

// ***** FUNCTION DEFINITIONS ***** //
void testBinaryTree()
{
    BinaryTree BT;
    BT.insert(3);  // root
    BT.insert(5);  // root->left
    BT.insert(7);  // root->right
    BT.insert(9);  // root->left->left
    BT.insert(11); // root->left->right
    BT.insert(13); // root->right->left
    BT.insert(15); // root->right->right
    
    //    BT.autoFill(10);
    
    BT.printRoot();
    BT.printLevelOrder();
    BT.printPreOrder();
    BT.printInOrder();
    BT.printPostOrder();
    BT.numberOfLevels();
    BT.numberOfNodes();
    BT.isBalanced();
    
    BT.search(1);
    BT.search(3);
    BT.search(5);
    BT.search(7);
    BT.search(9);
    BT.search(11);
    BT.search(13);
    BT.search(15);
    BT.search(17);
}

void testBSTree()
{
    BSTree BST;
    
    BST.insert(8);
    BST.insert(3);
    BST.insert(10);
    BST.insert(1);
    BST.insert(6);
    BST.insert(14);
    BST.insert(4);
    BST.insert(7);
    BST.insert(13);
    
    // EXPECTED (correct) RESULT:
    //            8
    //           / \
    //        3       10
    //       / \     / \
    //      1   6      14
    //         / \     / \
    //        4   7   13
    //
    //
    
    // |   FUNCTION   |        EXPECTED      | CORRECT? |
    // | Root Print:  | 8                    | YES |
    // | LevelOrder:  | 8 3 10 1 6 14 4 7 13 | YES |
    // | PreOrder:    | 8 3 1 6 4 7 10 14 13 | YES |
    // | InOrder:     | 1 3 4 6 7 8 10 13 14 | YES |
    // | PostOrder:   | 1 4 7 6 3 13 14 10 8 | YES |
    // | Height:      | 4 Levels             | YES |
    // | Total Nodes: | 9 Nodes              | YES |
    // | Balanced:    | Not                  | YES |
    
    BST.printRoot();
    BST.printLevelOrder();
    BST.printPreOrder();
    BST.printInOrder();
    BST.printPostOrder();
    BST.numberOfLevels();
    BST.numberOfNodes();
    BST.isBalanced();
}

void testAVLTree()
{
    AVLTree AVL;
    
    AVL.printRoot();
    AVL.printLevelOrder();
    AVL.printPreOrder();
    AVL.printInOrder();
    AVL.printPostOrder();
    AVL.numberOfLevels();
    AVL.numberOfNodes();
    AVL.isBalanced();
}

void testHeap()
{
    Heap H;
    
}
