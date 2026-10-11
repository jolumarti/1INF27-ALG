//
// Created by jolumarti on 10/5/26.
//

#include "p4.hpp"

struct Node {
    int value;
    Node *next;
};

struct Stack {
    Node *head = nullptr;
};

bool empty(Stack &pila) {
    return pila.head == nullptr;
}

void push(Stack &pila, int value) {
    Node *nuevo = new Node{value, pila.head};
    pila.head = nuevo;
}

void pop(Stack &pila) {
    if (empty(pila)) return;

    Node *temp = pila.head;
    pila.head = pila.head->next;
    delete temp;
}

int top(Stack &pila) {
    return pila.head->value;
}

int areaMaxima(int **matriz, int n, int m) {
    int *alturas = new int[m]();
    int maxArea = 0;

    Stack pila;

    for (int i = 0; i < n; i++) {

        // Actualizar alturas
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 1)
                alturas[j]++;
            else
                alturas[j] = 0;
        }

        // Calcular rectangulo maximo
        for (int j = 0; j <= m; j++) {

            int alturaActual = (j == m) ? 0 : alturas[j];

            while (!empty(pila) &&
                   alturas[top(pila)] > alturaActual) {

                int altura = alturas[top(pila)];
                pop(pila);

                int ancho;

                if (empty(pila))
                    ancho = j;
                else
                    ancho = j - top(pila) - 1;

                int area = altura * ancho;

                if (area > maxArea)
                    maxArea = area;
            }

            if (j < m) push(pila, j);
        }

        // Vaciar la pila para la siguiente fila
        while (!empty(pila))
            pop(pila);
    }

    delete[] alturas;
    return maxArea;
}

void p4() {
    int n = 4;
    int m = 4;

    int data[][4] = {
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0}
    };

    // Crear matriz de punteros a las filas
    int **matriz = new int*[n];

    for (int i = 0; i < n; i++)
        matriz[i] = data[i];

    cout << "Area maxima: "
         << areaMaxima(matriz, n, m) << endl;

    delete[] matriz;
}