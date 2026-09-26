#include "p1.hpp"

struct Node {
    int ID;
    char Nombre[20];
    char Equipo[20];
    Node* next;
};

Node* pop (Node *&list) {
    if (!list) return nullptr;
    Node *aux = list;
    list = list->next;
    aux->next = nullptr;
    return aux;
}
void push(Node *&list, Node *node) {
    node->next = list;
    list = node;
}
void append(Node *&list, Node *node) {
    node->next = nullptr;
    if (!list) {
        list = node;
        return;
    }
    Node *aux = list;
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    aux->next = node;
}
void add_player(Node *&list, int id, char *name, char *team) {
    Node *aux = new Node;
    aux->ID = id;
    strcpy(aux->Nombre, name);
    strcpy(aux->Equipo, team);
    aux->next = nullptr;
    push(list, aux);
}
void print_list(Node *aux) {
    while (aux != nullptr) {
        printf("[ID: %d, Nombre: %s, Equipo: %s]\n", aux->ID, aux->Nombre, aux->Equipo);
        aux = aux->next;
    }
}
void insert_ordered(Node *&list, Node *node) {
    node->next = nullptr;
    if (!list) {
        list = node;
        return;
    }
    if (node->ID % 2 == 0) {
        Node *cur = list;
        Node *prev = nullptr;
        while (cur && cur->ID % 2 == 0) {
            prev = cur;
            cur = cur->next;
        }
        if (!prev) {
            node->next = list;
            list = node;
        } else {
            node->next = cur;
            prev->next = node;
        }

    }
    else {
        Node *cur = list;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
}
void reverse_list(Node *&list) {
    if (!list || !list->next) return;
    Node *aux = list->next;
    reverse_list(aux);
    list->next->next = list;
    list->next = nullptr;
    list = aux;
}
void order_list(Node *&list) {
    Node *ordered = nullptr;
    while (list) {
        Node *node = pop(list);
        insert_ordered(ordered, node);
    }

    list = ordered;
}
void p1() {
    Node *list = nullptr;
    add_player(list, 17, "Messala", "Rojo");
    add_player(list, 4, "Ben-Hur", "Azul");
    add_player(list, 12, "Artax", "Verde");
    add_player(list, 7, "Drusus", "Negro");
    cout << "Lista Original\n";
    reverse_list(list);
    print_list(list);
    order_list(list);
    cout << "Lista Ordenada\n";
    print_list(list);

}