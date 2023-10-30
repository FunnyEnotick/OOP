
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stationery.h"
#include <string>
using std::string;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {

    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void remove(const T& value) {
        if (head == nullptr) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            T tmp = current->data;
            tmp.print();
            current = current->next;
        }
    }

    int count(string str) {
        int sum = 0;
        Node* current = head;
        while (current != nullptr) {
            T tmp = current->data;
            if (tmp.get_firm() == str) {
                sum += tmp.get_quantity();
            }
            current = current->next;
        }
        return sum;
    }
};

#endif // LINKEDLIST_H
