#ifndef BINARY_TREE_H
#define BINARY_TREE_H

enum WhichChild {
    LEFT,
    RIGHT
};

template <typename T>
class binary_tree {
private:
    node<T>* apex_node;
    size_t size;

public:
    binary_tree();
    ~binary_tree();

    node<T>* getApexNode() const { return this->apex_node; }
    node<T>* size() const { return this->size; }
};

template <typename T>
class node {
private:
    T value;
    binary_tree<T>* tree;
    node<T>* parent;
    node<T>* leftChild;
    node<T>* rightChild;
    bool isApexNode;

public:
    node(binary_tree<T>* tree); // apex node constructor
    node(T value, node<T>* parent);

    node<T>* setChild(T value, WhichChild lor);
    node<T>* setChild(node<T>* n, WhichChild lor);
    node<T>* setLeftChild(T value);
    node<T>* setLeftChild(node<T>* n);
    node<T>* setRightChild(T value);
    node<T>* setRightChild(node<T>* n);
};

#endif
