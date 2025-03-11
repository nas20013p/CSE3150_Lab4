#include "Node.h"

Node::Node(int value) : data(value), next(nullptr) {}

// Deep Copy Constructor
Node::Node(const Node& other) : data(other.data), next(nullptr) {
    if (other.next != nullptr) {
        next = new Node(*other.next);  
    }
}

// Destructor 
Node::~Node() {
    next = nullptr;  
}

