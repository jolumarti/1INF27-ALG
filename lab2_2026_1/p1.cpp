#include "p1.hpp"
#define CANT_CARTAS 52
#define CANT_PALOS 4
#define CANT_VALORES 13

struct Node {
    int num;
    char palo;
    Node *next;
};

struct Baraja {
    Node *head;
    int size;
};

void insertar_carta(Baraja &baraja, int num, char palo) {
    Node *nuevo = new Node{};
    nuevo->num = num;
    nuevo->palo = palo;
    nuevo->next = baraja.head;
    baraja.head = nuevo;
    baraja.size++;
}

void insertar_ultimo(Baraja &baraja, Node *carta) {
    Node *aux = baraja.head;
    while (aux->next) aux = aux->next;
    if (aux) aux->next = carta;
    else baraja.head = carta;
    baraja.size++;
}

Node *extraer_carta(Baraja &baraja, int posicion) {
    if (baraja.size == 0 || posicion < 0 || posicion >= baraja.size) return nullptr;
    Node *aux = baraja.head, *prev{};
    for (int i = 0; i < posicion; i++) {
        prev = aux;
        aux = aux->next;
    }
    if (prev == nullptr) baraja.head = aux->next; // first card
    else prev->next = aux->next;
    baraja.size--;
    aux->next = nullptr;
    return aux;
}

void barajar(Baraja &baraja) {
    int cant = baraja.size;
    int i = 0;
    for (int i = 0; i < cant; i++) {
        int posicion = rand() % (cant - i);
        Node *aux = extraer_carta(baraja, posicion);
        insertar_ultimo(baraja, aux);
    }
}

void destruir_baraja(Baraja &baraja) {
    Node *aux = baraja.head;
    while (aux) {
        Node *temp = aux;
        aux = aux->next;
        delete temp;
        baraja.size--;
    }
    baraja.head = nullptr;
}

void crear_baraja(Baraja &baraja) {
    baraja.size = 0;
    baraja.head = nullptr;
    char palos[CANT_PALOS]{'C', 'D', 'T', 'E'};
    for (int i = 0; i < CANT_CARTAS; i++) {
        int num = i % CANT_VALORES + 1;
        char palo = palos[i / CANT_VALORES];
        insertar_carta(baraja, num, palo);
    }
}

void imprimir_baraja(Baraja &baraja) {
    Node *aux = baraja.head;
    if (!aux) {
        cout << "BARAJA VACIA" << endl;
        return;
    }
    while (aux) {
        cout << aux->palo << aux->num << " ";
        aux = aux->next;
    }
    cout << endl;
}

void p1() {
    Baraja baraja{};
    srand(time(nullptr));
    crear_baraja(baraja);
    imprimir_baraja(baraja);
    barajar(baraja);
    imprimir_baraja(baraja);
    destruir_baraja(baraja);
    imprimir_baraja(baraja);
}
