#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Node.h"
#include "LinkedList.h"
#include "doctest.h"
#include <vector>

// Test build & print
TEST_CASE("Testing build_linked_list and print_linked_list") {
    std::vector<int> values = {1, 2, 3};
    Node* list = build_linked_list(values);

    CHECK(print_linked_list(list) == "1 2 3 \n");

    delete_entire_linked_list(list);
}

// Test getting values
TEST_CASE("Testing get_linked_list_data_item_value") {
    std::vector<int> values = {10, 20, 30};
    Node* list = build_linked_list(values);

    CHECK(get_linked_list_data_item_value(list, 0) == 10);
    CHECK(get_linked_list_data_item_value(list, 1) == 20);
    CHECK(get_linked_list_data_item_value(list, 2) == 30);

    delete_entire_linked_list(list);
}

// Test deleting an element
TEST_CASE("Testing delete_list_element") {
    std::vector<int> values = {0, 1, 2, 3, 4};
    Node* list = build_linked_list(values);

    delete_list_element(list, 2);
    CHECK(print_linked_list(list) == "0 1 3 4 \n");

    delete_list_element(list, 0);
    CHECK(print_linked_list(list) == "1 3 4 \n");

    delete_entire_linked_list(list);
}

// Test deleting the entire list
TEST_CASE("Testing delete_entire_linked_list") {
    std::vector<int> values = {5, 10, 15};
    Node* list = build_linked_list(values);

    CHECK(print_linked_list(list) == "5 10 15 \n");

    delete_entire_linked_list(list);
    CHECK(print_linked_list(list) == "\n");
}



TEST_CASE("Move Constructor transfers ownership") {
    LinkedList original({1, 2, 3});
    LinkedList moved(std::move(original));
    CHECK(original.toString() == "\n");
    CHECK(moved.toString() == "1 2 3 \n");
}

TEST_CASE("Move Assignment transfers ownership") {
    LinkedList list1({10, 20});
    LinkedList list2({30, 40});
    list1 = std::move(list2);
    CHECK(list2.toString() == "\n");
    CHECK(list1.toString() == "30 40 \n");
}

