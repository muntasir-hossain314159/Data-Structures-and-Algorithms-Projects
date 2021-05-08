#pragma once
#include "Node.hpp"
#include "Enum.hpp"
#include <iostream>

using namespace std;

template <typename K>
class RedBlackTree
{
private:
	Node<K>* root;
    Node<K>* NILL;

    void checkViolation(Node<K>*& childNode);
    void redViolation(Node<K>*& childNode, Node<K>*& parentNode);

    void redUncle(Node<K>*& childNode, Node<K>*& parentNode, Node<K>*& uncleNode, Node<K>*& grandparentNode);
    void blackUncle(Node<K>*& childNode, Node<K>*& parentNode, Node<K>*& grandparentNode);

    void leftRotate(Node<K>*& parentNode);
    void rightRotate(Node<K>*& parentNode);

public:
    RedBlackTree()
    {
        NILL = new Node<K>();
        root = NILL;
    };

	void Insert(Node<K>*& currentNode, Node<K>*& previousNode, K data);
	void Insert(K data);
    void printDataInorderTraversal(Node<K>*& node);
    void printDataInorderTraversal();
    Node<K>* findNode(Node<K>* cursorNode, K data);
    Node<K>* findNode(K data);
    void printFoundData(Node<K>* node);
    Node<K>* getRoot();
    void printRoot();
};

template <typename K>
void RedBlackTree<K> :: printRoot()
{
    cout << "Root: " << root->data << endl << endl;
}

template <typename K>
Node<K>* RedBlackTree<K> :: getRoot()
{
    return root;
}

//BST insert
template <typename K>
void RedBlackTree<K> ::Insert(Node<K>*& currentNode, Node<K>*& previousNode, K data) {
    
    if (currentNode == NILL) 
    {
        currentNode = new Node<K>(data);
        currentNode->parent = previousNode;
        currentNode->left = NILL;
        currentNode->right = NILL;
        checkViolation(currentNode);
    }
    else if (data < currentNode->data) {
        Insert(currentNode->left, currentNode, data);
    }
    else {  
        Insert(currentNode->right, currentNode, data);
    }
}

//BST insert using key
template <typename K>
void RedBlackTree<K> ::Insert(K data) {

    if (root == NILL)
    {
        root = new Node<K>(data);
        root->left = NILL;
        root->right = NILL;
        checkViolation(root);
    }
    else
    {
        Insert(root, root, data);
    }
}

template <typename K>
void RedBlackTree<K> :: checkViolation(Node<K>*& childNode)
{
    if (root == childNode)
    {
        root->color = Color::BLACK;

    }
    else
    {
        Node<K>* parentNode = childNode->parent;
        if (parentNode->color == Color::RED)
        {
            redViolation(childNode, parentNode);
        }
    }
}

template <typename K>
void RedBlackTree<K> :: redViolation(Node<K>*& childNode, Node<K>*& parentNode)
{
    Node<K>* grandparentNode = nullptr;
    Node<K>* uncleNode = nullptr;

    grandparentNode = parentNode->parent;

    if (grandparentNode->right == parentNode)
        uncleNode = grandparentNode->left;
    
    else if (grandparentNode->left == parentNode)
        uncleNode = grandparentNode->right;
    

    if (uncleNode->color == Color::RED)
    {
        redUncle(childNode, parentNode, uncleNode, grandparentNode);
    }
    else
    {
        blackUncle(childNode, parentNode, grandparentNode);
    }
}

template <typename K>
void RedBlackTree<K> :: redUncle(Node<K>*& childNode, Node<K>*& parentNode, Node<K>*& uncleNode, Node<K>*& grandparentNode)
{
    parentNode->color = Color::BLACK;
    uncleNode->color = Color::BLACK;
    grandparentNode->color = Color::RED;
    checkViolation(grandparentNode);
}


template <typename K>
void RedBlackTree<K> :: blackUncle(Node<K>*& childNode, Node<K>*& parentNode, Node<K>*& grandparentNode)
{
    if (grandparentNode->left == parentNode)
    {
        bool checkLeft = false;
        if (parentNode->right == childNode)
        {
            leftRotate(parentNode);
            checkLeft = true;
        }
        rightRotate(grandparentNode);
        
        if (!checkLeft)
        {
            parentNode->color = Color::BLACK;
            grandparentNode->color = Color::RED;
        }
        else
        {
            childNode->color = Color::BLACK;
            grandparentNode->color = Color::RED;
        }
    }
    else
    {
        bool checkRight = false;
        if (parentNode->left == childNode)
        {
            rightRotate(parentNode);
            checkRight = true;
        }
        
        leftRotate(grandparentNode);
       
        if (!checkRight)
        {
            parentNode->color = Color::BLACK;
            grandparentNode->color = Color::RED;
        }
        else
        {
            childNode->color = Color::BLACK;
            grandparentNode->color = Color::RED;
        }
    }   
    root->color = Color::BLACK;
}

template <typename K>
void RedBlackTree<K> :: leftRotate(Node<K>*& parentNode)
{
    Node<K>* childNode = parentNode->right;
    parentNode->right = childNode->left;
    if (childNode->left != NILL)
    {
        childNode->left->parent = parentNode;
    }
    childNode->parent = parentNode->parent;

    if (root == parentNode)
    {
        root = childNode;
    }
    else if (parentNode->parent->right == parentNode)
    {
        parentNode->parent->right = childNode;
    }
    else
    {
        parentNode->parent->left = childNode;
    }

    childNode->left = parentNode;
    parentNode->parent = childNode;
}

template <typename K>
void RedBlackTree<K> :: rightRotate(Node<K>*& parentNode)
{

    Node<K>* childNode = parentNode->left;
    parentNode->left = childNode->right;
    if (childNode->right != NILL)
    {
        childNode->right->parent = parentNode;
    }
    childNode->parent = parentNode->parent;

    if (root == parentNode)
    {
        root = childNode;
    }
    else if (parentNode->parent->right == parentNode)
    {
        parentNode->parent->right = childNode;
    }
    else
    {
        parentNode->parent->left = childNode;
    }

    childNode->right = parentNode;
    parentNode->parent = childNode;
    
}

template <typename K>
void RedBlackTree<K> :: printDataInorderTraversal(Node<K>*& node)
{
    if (node == NILL)
    {
        return;
    }
        
    Node<K>* leftNode = node->left;
    printDataInorderTraversal(leftNode);
    cout << "[" << node->data << "]";
    Node<K>* rightNode = node->right;
    printDataInorderTraversal(rightNode);
}

template <typename K>
void RedBlackTree<K> :: printDataInorderTraversal()
{
    //cout << "Root check " << root->data << endl;
    printDataInorderTraversal(root);
}

template <typename K>
Node<K>* RedBlackTree<K> :: findNode(Node<K>* cursorNode, K data)
{
    if (cursorNode == NILL)
        return nullptr;
    else if (data < cursorNode->data)
    {
        findNode(cursorNode->left, data);
    }
    else if (data == cursorNode->data)
    {
        return cursorNode;
    }
    else
    {
        findNode(cursorNode->right, data);
    }
}

template <typename K>
Node<K>* RedBlackTree<K> :: findNode(K data)
{
   return findNode(root, data); 
}

//ptr or ptr reference
template <typename K>
void RedBlackTree<K> ::printFoundData(Node<K>* node)
{
    try
    {
        if (node == nullptr)
            throw "Item not found";
        cout << "Data: " << node->data << ", " << endl;
        string msg;
        if (node->color == Color::RED)
        {
            msg = "RED";
        }
        else if (node->color == Color::BLACK)
        {
            msg = "BLACK";
        }
        cout << "Color: " << msg << endl << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl << endl;
    }
}




