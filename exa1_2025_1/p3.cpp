//
// Created by jolumarti on 2026-10-16.
//

#include "p3.hpp"

struct Node {
    int value;
    Node *next;
};

struct Stack {
    Node *head;
};

void construct_stack(Stack &pila) {
    pila.head = nullptr;
}

bool empty(Stack &pila) {
    return pila.head == nullptr;
}
int top(Stack &pila) {
    if (empty(pila)) {
        cout << "Pila vacia" << endl;
        exit(1);
    }
    return pila.head->value;
}

void push(Stack &pila, int value) {
    Node *nuevo = new Node{value, pila.head};
    pila.head = nuevo;
}
void new_push(Stack &pila, Stack &aux, int value) {
    int min = INT_MAX;
    if (!empty(aux)) min = top(aux);
    if (value <= min) {
        push(aux, value);
    }
    push(pila, value);
}

int pop(Stack &pila) {
    if (empty(pila)) {
        cout << "Pila vacia" << endl;

        exit(1);
    }
    Node *temp = pila.head;
    pila.head = pila.head->next;
    int res = temp->value;
    delete temp;
    return res;
}
int new_pop(Stack &pila, Stack &aux) {
    int min = INT_MAX;
    if (!empty(aux)) min = top(aux);
    if (top(pila) == min) {
        pop(aux);
    }
    return pop(pila);
}

int find_min(Stack &pila, Stack &aux) {
    if (empty(pila)) {
        cout << "Pila vacia" << endl;
        exit(1);
    }
    return top(aux);
}

void p3() {
    Stack pila,aux;
    construct_stack(pila);
    construct_stack(aux);
    new_push(pila,aux, 201809);
    new_push(pila,aux, 202010);
    new_push(pila,aux, 202109);
    new_push(pila,aux, 201510);
    new_push(pila,aux, 202409);
    cout << find_min(pila,aux) << endl;
    new_pop(pila,aux);
    new_pop(pila,aux);
    cout << find_min(pila,aux) << endl;
}
