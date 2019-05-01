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
    // |   FUNCTION   |  EXPECTED  | CORRECT? |
    // | LevelOrder:  | 3 5 7 9 11 | YES |
    // | PreOrder:    | 3 5 9 11 7 | YES |
    // | InOrder:     | 9 5 11 3 7 | YES |
    // | PostOrder:   | 9 11 5 7 3 | YES |
    // | Height:      | 3 Levels   | YES |
    // | Total Nodes: | 5 Nodes    | YES |
    
//    BT.autoFill(10);
    
//    BT.printRoot();
    BT.printLevelOrder();
    BT.printPreOrder();
    BT.printInOrder();
    BT.printPostOrder();
    BT.numberOfLevels();
    BT.numberOfNodes();
    
    BT.search(1);
    BT.search(3);
    BT.search(5);
    BT.search(7);
    BT.search(9);
    BT.search(11);
    BT.search(13);
    BT.search(15);
    BT.search(17);
    
    return 0;
}
