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

    
    //           3
    //          / \
    //        5      7
    //       / \    / \
    //      9  11
    //
    //      3 5 7 9 11
    
    //           3
    //          / \
    //        5      9
    //       / \    / \
    //      11  7
    //
    //      3 5 9 11 7
    
//    BT.autoFill(10);
//    BT.printRoot();
    BT.runLevelOrder();
    BT.printHeight();
    
    
    return 0;
}
