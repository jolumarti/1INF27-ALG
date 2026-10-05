#include <iostream>
#include <cstring>
#include "BibliotecaLista/Inventory.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

enum dataIngredientes { COD, CANT };

void crear_postre(struct ElementoLista &postre, const char *codigo, const char *nombre) {
    strcpy(postre.codigo, codigo);
    strcpy(postre.nombre, nombre);
    postre.cant_ingredientes = 0;
}

void agregar_ingrediente(struct ElementoLista &postre, int cod, int cant) {
    postre.ingredientes[postre.cant_ingredientes][COD] = cod;
    postre.ingredientes[postre.cant_ingredientes][CANT] = cant;
    postre.cant_ingredientes++;
}

int buscar_ingrediente(struct Inventory *stock, int size_stock, int cod) {
    for (int i = 0; i < size_stock; i++) {
        if (stock[i].codigo == cod) return i;
    }
    return -1;
}

void elaborar_postre(ElementoLista postre, struct Inventory *stock, int num_inv) {
    for (int i = 0; i < postre.cant_ingredientes; i++) {
        int cant = postre.ingredientes[i][CANT];
        int cod = postre.ingredientes[i][COD];
        int pos = buscar_ingrediente(stock, num_inv, cod);
        if (pos != -1) stock[pos].cantidad -= cant;
    }
}

bool puede_elaborarse(ElementoLista postre, struct Inventory *stock, int num_inv) {
    for (int i = 0; i < postre.cant_ingredientes; i++) {
        int cant = postre.ingredientes[i][CANT];
        int cod = postre.ingredientes[i][COD];
        int pos = buscar_ingrediente(stock, num_inv, cod);
        if (pos == -1 || cant > stock[pos].cantidad) {
            return false;
        }
    }
    return true;
}

void cargar_postres(ElementoLista &ele1, ElementoLista &ele2, ElementoLista &ele3, ElementoLista &ele4,
                    ElementoLista &ele5, ElementoLista &ele6) {
    crear_postre(ele1, "P001", "Crema Volteada");
    agregar_ingrediente(ele1, 1002, 810);
    agregar_ingrediente(ele1, 1003, 990);
    agregar_ingrediente(ele1, 1101, 15);
    agregar_ingrediente(ele1, 1201, 12);
    agregar_ingrediente(ele1, 1301, 400);

    crear_postre(ele2, "P002", "Trufas de chocolate");
    agregar_ingrediente(ele2, 1014, 330);
    agregar_ingrediente(ele2, 1701, 600);
    agregar_ingrediente(ele2, 1101, 5);

    crear_postre(ele3, "P003", "Keke de Vainilla");
    agregar_ingrediente(ele3, 1501, 200);
    agregar_ingrediente(ele3, 1301, 600);
    agregar_ingrediente(ele3, 1401, 375);
    agregar_ingrediente(ele3, 1014, 250);
    agregar_ingrediente(ele3, 1101, 10);

    crear_postre(ele4, "P004", "Profiterol");
    agregar_ingrediente(ele4, 1501, 100);
    agregar_ingrediente(ele4, 1401, 125);
    agregar_ingrediente(ele4, 1201, 4);

    crear_postre(ele5, "P005", "Alfajores");
    agregar_ingrediente(ele5, 1401, 188);
    agregar_ingrediente(ele5, 1302, 40);
    agregar_ingrediente(ele5, 1501, 250);
    agregar_ingrediente(ele5, 1101, 15);

    crear_postre(ele6, "P006", "Mousse de limon");
    agregar_ingrediente(ele6, 3001, 10);
    agregar_ingrediente(ele6, 1002, 330);
    agregar_ingrediente(ele6, 1004, 270);
}

int main() {
    Inventory inventory[]{
        {.nombre = "Harina Preparada", .codigo = 1401, .cantidad = 500},
        {.nombre = "Mantequilla", .codigo = 1501, .cantidad = 3500},
        {.nombre = "Huevos", .codigo = 1201, .cantidad = 40},
        {.nombre = "Aceite", .codigo = 1601, .cantidad = 2500},
        {.nombre = "Chocolate bitter", .codigo = 1701, .cantidad = 500},
        {.nombre = "Azucar blanca", .codigo = 1301, .cantidad = 3000},
        {.nombre = "Azucar en polvo", .codigo = 1302, .cantidad = 1000},
        {.nombre = "Cocoa", .codigo = 1702, .cantidad = 900},
        {.nombre = "Leche fresca", .codigo = 1001, .cantidad = 900},
        {.nombre = "Leche condensada", .codigo = 1002, .cantidad = 900},
        {.nombre = "Leche evaporada", .codigo = 1003, .cantidad = 900},
        {.nombre = "Crema de leche", .codigo = 1004, .cantidad = 1800},
        {.nombre = "Vainilla", .codigo = 1101, .cantidad = 100},
        {.nombre = "Limones", .codigo = 3001, .cantidad = 10},
    };
    int num_inventory = sizeof(inventory) / sizeof(inventory[0]);
    ElementoLista ele1, ele2, ele3, ele4, ele5, ele6;
    cargar_postres(ele1, ele2, ele3, ele4, ele5, ele6);

    Lista lista;
    construir(lista);
    insertarEnOrden(lista, ele5);
    insertarEnOrden(lista, ele1);
    insertarEnOrden(lista, ele3);
    insertarEnOrden(lista, ele6);
    insertarEnOrden(lista, ele4);
    insertarEnOrden(lista, ele2);

    imprimir(lista);
    int elaborados = 0;
    NodoLista *cur = lista.inicio, *prev{};
    while (cur && elaborados < 3) {
        if (puede_elaborarse(cur->elemento, inventory, num_inventory)) {
            elaborar_postre( cur->elemento, inventory, num_inventory);

            NodoLista *mover = cur;
            if (prev)prev->siguiente = cur->siguiente;
            else lista.inicio = cur->siguiente;
            cur = cur->siguiente;
            mover->siguiente = lista.inicio;
            lista.inicio = mover;
            elaborados++;
        } else {
            prev = cur;
            cur = cur->siguiente;
        }
    }
    cout << "Cantidad Elaborados: " << elaborados << endl;
    imprimir(lista);
}
