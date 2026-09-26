#include "p1.hpp"

struct Node {
    int grado;
    int tiempo;
    Node* next;
};
void push(Node*&head, Node* node) {
    if (head == nullptr) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
}
void add_efectivo(Node *&head, int grado, int tiempo) {
    Node* newNode = new Node;
    newNode->grado = grado;
    newNode->tiempo = tiempo;
    newNode->next = nullptr;
    push(head, newNode);
}
void p1() {
    Node *pila{};
    add_efectivo(pila, 1, 10);
    add_efectivo(pila, 2, 20);
    add_efectivo(pila, 3, 15);
}