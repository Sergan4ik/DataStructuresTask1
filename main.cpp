#include <iostream>
#include "task2.cpp"
#include "task3.cpp"
#include "task4.cpp"
#include "task5.cpp"
#include "task6.cpp"
#include "task7.cpp"

using namespace std;

class Node{
public:
    explicit Node(int value) : value(value) {}

public:
    Node *nextNode = nullptr, *previousNode = nullptr;
    int value;
};

Node* head;

Node* push_back_node(int value){
    auto newNode = new Node(value);
    Node* currentNode = head;
    while(currentNode->nextNode != nullptr)
        currentNode = currentNode->nextNode;
    newNode->previousNode = currentNode;
    currentNode->nextNode = newNode;
    return newNode;
}

Node* find_node_with_value(int value){
    Node* currentNode = head;
    while(currentNode != nullptr && currentNode->value != value){
        currentNode = currentNode->nextNode;
    }
    return currentNode;
}

void remove_node(int toDelete){
    Node* currentNode = find_node_with_value(toDelete);
    if (currentNode == nullptr)
        return;

    if (currentNode->previousNode != nullptr)
    {
        currentNode->previousNode->nextNode = currentNode->nextNode;
        currentNode->nextNode->previousNode = currentNode->previousNode;
    }
    else
    {
        currentNode->nextNode->previousNode = nullptr;
        head = currentNode;
    }

    delete currentNode;
}

void print_list(){
    for(auto it = head; it != nullptr; it = it->nextNode){
        cout << it->value << " ";
    }
    cout << endl;
}

void swap_nodes(int val){
    Node* node = find_node_with_value(val);

    if (node->previousNode == nullptr || node->nextNode == nullptr)
        return;

    Node* prev = node->previousNode->previousNode;
    if (node->previousNode->previousNode == nullptr)
        head = node->nextNode;

    swap(node->nextNode , node->previousNode);
    swap(node->previousNode->previousNode , node->nextNode->previousNode);
    swap(node->previousNode->nextNode , node->nextNode->nextNode);

    prev->nextNode = node->previousNode;
}

size_t list_size(){
    size_t count = 0;
    for(auto it = head; it != nullptr; it = it->nextNode, count++){}
    return count;
}


void testTask1(){
    head = new Node(10);
    push_back_node(12);
    push_back_node(7);
    push_back_node(20);

    print_list();
    cout << list_size() << endl;
    swap_nodes(7);
    print_list();
    cout << list_size() << endl;
}

int main() {
    testTask2();

    cout << endl << endl;

    testTask7();
}
