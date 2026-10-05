//
// Created by jolumarti on 9/28/26.
//

#include "p2.hpp"

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *head;
    char almacen;
};

void construct_stack(Stack *&stack, int num, char al) {
    stack = new Stack;
    stack->almacen = al;
    Node *aux = nullptr;
    for (int i = num; i > 0; i--) {
        aux = new Node{
            .data = i,
            .next = aux,
        };
    }
    stack->head = aux;
}

void print_stack(Stack *stack) {
    Node *aux = stack->head;
    cout << "ALMANCEN " << stack->almacen  <<": ";
    while (aux) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

void move_node(Stack *&src, Stack *&dst) {
    if (!src->head) return;
    Node *aux = src->head;
    src->head = src->head->next;
    aux->next = dst->head;
    dst->head = aux;
    cout << "Mover " << aux->data << ": " << src->almacen << " -> " << dst->almacen << endl;
}

void move_stack(Stack *&src, Stack *&mid, Stack *&dst, int n) {
    if (n == 0)
        return;

    //mover n-1 paq de src a dst
    move_stack(src, mid, dst, n - 1);

    //mover n paq de src a mid
    move_node(src, mid);

    //mover n-1 paq de dst a src
    move_stack(dst, mid, src, n - 1);

    //mover n paq de mid a dst
    move_node(mid, dst);

    // mover n-1 de src a dst
    move_stack(src, mid, dst, n - 1);
}

void p2() {
    int num = 2;

    Stack *a1, *a2, *a3;

    construct_stack(a1, num, 'A');
    construct_stack(a2, 0, 'B');
    construct_stack(a3, 0, 'C');

    cout << "Estado inicial:" << endl;

    print_stack(a1);
    print_stack(a2);
    print_stack(a3);

    cout << endl << "MOVIMIENTOS:" << endl;

    move_stack(a1,a2,a3,num);

    cout << endl << "Estado final:" << endl;

    print_stack(a1);
    print_stack(a2);
    print_stack(a3);
}
