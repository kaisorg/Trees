//
//  Node.cpp
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Node
// Simple Node, containing pointers to left and right, and var for integer
{
public:
    Node()
    { *left = NULL; *right = NULL; }
    
    Node(int data, Node *Lptr = NULL, Node *Rptr = NULL)
    { info = data; left = Lptr; right = Rptr; }
    
    int info;
    Node *left, *right;
};
