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
    BT.insert(3);
    BT.insert(5);
//    BT.insert(7);
//    BT.printRoot();
//    BT.runLevelOrder();
    BT.printHeight();
    
    
    return 0;
}
