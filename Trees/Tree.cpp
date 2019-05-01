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
        
        int level = search(data, 1, root);
        
        if (level == 1) cout << "'" << data << "' is the root, Level 1." << endl;
        else if (level > 1) cout << "'" << data << "' was found at Level " << level << "." << endl;
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
    
    void isBalanced()
    {
        if (isBalanced(root)) cout << "BinaryTree is balanced." << endl;
        else cout << "BinaryTree is not balanced." << endl;
        cout << "----------------" << endl;
    }
    
private:
    Node *root;

    // ***** RECURSIVE FUNCTIONS ***** //
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
    
    int search(int data, int level, Node *tmp)
    {
        if (tmp == NULL) return 0;
        if (tmp->info == data) return level;
        
        int reclevel = search(data, level+1, tmp->left);
        if (reclevel != 0) return reclevel;
        
        reclevel = search(data, level+1, tmp->right);
        return reclevel;
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
    
    bool isBalanced(Node *tmp)
    {
        if(tmp == NULL)
            return 0; // Can't be balanced if it doesn't exist
        
        int left;
        int right;
        
        left = height(tmp->left);
        right = height(tmp->right);
        
        if(left-right <= 1 && isBalanced(tmp->left) && isBalanced(tmp->right))
            return 1;
        
        if(left-right > 1 && isBalanced(tmp->left) && isBalanced(tmp->right))
            return 0;
        
        return 0; // Default return
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
