//
// Created by jolumarti on 9/9/26.
//

#include "p1.hpp"
#define SECURITY_SIZE 8
#define CAT_SIZE 3

void chromoDec2Bin(int num, int n, int *chromo) {
    for (int i = 0; i < n; i++) {
        chromo[i] = num % 2;
        num /= 2;
    }
}

void searchCombinations(int data[][3], int dataSize, int P, int B, int F) {
    //P=50000; B=100; F=3;
    int posibilities = (int) pow(2, dataSize);
    int chromo[dataSize], solutions{};
    for (int i = 0; i < posibilities; i++) {
        int totalP{}, totalB{}, totalF{};
        chromoDec2Bin(i, dataSize, chromo); // numero a binaria de las posibilidades
        for (int j = 0; j < dataSize; j++) {
            totalP += chromo[j] * data[j][0]; // solo suma si es el chromo indicado
            totalB += chromo[j] * data[j][1];
            totalF += chromo[j] * data[j][2];
        }
        if (totalP <= P and totalB >= B and totalF <= F) { // imprime cuando esta dentro de los limites
            cout << "Recursos: {";
            bool first = true;
            for (int j = 0; j < dataSize; j++) {
                if (chromo[j] != 0) {
                    if (!first) cout << ",";
                    cout << j + 1;
                    first = false;
                }
            }
            cout << "}, Costo Total: " << totalP << ", Beneficio: " << totalB << ", Falsos Negativos: " << totalF <<
                    endl;
            solutions++;
        }
    }
    if (!solutions) cout << "No se pueden seleccionar controles de seguridad que cumplan todas las restricciones." << endl;
}

void p1() {
    //int data[SECURITY_SIZE][CAT_SIZE] = {
    int data[][CAT_SIZE] = {
        {35000, 80, 1},
        {24000, 60, 3},
        {30000, 70, 2},
        {27000, 48, 1},
        {10000, 20, 1},
        {7000, 35, 2},
        {6000, 10, 1},
        {40000, 40, 3},
    };
    int dataSize = sizeof(data) / sizeof(data[0]); // usando sizeof en vez de SECURITY_SIZE

    while (true) {
        int P, B, F;
        cout << "Ingrese el monto maximo de presupuesto (P): ";
        cin >> P;
        cout << "Ingrese el ancho de banda minimo (B): ";
        cin >> B;
        cout << "Ingrese el numero maximo de falsos negativos (F): ";
        cin >> F;
        if (P < 0 || B < 0 || F < 0) {
            cout << "Los valores no deben ser negativos." << std::endl;
            continue; // Ask for input again
        }
        searchCombinations(data, dataSize, P, B, F);
        cout << "¿Desea ingresar otro conjunto de valores? (s/n): ";
        char choice;
        cin >> choice;
        if (choice != 's' && choice != 'S') {
            break; // Exit the loop
        }
    }
}
