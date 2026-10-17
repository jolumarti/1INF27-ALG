//
// Created by jolumarti on 2026-10-16.
//

#include "p2a.hpp"

struct Element {
    int codigo;
    int cantidad;
    char prioridad;
};

struct Node {
    Element ele;
    Node *next;
};

struct List {
    Node *head;
};

void construct_list(List &list) {
    list.head = nullptr;
}

bool is_list_empty(List &list) {
    return list.head == nullptr;
}

void push_node(Node *&node, Node *new_node) {
    new_node->next = node;
    node = new_node;
}

Node *pop_node(Node *&node) {
    if (!node) return nullptr;
    Node *temp = node;
    node = node->next;
    temp->next = nullptr;
    return temp;
}

void push_list(List &list, int codigo, int cantidad, char prioridad) {
    Node *node = new Node;
    node->ele.codigo = codigo;
    node->ele.cantidad = cantidad;
    node->ele.prioridad = prioridad;
    push_node(list.head, node);
}

void print_list(List &list) {
    Node *node = list.head;
    cout << "Codigo  Cantidad Prioridad" << endl;
    while (node) {
        cout << node->ele.codigo << " " << node->ele.cantidad << " " << node->ele.prioridad << endl;
        node = node->next;
    }
}
// ia solution
void process_list2(List &list) {
    Node *current = list.head;
    list.head = nullptr;
    Node *tailA = nullptr;
    Node *tailGroups = nullptr;
    Node *tail = nullptr;
    char previous = 0;
    while (current) {
        Node *next = current->next;
        current->next = nullptr;
        char p = current->ele.prioridad;
        bool isGroup = p != 'A' && (previous == p || (next && next->ele.prioridad == p));
        if (p == 'A') {
            if (tailA) {
                current->next = tailA->next;
                tailA->next = current;
            } else {
                current->next = list.head;
                list.head = current;
            }
            tailA = current;
        } else if (isGroup) {
            Node *anchor = tailGroups ? tailGroups : tailA;
            if (anchor) {
                current->next = anchor->next;
                anchor->next = current;
            } else {
                current->next = list.head;
                list.head = current;
            }
            tailGroups = current;
        } else {
            if (tail) tail->next = current;
            else list.head = current;
        }
        if (!current->next) tail = current;
        previous = p;
        current = next;
    }
}

// my solution
void process_list(List &list) {
    Node *node = list.head;
    Node *n_A = nullptr;
    Node *n_pairs = nullptr;
    Node *n_leftovers = nullptr;
    char prev_prioridad = 0;
    while (node) {
        Node *cur = pop_node(node);
        if (cur->ele.prioridad == 'A') {
            push_node(n_A, cur);
        } else {
            if (prev_prioridad == cur->ele.prioridad || node && node->ele.prioridad == cur->ele.prioridad)
                push_node(n_pairs, cur);
            else push_node(n_leftovers, cur);
        }
        prev_prioridad = cur->ele.prioridad;
    }
    list.head = nullptr;
    while (n_leftovers) {
        push_node(list.head, pop_node(n_leftovers));
    }
    while (n_pairs) {
        push_node(list.head, pop_node(n_pairs));
    }
    while (n_A) {
        push_node(list.head, pop_node(n_A));
    }
}

void p2a() {
    List list;
    construct_list(list);
    push_list(list, 9, 2, 'B');
    push_list(list, 8, 4, 'C');
    push_list(list, 7, 8, 'C');
    push_list(list, 6, 6, 'A');
    push_list(list, 5, 5, 'C');
    push_list(list, 4, 12, 'B');
    push_list(list, 3, 15, 'B');
    push_list(list, 2, 20, 'A');
    push_list(list, 1, 10, 'B');
    print_list(list);
    process_list(list);
    print_list(list);
}
