#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

// Build linked list 
Node* build_linked_list(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    
    Node* root = new Node(values[0]);
    Node* current = root;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    
    return root;
}

// Print linked list 
std::string print_linked_list(Node* root) {
    std::ostringstream oss;
    Node* current = root;
    while (current != nullptr) {
        oss << current->data << " ";
        current = current->next;
    }
    oss << "\n";
    return oss.str();
}


void delete_entire_linked_list(Node*& root) {
    while (root != nullptr) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}




// Get value from a given node position
int get_linked_list_data_item_value(Node* root, int node_number) {
    if (node_number < 0) {
        throw std::out_of_range("Node number cannot be negative");
    }
    
    Node* current = root;
    int current_position = 0;
    
    while (current != nullptr && current_position < node_number) {
        current = current->next;
        current_position++;
    }
    
    if (current == nullptr) {
        throw std::out_of_range("Node number exceeds list length");
    }
    
    return current->data;
}

// Delete an element at a given index
void delete_list_element(Node*& root, int node_number) {
    if (root == nullptr) {
        throw std::out_of_range("List is empty");
    }
    
    if (node_number < 0) {
        throw std::out_of_range("Node number cannot be negative");
    }
    
    if (node_number == 0) {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }
    
    Node* current = root;
    int current_position = 0;
    
    while (current->next != nullptr && current_position < node_number - 1) {
        current = current->next;
        current_position++;
    }
    
    if (current->next == nullptr) {
        throw std::out_of_range("Node number exceeds list length");
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}
