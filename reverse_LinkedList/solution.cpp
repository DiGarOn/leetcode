#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void reverse() {
        Node *current = head;
        Node *prev = NULL, *next = NULL;
        while ( current != NULL ) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {


    return 0;
}