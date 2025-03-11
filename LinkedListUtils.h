
#ifndef LINKED_LIST_UTILS_H
#define LINKED_LIST_UTILS_H

#include <vector>
#include <string>
#include "Node.h"

Node* build_linked_list(const std::vector<int>& values);
std::string print_linked_list(Node* root);
void delete_entire_linked_list(Node*& root);
int get_linked_list_data_item_value(Node* root, int node_number);
void delete_list_element(Node*& root, int node_number);

#endif
