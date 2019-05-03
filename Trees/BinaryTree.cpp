//
//  BinaryTree.cpp
//  Trees
//
//  Created by Nitin K on 3/8/19.
//  Copyright © 2019 CSCI 373. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Node.h"
using namespace std;

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
        if (root == NULL) root = new Node(data);
        else insert(data, root);
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
        cout << "BinaryTree: Root print: " << root->info << endl
        << "----------------" << endl;
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

    void testlastvalue()
    {
        Node *tmp = lastvalue(tmp);
        cout<<tmp->info<<endl;
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