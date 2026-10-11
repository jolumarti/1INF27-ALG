//
// Created by jolumarti on 2026-10-10.
//

#include "p5.hpp"

struct Ele {
    int value;
    int priority;
};

struct Node {
    Ele ele;
    Node *next;
};

struct Queue {
    Node *head;
    Node *last1;
    Node *tail;
};
enum dataPriority {PREFERENTE, REGULAR};

void constructQueue(Queue &queue) {
    queue.head = nullptr;
    queue.last1 = nullptr;
    queue.tail = nullptr;
}
void print_queue(const Queue &queue) {
    Node *aux = queue.head;
    cout << "Estado: ";
    while (aux != nullptr) {
        cout << "[" << aux->ele.value << " ";
        aux = aux->next;
        if (aux) cout << "][";
    }
    cout << std::endl;
}


void p5() {

}