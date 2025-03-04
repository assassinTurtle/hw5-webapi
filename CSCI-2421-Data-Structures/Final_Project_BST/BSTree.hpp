/*
 - Patrick Tate
 - Final Project
 - CSCI 2421
 - Program written using Xcode on MacOS
 - Program Status: program compiles and runs on the cse grid
 */

//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
 but do NOT compile it (or add it to the project)*/
#ifndef BSTREEINT_HPP
#define BSTREEINT_HPP
#include "BSTree.h"

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>:: searchT(string value)
{
    if (Root() == nullptr) {
        cout << "Empty tree, no records.\n";
    }
    else if (root->Key() == value){
        cout << "Found record at root.\n";
    }
    else if (value < root->Key()){
        searchTree(value, root->Left());
    }
    else if (value >= root->Key()){
        searchTree(value, root->Right());
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>:: searchTree(string value, Node<DATATYPE, KEYTYPE> * leaf)
{
    if (leaf == nullptr) {
        cout << endl << "Record not found.\n";
        return;
    }
    else if (leaf->Key() == value){
        cout << endl << "Found that record:\n";
        print(cout, leaf->Data());
        if (leaf->Right() != nullptr) {
            searchTree(value, leaf->Right());
        }
        return;
    }
    if (value < leaf->Key()) {
        searchTree(value, leaf->Left());
    }
    else if (value >= leaf->Key()){
        searchTree(value, leaf->Right());
    }
}

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
    root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node written by Patrick Tate
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    //Student must fill in
    //if the root is the leaf, delete that leaf
    // otherwise if the leaf is not null
    //recursive call of the leaf's left
    //recursive call of the leaf's right
    //now delete the leaf
    if (leaf == Root()) {
        delete leaf;
    }
    freeNode(leaf->Left());
    freeNode(leaf->Right());
    
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
    if (Root() == nullptr)
    {
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
        
    }
    else
        addNode(key, root, data);
}

// Add a node (private) written by Patrick Tate
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    //Student must fill in
    //Don't forget to set your key, Parent, then left or right
    //Based on the case you use you will addNode recursively to the left or right
    
    //First check if root is null
    //make a new node
    //set the key and data
    //set the root
    //Otherwise
    //Check to see if the key is < the leaf's key
    // if left is not null then
    //Add the node to the left (recursively)
    // Otherwise make a new node and attach it to the left
    
    //Check to see if the key >= leaf's key
    // if leaf's right is not null then
    //Add the node to the right (recursively)
    // Otherwise make new node and attach it to the right
    if (leaf == nullptr) {
        //if tree is empty
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);
    }
    else if (key < leaf->Key()){
        if (leaf->Left() != nullptr) {
            addNode(key, leaf->Left(), data);
        }
        else{
            //add node to tree
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setLeft(newNodePtr);
            newNodePtr->setParent(leaf);
        }
    }
    else if (key >= leaf->Key()){
        if (leaf->Right() != nullptr) {
            addNode(key, leaf->Right(), data);
        }
        else{
            //add node to tree
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setRight(newNodePtr);
            newNodePtr->setParent(leaf);
        }
    }
    
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
    return findNode(key, root);
}

// Find a node written by Patrick Tate
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in
    // trap nullptr first in case we've hit the end unsuccessfully.
    // success base case
    //Greater than (Right), Less than (Left)
    if ((node == nullptr) || node->Key() == key) {
        return node;
    }
    if (node->Key() < key) {
        return findNode(key, node->Right());
    }
    else{
        return findNode(key, node->Left());
    }
    
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
    printInorder(root);
}

//written by Patrick Tate
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //if tree not empty
    if (root != nullptr) {
        //go left if possible
        if (node->Left() != nullptr) {
            printInorder(node->Left());
        }
        
        print(cout,node->Data());
        
        //go right if possible
        if (node->Right() != nullptr) {
            printInorder(node->Right());
        }
    }
    else{
        cout << "Tree is empty.\n";
    }
    
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
    
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */
    
    // base case
    if (aRoot == nullptr) return aRoot;
    
    // If the key to be deleted is smaller than the aRoot's key,
    // then it lies in left subtree
    if (value < aRoot->Key())
        aRoot->setLeft(deleteNode(aRoot->Left(), value));
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (value > aRoot->Key())
        aRoot->setRight(deleteNode(aRoot->Right(), value));
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (aRoot->Left() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
            delete aRoot;
            return temp;
        }
        else if (aRoot->Right() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
            delete aRoot;
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());
        
        // Copy the inorder successor's content to this node
        aRoot->setKey(temp->Key());
        aRoot->setData(temp->Data());
        
        // Delete the inorder successor
        aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
    }
    return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->Left() != nullptr)
        current = current->Left();
    
    return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->Right())
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}
#endif
