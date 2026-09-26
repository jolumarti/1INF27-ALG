
#include <iostream>
#include <cstring>
#include "BibliotecaLista/Ingrediente.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

enum dataIngredientes { COD, CANT };

void crear_postre(struct ElementoLista &postre, const char *codigo, const char *nombre) {
    strcpy(postre.codigo, codigo);
    strcpy(postre.nombre, nombre);
    postre.cant_ingredientes = 0;
}

void agregar_ingr(struct ElementoLista &postre, int cod, int cant) {
    postre.ingredientes[postre.cant_ingredientes][COD] = cod;
    postre.ingredientes[postre.cant_ingredientes][CANT] = cant;
    postre.cant_ingredientes++;
}

int buscar_ingrediente(struct Ingrediente *stock, int size_stock, int cod) {
    for (int i = 0; i < size_stock; i++) {
        if (stock[i].codigo == cod) return i;
    }
    return -1;
}

void elaborar_postre(ElementoLista postre, struct Ingrediente *stock, int size_stock) {
    bool result = true;
    for (int i = 0; i < postre.cant_ingredientes; i++) {
        int cant = postre.ingredientes[i][COD];
        int cod = postre.ingredientes[i][COD];
        int pos = buscar_ingrediente(stock, size_stock, cod);
        if (pos != -1) {
            if (cant <= stock[pos].cantidad) {
                stock[pos].cantidad -= cant;
            }
        }
    }
}

bool puede_elaborarse(ElementoLista postre, struct Ingrediente *stock, int size_stock) {
    bool result = true;
    for (int i = 0; i < postre.cant_ingredientes; i++) {
        int cant = postre.ingredientes[i][CANT];
        int cod = postre.ingredientes[i][COD];
        int pos = buscar_ingrediente(stock, size_stock, cod);
        if (pos != -1) {
            if (cant > stock[pos].cantidad) {
                result = false;
                break;
            }
        } else {
            result = false;
            break;
        }
    }
    return result;
}
int main() {
    Ingrediente stock[]{
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
    int size_stock = sizeof(stock) / sizeof(stock[0]);
    struct Lista lista;
    construir(lista);
    struct ElementoLista ele1{};
    crear_postre(ele1, "P001", "Crema Volteada");
    agregar_ingr(ele1, 1002, 810);
    agregar_ingr(ele1, 1003, 990);
    agregar_ingr(ele1, 1101, 15);
    agregar_ingr(ele1, 1201, 12);
    agregar_ingr(ele1, 1301, 400);

    struct ElementoLista ele2{};
    crear_postre(ele2, "P002", "Trufas de chocolate");
    agregar_ingr(ele2, 1014,330 );
    agregar_ingr(ele2, 1701,600 );
    agregar_ingr(ele2, 1101, 5);


    
    struct ElementoLista ele3{};
    crear_postre(ele3, "P003", "Keke de Vainilla");
    agregar_ingr(ele3, 1501,200 );
    agregar_ingr(ele3, 1301,600 );
    agregar_ingr(ele3, 1401,375 );
    agregar_ingr(ele3, 1014,250 );
    agregar_ingr(ele3, 1101,10 );
    
    struct ElementoLista ele4{};
    crear_postre(ele4, "P004", "Profiterol");
    agregar_ingr(ele4, 1501,100 );
    agregar_ingr(ele4, 1401,125 );
    agregar_ingr(ele4, 1201,4 );

    struct ElementoLista ele5{};
    crear_postre(ele5, "P005", "Alfajores");
    agregar_ingr(ele5, 1401,188 );
    agregar_ingr(ele5, 1302,40 );
    agregar_ingr(ele5, 1501,250 );
    agregar_ingr(ele5, 1101,15 );

    
    
    struct ElementoLista ele6{};
    crear_postre(ele6, "P006", "Mousse de limon");
    agregar_ingr(ele6, 3001,10 );
    agregar_ingr(ele6, 1002,330 );
    agregar_ingr(ele6, 1004,270 );

    

    insertarEnOrden(lista, ele5);
    insertarEnOrden(lista, ele1);
    insertarEnOrden(lista, ele3);
    insertarEnOrden(lista, ele6);
    insertarEnOrden(lista, ele4);
    insertarEnOrden(lista, ele2);
    imprimir(lista);
    int cant_elaborados = 0;
    NodoLista *aux = lista.inicio;
    while (aux) {
        if (puede_elaborarse(aux->elemento, stock, size_stock)){
            ElementoLista aux_elemento = aux->elemento;
            elaborar_postre(aux_elemento, stock, size_stock);
            aux = aux->siguiente;
            eliminaNodo(lista, aux_elemento);
            insertarAlInicio(lista, aux_elemento);
            cant_elaborados++;
            if (cant_elaborados >= 3)break;
        } else aux = aux->siguiente;
    }
    cout << "Cantidad Elaborados: " << cant_elaborados << endl;
    imprimir(lista);
}


// int main(int argc, char **argv) {
//
//     struct ElementoLista elemento{};
//     struct Lista listaInicio, listaFinal, listaEnOrden;
//
//     construir(listaInicio);
//     construir(listaFinal);
//     construir(listaEnOrden);
//     cout << "La lista esta vacia: " << esListaVacia(listaInicio) << endl;
//
//     for (int i = 1; i < 10; i+=2) {
//         elemento.codigo = i;
//         insertarAlInicio(listaInicio, elemento);
//     }
//     imprimir(listaInicio);
//
//     /*Inserta datos desde el final de la lista*/
//     for (int i = 4; i < 7; i++) {
//         elemento.codigo = i;
//         insertarAlFinal(listaFinal, elemento);
//     }
//     imprimir(listaFinal);
//
//     elemento.codigo = 75;
//     insertarEnOrden(listaEnOrden, elemento);
//     elemento.codigo = 5;
//     insertarEnOrden(listaEnOrden, elemento);
//     elemento.codigo = 25;
//     insertarEnOrden(listaEnOrden, elemento);
//     elemento.codigo = 85;
//     insertarEnOrden(listaEnOrden, elemento);
//
//
//     imprimir(listaEnOrden);
//
//     /*Elimina un nodo de la lista correspondiente al elemento ingresado*
//     // [1, 10, 6]
//     /*para que pueda eliminar busca el elemento dentro de la lista para eliminarlo*/
//     elemento.codigo = 85;
//     eliminaNodo(listaEnOrden, elemento);
//     imprimir(listaEnOrden);
//
//     destruir(listaEnOrden);
//     imprimir(listaEnOrden);
//     return 0;
// }
