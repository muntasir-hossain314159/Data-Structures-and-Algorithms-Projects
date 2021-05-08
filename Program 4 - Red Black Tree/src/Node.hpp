#pragma once
#include "Enum.hpp"

template <typename K>
struct Node {
    K data;
    Color color;
    Node<K>* left;
    Node<K>* right;
    Node<K>* parent;

    //Default constructor for NILL Node
    Node()
    {
        color = Color::BLACK;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    };

    // Constructor
    Node(K data) :
        data{ data },
        left{ nullptr },
        right{ nullptr },
        parent{ nullptr },
        color{ Color::RED }
    {};
};