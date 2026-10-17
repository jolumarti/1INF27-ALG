//
// Created by jolumarti on 2026-10-16.
//

#include "p2b.hpp"



struct Node {
    int temp;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
    int cap;
    int num;
    int total;
};

bool is_queque_empty(Queue &queue) {
    return queue.head == nullptr;
}

void construct_queue(Queue &queue, int cap) {
    queue.head = nullptr;
    queue.tail = nullptr;
    queue.cap = cap;
    queue.num = 0;
    queue.total = 0;
}

void pop(Queue &queue) {
    if (is_queque_empty(queue)) {
        cout << "A cola esta vacia." << endl;
        return;
    }
    Node *aux = queue.head;
    queue.total-= aux->temp;
    queue.num--;

    if (aux == queue.tail) queue.tail = nullptr;
    queue.head = queue.head->next;

    delete aux;
}

void push(Queue &queue, int temp) {
    Node *node = new Node;
    node->temp = temp;
    node->next = nullptr;
    queue.total+= temp;
    queue.num++;

    if (is_queque_empty(queue)) {
        queue.head = node;
        queue.tail = node;
        return;
    }
    queue.tail->next = node;
    queue.tail = node;

}
double calcularPromedio(Queue &queue) {
    if (!queue.num) {
        cout << "A cola esta vacia." << endl;
        exit(1);

    }
    return (double)queue.total / queue.num;
}
void agregarTemperatura(Queue &queue, int temp) {
    if (queue.num == queue.cap) {
        pop(queue);
    }
    push(queue, temp);
}

void p2b() {
    Queue queue;
    int temp, k;
    while (true) {
        cout << "Ingrese K: ";
        cin >> k;
        if (k>0) {
            construct_queue(queue, k);
            break;
        } else cout << "Ingrese un numero entero mayor a cero." << endl;
    }
    while (true) {
        cout << "Ingrese Temperatura: ";
        cin >> temp;
        if (temp == -1) break;
        agregarTemperatura(queue, temp);
        cout << "Promedio: " << calcularPromedio(queue) << endl;
    }
}