#include "p1.hpp"

struct Node {
    int id;
    char name[15];
    char position[15];
    Node *next;
};
int findPortero(const char* position) {
    int i = 0;
    char positions[4][15] {
        "Portero", "Defensa", "Mediocampo", "Delantero"
    };
    for (;i<4; i++) {
        if (strcmp(position,positions[i]) == 0) return i;
    }
    return -1;
}
void insert_ordered(Node *&node, int id,const char *name,const char *position) {
    Node *new_node = new Node, *aux{};
    new_node->id = id;
    strcpy(new_node->name,name);
    strcpy(new_node->position,position);
    new_node->next = nullptr;
    if (node == nullptr) {
        node = new_node;
        return;
    }
    aux = node;

    while (aux->next != nullptr) {

        aux = aux->next;
    }
}

void p1() {

}
