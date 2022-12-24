#include "binary_tree.h"

template <typename T>
binary_tree<T>::binary_tree() {
    this->apex_node = new node<T>();
}


template <typename T>
node<T>::node(binary_tree<T>* tree) {
    this->value = nullptr;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->isApexNode = true;
    this->tree = tree;
}

template <typename T>
node<T>::node(T value, node<T> *parent) {
    this->value = value;
    this->parent = parent;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->isApexNode = false;
    this->tree = parent->tree;
    this->tree->size++; 
}

template <typename T>
node<T>* node<T>::setChild(T value, WhichChild lor) {
    node n = new node<T>(value, this);
    return n.setChild(n, lor);
}

template <typename T>
node<T>* node<T>::setChild(node<T>* n, WhichChild lor) {
    if(lor == WhichChild::LEFT) this->leftChild = n;
    if(lor == WhichChild::RIGHT) this->rightChild = n;
    return n;
}

template <typename T>
node<T>* node<T>::setLeftChild(T value) {
    node n = new node<T>(value, this);
    return n.setLeftChild(n);
}

template <typename T>
node<T>* node<T>::setLeftChild(node<T>* n) {
    this->leftChild = n;
    return n;
}

template <typename T>
node<T>* node<T>::setRightChild(T value) {
    node n = new node<T>(value, this);
    return n.setRightChild(n);
}

template <typename T>
node<T>* node<T>::setRightChild(node<T>* n) {
    this->rightChild = n;
    return n;
}
