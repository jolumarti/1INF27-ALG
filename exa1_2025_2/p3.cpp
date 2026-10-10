//
// Created by jolumarti on 10/5/26.
//

#include "p3.hpp"

struct Ele {
    int value;
    char type;
};

struct Node {
    Ele ele;
    Node *next;
};

struct Stack {
    Node *head;
};

void construct_stack(Stack &stack) {
    stack.head = nullptr;
}

void push_node(Stack &stack, Node *node) {
    node->next = stack.head;
    stack.head = node;
}

void push_ele(Stack &stack, int value, char type) {
    Node *node = new Node{};
    node->ele.value = value;
    node->ele.type = type;
    push_node(stack, node);
}

Node *get_ele(Stack &stack, char type) {
    Node *cur = stack.head, *prev{};
    while (cur) {
        if (cur->ele.type == type) {
            if (prev) prev->next = cur->next;
            else stack.head = cur->next;
            cur->next = nullptr;
            return cur;
        }
        prev = cur;
        cur = cur->next;
    }
    return nullptr;
}
void print_stack(Stack &stack) {
    Node *cur = stack.head;
    while (cur) {
        cout << cur->ele.value << cur->ele.type << "->";
        cur = cur->next;
    }
    cout << "0" << endl;
}

void reordenaLista(Stack &stack, int num) {
    char types[]{'A', 'B', 'C'};
    if (stack.head) {
        Node *aux = get_ele(stack, types[num % 3]);
        //print_stack(stack);
        reordenaLista(stack, num + 1);
        if (aux) push_node(stack, aux);
    }
}


void p3() {
    Stack stack{}, stack2{};
    construct_stack(stack);;
    push_ele(stack, 6, 'B');
    push_ele(stack, 5, 'A');
    push_ele(stack, 9, 'C');
    push_ele(stack, 2, 'A');
    push_ele(stack, 7, 'B');
    print_stack(stack);
    reordenaLista(stack, 0);
    print_stack(stack);

    construct_stack(stack2);;
    push_ele(stack2, 4, 'A');
    push_ele(stack2, 8, 'C');
    push_ele(stack2, 9, 'A');
    push_ele(stack2, 3, 'C');
    print_stack(stack2);
    reordenaLista(stack2, 0);
    print_stack(stack2);
}
