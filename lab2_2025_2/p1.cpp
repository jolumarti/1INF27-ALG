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
void insert_ordered(Node *&head, int id,const char *name,const char *position) {
    Node *new_node = new Node, *aux = head;
    new_node->id = id;
    strcpy(new_node->name,name);
    strcpy(new_node->position,position);
    new_node->next = nullptr;
    int new_pos = findPortero(position);
    if (head == nullptr || new_pos <= findPortero(head->position)) {
        new_node->next = head;
        head = new_node;
        return;
    }
    while (aux->next && new_pos > findPortero(aux->position)) {
        aux = aux->next;
    }
    new_node->next = aux->next;
    aux->next = new_node;
}
void print_results(Node *node) {
    while (node) {
        printf("%d %s %s\n",node->id,node->name,node->position);
        node = node->next;
    }
}
void p1() {
    Node *node{};
    insert_ordered(node,7, "Martinez","Delantero");
    insert_ordered(node,1, "Ramirez","Portero");
    insert_ordered(node,5, "Perez","Defensa");
    insert_ordered(node,8, "Torres","Mediocampo");
    insert_ordered(node,9, "Lopez","Delantero");
    insert_ordered(node,3, "Gomez","Defensa");
    print_results(node);
}
