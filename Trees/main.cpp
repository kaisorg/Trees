//
//  main.cpp
//  Tree
//
//  Created by Nitin K on 3/1/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <iostream>
#include "Tree.cpp"
using namespace std;

int main()
{
    BinaryTree BT;
    BT.insert(3); // root
    BT.insert(5); // root->left
    BT.insert(7); // root->right
    BT.insert(9); // root->left->left
    BT.insert(11);// root->left->right

    // What this is supposed to look like:
    //           3
    //          / \
    //        5      7
    //       / \    / \
    //      9  11
    //
    // LevelOrder:  3 5 7 9 11  // our LevelOrder is CORRECT
    // PreOrder:    3 5 9 11 7  // our PreOrder is CORRECT
    // InOrder:     9 5 11 3 7  // our InOrder is CORRECT
    // PostOrder:   9 11 5 7 3  // our PostOrder is CORRECT
    
//    BT.autoFill(10);
    
//    BT.printRoot();
    BT.printLevelOrder();
    BT.printPreOrder();
    BT.printInOrder();
    BT.printPostOrder();
    BT.printHeight();
   // BT.deleteRoot();
    BT.testlastvalue();
    
    return 0;
}
