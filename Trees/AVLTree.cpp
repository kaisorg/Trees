//
//  AVLTree.cpp
//  Trees
//
//  Created by Nitin K on 5/2/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Node.h"
using namespace std;

class AVLTree
// A self-balancing BST where the difference between heights of left and right subtrees cannot be more than one for all nodes
// Uses rotation to move things into their proper place
{
public:
    AVLTree()
    { root = NULL; }
    
//    ~AVLTree()
//    {
//        cout << "AVLTree Warning: Destructor called." << endl;
//        destroyTree();
//    }
    
    // ***** INSERTION ***** //
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return root;
        }
        
        else if(data < root->info)
        {
            root->left = insert(root->left, data);
            root = balance(root);
        }
        
        else if (data >= root->info)
        {
            root->right = insert(root->right, data);
            root = balance(root);
        }
        return root;
    }
    
    // ***** ROTATION ***** //
    Node *LLrotation(Node *parent)
    {
        Node *tmp;
        tmp = parent->left;
        parent->left = tmp->right;
        tmp->right = parent;
        return tmp;
    }
    
    Node *LRrotation(Node *parent)
    {

    }
    
    Node *RRrotation(Node *parent)
    {
        Node *tmp;
        tmp = parent->right;
        parent->right = tmp->left;
        tmp->left = parent;
        return tmp;
    }
    
    Node *RLrotation(Node *parent)
    {

    }
    
    Node *balance(Node *tmp)
    {
        int BFactor = getBFactor(tmp);
        
        if (BFactor > 1)
        {
            if (getBFactor(tmp->left) > 0)
                tmp = LLrotation(tmp);
            else
                tmp = LRrotation(tmp);
        }
        
        else if (BFactor < -1)
        {
            if (getBFactor(tmp->right) > 0)
                tmp = RLrotation(tmp);
            else
                tmp = RRrotation(tmp);
        }
        return tmp;
    }
    
    // ***** DELETION ***** //
    
    // ***** PRINTS ***** //
    void printRoot()
    {
        cout << "AVLTree: Root print: " << root->info << endl
        << "----------------" << endl;
    }
    
    void printLevelOrder()
    {
        cout << "AVLTree: LevelOrder print:" << endl;
        printLevelOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPreOrder()
    {
        cout << "AVLTree: PreOrder print:" << endl;
        printPreOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printInOrder()
    {
        cout << "AVLTree: InOrder print:" << endl;
        printInOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    void printPostOrder()
    {
        cout << "AVLTree: PostOrder print:" << endl;
        printPostOrder(root);
        cout << endl << "----------------" << endl;
    }
    
    // ***** SEARCH & SIZE ***** //
    void search(int data)
    {
        cout << "AVLTree: Searching for '" << data << "'... " << endl;
        
        int level = search(data, 1, root);
        
        if (level == 1) cout << "'" << data << "' is the root, Level 1." << endl;
        else if (level > 1) cout << "'" << data << "' was found at Level " << level << "." << endl;
        else cout << "'" << data << "' was not found." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfLevels()
    {
        cout << "AVLTree: Number of Levels: " << height(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void numberOfNodes()
    {
        cout << "AVLTree: Number of Nodes: " << numberOfNodes(root) << "." << endl;
        cout << "----------------" << endl;
    }
    
    void isBalanced()
    {
        if (isBalanced(root)) cout << "AVLTree is balanced." << endl;
        else cout << "AVLTree is not balanced." << endl;
        cout << "----------------" << endl;
    }
    
    void printBalanceFactor()
    {
        cout << "AVLTree: Balance Factor: " << getBFactor(root) << " ." << endl;
        cout << "----------------" << endl;
    }
    
private:
    Node *root;
    
    // ***** RECURSIVE FUNCTIONS ***** //
    void insert();
    
    void printLevelOrder(Node *tmp)
    {
        int h = height(tmp);
        for (int i = 1; i <= h; i++)
            printGivenLevel(tmp, i);
    }
    
    void printGivenLevel(Node *tmp, int level)
    {
        if (root == NULL)
            cout << "AVLTree Error: printLevelOrder failed because AVLTree does not exist." << endl;
        
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
            cout << "AVLTree Error: printLevelOrder failed because AVLTree does not exist." << endl;
        
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
            cout << "AVLTree Error: printInOrder failed because AVLTree does not exist." << endl;
        
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
            cout << "AVLTree Error: printPostOrder failed because AVLTree does not exist." << endl;
        
        else if (tmp != NULL)
        {
            printPostOrder(tmp->left);
            printPostOrder(tmp->right);
            cout << tmp->info << " ";
        }
    }
    
    int height(Node *tmp)
    {
        if (tmp != NULL)
        {
            int left = height(tmp->left);
            int right = height(tmp->right);
            
            if (left > right) return (left+1);
            else return (right+1);
        }
        return 0;
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
    
    int getBFactor(Node *tmp) // get Balance Factor of the AVL Tree
    {
        int left = height(tmp->left);
        int right = height(tmp->right);
        int BFactor = left - right;
        return BFactor;
    }
};
