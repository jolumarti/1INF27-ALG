//
// Created by jolumarti on 2026-10-10.
//

#include "p5.hpp"


struct Node {
    int data;
    int priority;
    Node *next;
};

struct Queue {
    Node *head;
    Node *last1;
    Node *tail;
};

enum dataPriority { PREFERENTE, REGULAR };

bool is_queque_empty(Queue &queue) {
    return queue.head == nullptr;
}

void construct_queue(Queue &queue) {
    queue.head = nullptr;
    queue.last1 = nullptr;
    queue.tail = nullptr;
}



void push(Queue &queue, int data, int priority) {
    Node *node = new Node;
    node->data = data;
    node->priority = priority + 1;
    node->next = nullptr;
    if (is_queque_empty(queue)) {
        queue.head = node;
        queue.tail = node;
        if (priority==PREFERENTE) queue.last1 = node;
        return;
    }
    if (priority == PREFERENTE) {
        if (queue.last1) {
            node->next = queue.last1->next;
            queue.last1->next = node;
            if (queue.tail == queue.last1) queue.tail = node;
            queue.last1 = node;
        } else {
            queue.last1 = node;
            node->next = queue.head;
            queue.head = node;
        }
    } else {
        queue.tail->next = node;
        queue.tail = node;
    }
}
void print_queue(const Queue &queue) {
    Node *aux = queue.head;
    cout << "Estado: [P1:";
    while (aux != nullptr && queue.last1 != nullptr) {
        cout << aux ->data;
        if (aux == queue.last1) break;
        aux = aux->next;
        if (aux) cout << ",";
    }
     cout << "][P2:";
    if (queue.last1) aux = queue.last1->next;
    else aux = queue.head;
    while (aux != nullptr) {
        cout << aux ->data;
        aux = aux->next;
        if (aux) cout << ",";
    }
    cout << "]" << endl;
}
void pop(Queue &queue) {
    if (is_queque_empty(queue)) {
        cout << "A cola esta vacia." << endl;
        return;
    }
    Node *aux = queue.head;
    if (aux == queue.last1) queue.last1 = nullptr;
    if (aux == queue.tail) queue.tail = nullptr;
    queue.head = queue.head->next;
    aux->data;
    cout << "Atendido: " << aux->data << "-P" << aux->priority << endl;
    delete aux;
}

void pop_many(Queue &queue, int num) {
    for (int i = 0; i < num; i++) {
        if (!is_queque_empty(queue)) pop(queue);
    }
}

void p5() {
    Queue queue;
    construct_queue(queue);
    push(queue, 101, REGULAR);
    push(queue, 102, PREFERENTE);
    pop(queue);
    push(queue, 104, REGULAR);
    push(queue, 105, PREFERENTE);
    print_queue(queue);
    pop_many(queue, 3);
    print_queue(queue);
}
