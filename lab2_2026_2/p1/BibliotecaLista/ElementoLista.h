//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H
struct ElementoLista {
    char codigo[6];
    char nombre[20];
    int ingredientes[20][2];
    int cant_ingredientes;
};
#endif //LISTASIMPLEMENTEENLAZADA_ELEMENTOLISTA_H