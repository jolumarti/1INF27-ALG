#include "p2.hpp"

#include <iostream>
#include <climits>

using namespace std;

#define NOT_FOUND -1

struct Node {
    int value;
    Node *next;
};

void push(Node *&head, Node *node) {
    if (node == nullptr)
        return;

    node->next = head;
    head = node;
}

Node *pop(Node *&head) {
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    temp->next = nullptr;

    return temp;
}

void insert_value(Node *&head, int value) {
    Node *node = new Node;
    node->value = value;
    node->next = nullptr;

    push(head, node);
}

void print_stack(Node *head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void print_stacks(Node *stacks[]) {
    cout << "STACK 1: ";
    print_stack(stacks[0]);
    cout << "STACK 2: ";
    print_stack(stacks[1]);
    cout << "STACK 3: ";
    print_stack(stacks[2]);
    cout << endl;
}

void hanoi(Node *stacks[], int limit, int dest_id) {
    int max_value = INT_MIN;
    int max_id = NOT_FOUND;

    // encontrar el paq mas grande
    for (int i = 0; i < 3; i++) {
        Node *current = stacks[i];

        while (current) {
            if (current->value < limit &&
                current->value > max_value) {
                max_value = current->value;
                max_id = i;
            }
            current = current->next;
        }
    }

    // no hay paq mas grande
    if (max_id == NOT_FOUND) return;

    // el paq ya esta en destino, ahora buscar el siguiente paq
    if (max_id == dest_id) {
        hanoi(stacks, max_value, dest_id);
        return;
    }

    // encontrar la pila aux, se puede hacer con for
    int aux_id = 3 - max_id - dest_id;

    // mover otros discos al aux
    hanoi(stacks, max_value, aux_id);

    print_stacks(stacks);

    // ahora el paq mayor estar arriba y mover al destino
    push(stacks[dest_id], pop(stacks[max_id]));

    print_stacks(stacks);

    // mover otros paq al destino
    hanoi(stacks, max_value, dest_id);
    print_stacks(stacks);

}

void p2() {
    Node *stacks[3] = {nullptr, nullptr, nullptr};

    // Stack 1:
    insert_value(stacks[0], 20);
    insert_value(stacks[0], 15);
    insert_value(stacks[0], 5);

    // Stack 2:
    insert_value(stacks[1], 18);
    insert_value(stacks[1], 12);
    insert_value(stacks[1], 10);
    insert_value(stacks[1], 2);

    cout << "INITIAL STATE\n";
    print_stacks(stacks);

    hanoi(stacks, INT_MAX, 2);

    cout << "FINAL STATE\n";
    print_stacks(stacks);
}