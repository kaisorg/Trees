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
     // ******* Destructor  ******//
    ~BinaryTree()
    {
        cout << "BinaryTree Warning: Destructor called." << endl;
        destroy_tree();
    }
    // ****** Wrap that calls private destroy function ****//
    void destroy_tree()
    {
        destroy_tree(root);
    }
    
    // ***** INSERTION ***** //
    void insert(int data)
    {
        if (root == NULL) root = new Node(data); // Simply create new Node with (data) and make it *root //
        
        else insert(data, root); // Else go to the recursive insert function using the second param //
    }
    
    void insert(int data, Node *tmp) // Recursive insert function //
    {
        if (tmp->left == NULL || tmp->right == NULL) // Check if EITHER the left or the right are open //
        {
            if (tmp->left == NULL)          // If the left was the open one,
                tmp->left = new Node(data); // insert there //
            
            else if (tmp->right == NULL)     // Else if the right one was the open one,
                tmp->right = new Node(data); // insert there //
        }

        else if (tmp->left != NULL || tmp->right != NULL) // But if they were both taken...
        {
            if (tmp->left != NULL)
                insert(data, tmp->left);    // ...Start recursing through the tree...
                                            // ...Until it finds the opening //
            else if (tmp->right != NULL)
                insert(data, tmp->right);
        }
    }
    
    void autoFill(int amount)   // Function to automatically fill the tree...
    {                           // ...with random numbers //
        for(int i = 0; i < amount; i++)
            insert(rand()%100);
    }
    
    // ***** DELETION ***** //
    void deleteRoot()
    {
       deleteroot(root);
    }
    
    void deleteLeaf(int data)
    {   
        // traverse tree until tmp->info == data
       
        // delete tmp and reattach pointers
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
        
        // pseudocode:
        // use height to determine how many spaces the root needs
        // use levelorder and print the root
        // endl and then insert slashes
        // the amount of spaces used for the root, minus a variable number, print the root->left
        // then the number of spaces subtracted are then printed
        // then the right is printed, endl;
        // insert slashes
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

    void testlastvalue()
    {
        Node *tmp = lastvalue(tmp);
        cout<<tmp->info<<endl;
    }
    
private:
    Node *root;

    // ***** RECURSIVE FUNCTIONS ***** //
    void printLevelOrder(Node *tmp)
    {
        int h = height(tmp);
        for (int i = 1; i <= h; i++)
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
            int left = height(tmp->left); // Recursive calls for depth-first //
            int right = height(tmp->right);
            
            if (left > right) return (left+1);  // if the left is larger, return left
            else return (right+1);              // +1 to compensate for the recursion missing one
        }
    }
    void destroy_tree( Node *tmp)
    {
        if(tmp != NULL)
        {
            insert(data, tmp->right);
            destroy_tree(tmp->left);
            destroy_tree(tmp->right);
            delete tmp;
            
        }
    }
    void deleteroot (Node *root)  //deleteing the root and replacing it with the last value 
    {
         Node *tmp = root;
        if (root==NULL)
        {
            cout<<"root does not exsist"<<endl;
        }
        else
        {
            if (tmp->left != NULL && tmp->right != NULL) 
            {
                Node *replacment = lastvalue(tmp); //calls the function that returns the last value
                delete root;
                root = replacment;
                replacment->left = root->left;
                replacment->right = root->right;
            } 
        }
        
    }
    Node *lastvalue (Node *tmp) //finds and returns the last value in the tree using post order traversal
    {
        Node *tmp = root;
        if (tmp!= NULL)
        {
            Node *lastvalue(tmp->left);
            Node *lastvalue(tmp->right);
            return tmp;
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
