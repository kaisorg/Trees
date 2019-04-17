//
//  Tree.cpp
//  Tree
//
//  Created by Nitin K on 3/8/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <iostream>
using namespace std;

class Node
{
public:
    Node()
    { *left = NULL; *right = NULL; }
    
    Node(int data, Node *Lptr = NULL, Node *Rptr = NULL)
    { info = data; left = Lptr; right = Rptr; }

    
    int info;
    Node *left, *right;
};

class BinaryTree
// Type of Tree where there are 0, 1, or 2 children per Node...
// ...However, there is no built-in sorting...
// ...And right-side Nodes are allowed //
{
public:
    BinaryTree()
    { root = leaf = NULL; }
    
//    ~BinaryTree() // definitely wrong as f
//    {
//        cout << "Warning: Destructor called." << endl;
//        for (Node *tmp = root; tmp != NULL;)
//        {
//            tmp = root->left;
//            delete root;
//            root = tmp;
//        }
//    }
    
    // ***** INSERTION ***** //
    void insert(int data)
    {
        if (root == NULL)
            root = new Node(data);

        else
        {
            Node *plug = new Node(data);
            plug = levelOrder(root);
        }
    }
    
    // ***** PRINTS ***** //
    void printRoot()
    {
        cout << root->info << endl;
    }
    
    void printHeight()
    {
        cout << "BinaryTree height is " << height(root) << " levels." << endl;
    }
    
    void visualTree()
    {
        // we need level order for this
        // and height
    }
    
    void runLevelOrder()
    {
        printLevelOrder(root);
    }
    
    void printLevelOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BinaryTree Error: printLevelOrder failed because BinaryTree does not exist." << endl;
        
        else
        {
            printLevelOrder(tmp->left);
            cout << tmp->info << " ";
            printLevelOrder(tmp->right);
        }
    }
    
    // ***** TRAVERSALS ***** //
    
    Node *levelOrder(Node *tmp) // trying to return the pointer
    {
        if (tmp == NULL) return tmp;
        
        else
        {
            if (tmp->left == NULL)
            {
                return tmp->left;
            }
            else if (tmp->right == NULL)
                
            levelOrder(tmp->left);
            levelOrder(tmp->right);
            return tmp;
        }
    }
    
    // ***** HELPER FUNCTIONS ***** //
    int height(Node *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(root->left);
            int rheight = height(root->right);
            
            /* use the larger one */
            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }
    
private:
    Node *root, *leaf;
};

class BSTree
// Type of Tree where there are 0, 1, or 2 children per Node...
// ...It has built-in sorting, where the median is the root Node...
// ...And right-side Nodes are allowed //
{
public:
    // CONSTRUCTOR
    
    // ~DESTRUCTOR
    
    void insert(int data)
    {
        
        if (root == NULL)
            root = new Node(data);
        
        else
        {
            Node *tmp = root;
            if (tmp->left == NULL)
            {
                
            }
        }
    }
    
private:
    Node *root, *leaf;
};

class AVLTree
// A self-balancing BST where the difference between heights of left and right subtrees cannot be more than one for all nodes
// Uses rotation to move things into their proper place
{
public:
    
private:
    Node *root, *leaf;
};

class Heap
{
public:
    ///<type> MaxHeapify()
    
    ///<type> MinHeapify()
private:
    Node *root, *leaf;
};
