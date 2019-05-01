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
    BT.insert(13);// root->right->left
    BT.insert(15);// root->right->right

    // What this is supposed to look like:
    //           3
    //          / \
    //        5      7
    //       / \    / \
    //      9  11  13 15
    //
    // |   FUNCTION   |      EXPECTED    | CORRECT? |
    // | LevelOrder:  | 3 5 7 9 11 13 15 | NO |
    // | PreOrder:    | 3 5 9 11 7 13 15 | NO |
    // | InOrder:     | 9 5 11 3 13 7 15 | NO |
    // | PostOrder:   | 9 11 5 13 15 7 3 | NO |
    // | Height:      | 3 Levels         | NO |
    // | Total Nodes: | 7 Nodes          | YES |
    // | Balanced:    | Not              | NO |
    
//    BT.autoFill(10);
    
//    BT.printRoot();
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
    
    return 0;
}
