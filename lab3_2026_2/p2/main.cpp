#include <iostream>
#include <cmath>

using namespace std;



struct Node {
    int value;
    Node *next;
};

struct Pila {
    Node *head;
};

void construct_pila(Pila &pila) {
    pila.head = nullptr;
}

bool is_pila_empty(Pila &pila) {
    return pila.head == nullptr;
}

int pop(Pila &pila) {
    if (pila.head == nullptr) {
        cout << "Pila is empty" << endl;
        exit(1);
    }
    Node *temp = pila.head;
    pila.head = pila.head->next;
    int data = temp->value;
    delete temp;
    return data;
}


void push(Pila &pila, int ele) {
    Node *new_node = new Node;
    new_node->value = ele;
    new_node->next = pila.head;
    pila.head = new_node;
}

void print_pila(Pila &pila) {
    Node *temp = pila.head;
    while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp) cout << " ";
    }
    cout << endl;
}

void insertar_pila(Pila &pila, int cur) {
    //print_pila(pila);
    if (is_pila_empty(pila)) {
        push(pila, cur);
        return;
    }
    int prev = pop(pila);
    while (prev>0 && cur <0) {
        int dif = abs(cur) -  abs(prev);
        if (dif > 0) {
            if (is_pila_empty(pila)) {
                push(pila, cur);
                return;
            }
            prev = pop(pila);
        } else if (dif < 0) {
            push(pila, prev);
            return;
        } else return;
    }
    push(pila, prev);
    push(pila, cur);
}

void procesar(int arr[], int num) {
    Pila pila;
    construct_pila(pila);
    for (int i = 0; i < num; i++) {
        insertar_pila(pila, arr[i]);
    }
    print_pila(pila);
}

int main() {
    int arr1[] = {12, 7, -5, -15, 4, -3, 9, -20, 6, 2, -1};
    int num1 = sizeof(arr1) / sizeof(arr1[0]);

    procesar(arr1, num1);

    int arr2[] = {-5, 9, 27, -27, -20};
    int num2 = sizeof(arr2) / sizeof(arr2[0]);
    procesar(arr2, num2);


    return 0;
}
