#ifndef LINKED_LIST_CLASS_H
#define LINKED_LIST_CLASS_H

#include "Node.h"
#include "LinkedListUtils.h"  
#include <vector>
#include <string>

class LinkedList {
private:
    Node* head;
public:
    // Default constructor (creates an empty list)
    LinkedList() : head(nullptr) {}

    // Construct a linked list from a vector of integers
    LinkedList(const std::vector<int>& values) {
        head = build_linked_list(values);
    }

    // Copy constructor 
    LinkedList(const LinkedList& other) {
        if (other.head)
            head = new Node(*other.head); 
        else
            head = nullptr;
    }

    // Move constructor
    LinkedList(LinkedList&& other) noexcept : head(other.head) {
        other.head = nullptr;  
    }

    // Copy assignment operator 
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            delete head;  
            head = (other.head) ? new Node(*other.head) : nullptr;
        }
        return *this;
    }

    //  Clean up current list and steal other's list
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            delete head;
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    // Destructor: deletes the entire list
    ~LinkedList() {
        delete head; 
    }

    //  Return a string representation of the list
    std::string toString() const {
        return print_linked_list(head);
    }

    // Append a new element at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
};

#endif

