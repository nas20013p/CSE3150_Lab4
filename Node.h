#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value);
    
    // Copy constructor (Deep Copy)
    Node(const Node& other);
    
    // Destructor (Properly frees memory)
    ~Node();
};

#endif
