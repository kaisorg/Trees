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
// ...Maintains fullness/completeness during insertion //
{
public:
    BinaryTree()
    { root = NULL; }
    
//    ~BinaryTree() // definitely wrong as f
//    {
//        cout << "BinaryTree Warning: Destructor called." << endl;
//        destroyTree();
//    }
    
    // ***** INSERTION ***** //
    void insert(int data)
    {
        if (root == NULL) root = new Node(data);
        
        else insert(data, root);
    }
    
    void insert(int data, Node *tmp)
    {
        if (tmp->left == NULL || tmp->right == NULL) // because && ignores the second value
        {                                            // when the first equals false //
            if (tmp->left == NULL)
                tmp->left = new Node(data);
            
            else if (tmp->right == NULL)
                tmp->right = new Node(data);
        }

        else if (tmp->left != NULL || tmp->right != NULL)
        {
            if (tmp->left != NULL)
                insert(data, tmp->left); //recursion for left
            
            else if (tmp->right != NULL)
                insert(data, tmp->right); //recursion for right
        }
    }
    
    void autoFill(int amount)
    {
        for(int i = 0; i < amount; i++)
            insert(i);
    }
    
    // ***** PRINTS ***** //
    void printRoot()
    {
        cout << root->info << endl;
    }
    
    void printHeight()
    {
        cout << "BinaryTree height is " << height(root) << " levels." << endl;
        cout << "----------------" << endl;
    }
    
    void visualTree()
    {
        // we need level order for this
        // and height
    }
    
    void printLevelOrder()
    {
        cout << "BinaryTree LevelOrder print:" << endl;
        printLevelOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPreOrder()
    {
        cout << "BinaryTree PreOrder print:" << endl;
        printPreOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printInOrder()
    {
        cout << "BinaryTree InOrder print:" << endl;
        printInOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPostOrder()
    {
        cout << "BinaryTree PostOrder print:" << endl;
        printPostOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    // ***** TRAVERSALS ***** //

    
private:
    Node *root;

    // ***** RECURSIVE FUNCTIONS ***** //
    void printLevelOrder(Node *tmp)
    {
        int h = height(tmp);
        int i;
        for (i = 1; i <= h; i++)
            printGivenLevel(tmp, i);
    }
    
    void printGivenLevel(Node *tmp, int level)
    {
        if (root == NULL)
            cout << "BinaryTree Error: printLevelOrder failed because BinaryTree does not exist." << endl;
        else
        {
            if (tmp == NULL)
                return;
            
            if (level == 1)
                cout << tmp->info << " ";
            
            else if (level > 1)
            {
                printGivenLevel(tmp->left, level-1);
                printGivenLevel(tmp->right, level-1);
            }
        }
    }
    
    void printPreOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BinaryTree Error: printLevelOrder failed because BinaryTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            cout << tmp->info << " ";
            printPreOrder(tmp->left);
            printPreOrder(tmp->right);
        }
    }
    
    void printInOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BinaryTree Error: printInOrder failed because BinaryTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printInOrder(tmp->left);
            cout << tmp->info << " ";
            printInOrder(tmp->right);
        }
    }
    
    void printPostOrder(Node *tmp)
    {
        if (root == NULL)
            cout << "BinaryTree Error: printPostOrder failed because BinaryTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printPostOrder(tmp->left);
            printPostOrder(tmp->right);
            cout << tmp->info << " ";
        }
    }
    
    int height(Node *tmp)
    {
        if (root == NULL || tmp == NULL)
            return 0;
        
        else
        {
            /* compute the height of each subtree */
            int lheight = height(tmp->left);
            int rheight = height(tmp->right);
            
            /* use the larger one */
            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }
};

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
