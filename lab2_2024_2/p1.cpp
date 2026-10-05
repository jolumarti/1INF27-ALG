#include "p1.hpp"

struct Node {
    int grado;
    int tiempo;
    Node *next;
};

void push(Node *&head, Node *node) {
    if (head == nullptr) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
}

void add_efectivo(Node *&head, int grado, int tiempo) {
    Node *newNode = new Node;
    newNode->grado = grado;
    newNode->tiempo = tiempo;
    newNode->next = nullptr;
    push(head, newNode);
}
void reverse(Node *&head) {
    if (head == nullptr || head->next == nullptr) return;
    Node* aux = head -> next;
    reverse(aux);
    head->next->next = head;
    head->next = nullptr;
    head = aux;
}
int count_subgroups(Node *head) {
    if (head == nullptr) return 0;
    Node *aux = head, *prev{};
    int count = 1;
    while (aux) {
        if (prev) {
            if ((aux->grado < head->grado) ||
                ( (aux->grado <= head->grado) &&
                    (aux->grado == prev->grado) &&
                    (aux->tiempo < prev->tiempo))) {
                count++;
            } else break;
        }
        prev = aux;
        aux = aux->next;
    }
    return count;
}

void count_groups(Node *head) {
    reverse(head);
    Node *aux = head;
    int count = 0;
    while (aux) {
        count+= count_subgroups(aux);
        aux = aux->next;
    }
    cout << "Number of groups: " << count << endl;
}

void p1() {
    Node *pila{};
    add_efectivo(pila, 2, 4);
    add_efectivo(pila, 2, 1);
    add_efectivo(pila, 2, 4);
    count_groups(pila);
    Node *pila2{};
    add_efectivo(pila2, 1, 1);
    add_efectivo(pila2, 2, 3);
    add_efectivo(pila2, 2, 5);
    add_efectivo(pila2, 1, 2);
    count_groups(pila2);
    Node *pila3{};
    add_efectivo(pila3, 3, 1);
    add_efectivo(pila3, 2, 1);
    add_efectivo(pila3, 2, 4);
    count_groups(pila3);
}
