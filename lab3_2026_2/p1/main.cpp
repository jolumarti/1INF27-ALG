#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

struct List {
    Node *head;
    Node *mid;
};

void construct_list(List &list) {
    list.head = nullptr;
    list.mid = nullptr;
}

bool is_empty_list(List &list) {
    return list.head == nullptr;
}

Node* pop(List &list) {
    if (list.head == nullptr) {
        cout << "List is empty" << endl;
        exit(1);
    }
    Node *temp = list.head;
    list.head = list.head->next;
    temp->next = nullptr;
    return temp;
}


void push(List &list, int data) {
    Node *new_node = new Node;
    new_node->value = data;
    new_node->next = list.head;
    list.head = new_node;
}
void push_head(List &list,  Node *node) {
    node->next = list.head;
    list.head = node;
    if (!list.mid) list.mid = node;
}
void push_mid(List &list,  Node*node) {
    if (is_empty_list(list)) {
        list.head = node;
        return;
    }
    if (list.mid) {
        node->next = list.mid->next;
        list.mid->next = node;
    } else {
        node->next = list.head;
        list.head = node;
    }
}

// int aislarEquipos(List &list) {
//     if (is_empty_list(list)) return 0;
//     int cont = 0;
//     Node* node = pop(list);
//     cont += aislarEquipos(list);
//     if (node->value < 0) {
//         cont++;
//         push_head(list, node);
//     } else push_mid(list, node);
//     return cont;
// }
// SIN AUXILIARES
int aislarEquipos(List &list) {
    if (is_empty_list(list)) {
        list.mid = nullptr; //reinicio si se vuelve usar funcion.
        return 0;
    }
    Node* node = pop(list);
    int cont = aislarEquipos(list);
    if (node->value < 0) {
        cont++;
        node->next = list.head;
        list.head = node;
        if (!list.mid) list.mid = node;
    } else {
       if (list.mid) {
            node->next = list.mid->next;
            list.mid->next = node;
        } else {
            node->next = list.head;
            list.head = node;
        }
    }
    return cont;
}

void print_list(List &list) {
    Node *temp = list.head;
    while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp) cout << " -> ";
    }
    cout << endl;
}


void print_reorder(List &list) {
    cout << "Lista original: \n";
    print_list(list);
    int count = aislarEquipos(list);
    cout << "Lista reorganizada: \n";
    print_list(list);
    cout << "Equipos comprometidos: "<< count <<"\n\n";
}

int main() {
    List list;
    construct_list(list);
    push(list, 106);
    push(list, -105);
    push(list, -104);
    push(list, 103);
    push(list, -102);
    push(list, 101);
    print_reorder(list);

    List list2;
    construct_list(list2);
    push(list2, 204);
    push(list2, 203);
    push(list2, 202);
    push(list2, 201);
    print_reorder(list2);
    List list3;
    construct_list(list3);
    push(list3, -304);
    push(list3, -303);
    push(list3, -302);
    push(list3, -301);
    print_reorder(list3);
    List list4;
    construct_list(list4);
    push(list4, -405);
    push(list4, -404);
    push(list4, 403);
    push(list4, 402);
    push(list4, 401);
    print_reorder(list4);

    return 0;
}
