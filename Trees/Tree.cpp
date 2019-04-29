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
        cout << "BinaryTree: LevelOrder print:" << endl;
        printLevelOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPreOrder()
    {
        cout << "BinaryTree: PreOrder print:" << endl;
        printPreOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printInOrder()
    {
        cout << "BinaryTree: InOrder print:" << endl;
        printInOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPostOrder()
    {
        cout << "BinaryTree: PostOrder print:" << endl;
        printPostOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    // ***** SEARCH & SIZE ***** //
    void search(int data)
    {
        cout << "BinaryTree: Searching for '" << data << "'... " << endl;
        
        // if found, cout "data was found on level x of the tree"
        // if not, cout " data was not found in the tree"
        
        int found = search(data, root);
        if (found != 0) cout << "'" << data << "' was found at Level " << found << "." << endl;
        else cout << "'" << data << "' was not found." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfLevels()
    {
        cout << "BinaryTree: Number of Levels: " << height(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfNodes()
    {
        cout << "BinaryTree: Number of Nodes: " << numberOfNodes(root) << "." << endl;
        cout << "----------------" << endl;
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
        if (tmp == NULL)
            return 0;
        
        else
        {
            int left = height(tmp->left); // Recursive calls for depth-first //
            int right = height(tmp->right);
            
            if (left > right) return (left+1);  // if the left is larger, return left
            else return (right+1);              // +1 to compensate for the recursion missing one
        }
    }
    
//    int search(int data, Node *tmp)
//    {
//        if (tmp != NULL)
//        {
//            if (data == tmp->info) return searchHeight(data, tmp); // When we have found that the value DOES exist in the tree
//                                                                   // We need to find what LEVEL it resides on, thus calling searchHeight
//            else
//            {
//                if (data < tmp->info) return search(data, tmp->left); // But if we haven't, we need to recurse the tree until the match is found
//                else return search(data, tmp->right);
//            }
//        }
//        else return NULL;
//    }
    
    int search(int data, Node *tmp)
    {
        if (root->info == data) return 1; // This will always print "Level 1" for the Root
        
        if (tmp != NULL && tmp->info != data) // This is the hard part ... We have to find where tmp-info == data while tmp != NULL
        {                // Bc if tmp == NULL then it does not exist
//            if (tmp->info != data)
//            {
                int left = search(data, tmp->left); //
                int right = search(data, tmp->right);
                
                if (left < right) return (left+1);  //
                else return (right+1);              //
//            }
//            else return 0;
        }
        else return 0;
    }
    
    int numberOfNodes(Node *tmp)
    {
        int count = 1;
        
        if (tmp->left != NULL)
            count += numberOfNodes(tmp->left);
        
        if (tmp->right != NULL)
            count += numberOfNodes(tmp->right);
        
        return count;
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
