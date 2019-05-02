//
//  BSTree.cpp
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Node.cpp"
using namespace std;

class BSTree
// Type of Tree where there are 0, 1, or 2 children per Node...
// ...It has built-in sorting, where the median is the root Node...
// ...Maintains fullness/completeness during insertion //
{
public:
    // CONSTRUCTOR
    
    // ~DESTRUCTOR
    
    void insert(int data)
    {
        insert(data, root);
    }
    
private:
    Node *root, *leaf;
    
    void insert(int data, Node *tmp) // Recursive insert function //
    {
        if (root == NULL)
            root = new Node(data);
        
        else
        {
            if (data < tmp->info)
            {
                if(tmp->left != NULL)
                    insert(data, tmp->left);
                else
                    tmp->left = new Node (data);
            }
            
            else if (data >= tmp->info)
            {
                if(tmp->right != NULL)
                    insert(data, tmp->right);
                else
                    tmp->right = new Node (data);
            }
        }
    }
};
