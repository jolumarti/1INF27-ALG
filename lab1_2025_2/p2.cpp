//
// Created by jolumarti on 9/9/26.
//

#include "p2.hpp"
#define N 6
#define M 11

int changeGallery(char c, int x, int y, char matriz[N][M]) {
    // retorna cuantos a cambiado
    int count;
    if (x < 0 || x >= M || y < 0 || y >= N //se escapa de la matriz
        || matriz[y][x]) {
        // caso que sea un numero o *
        return 0;
    }
    matriz[y][x] = c;
    if (x == M - 1) return 1; // llega a la derecha
    count = changeGallery(c, x, y + 1, matriz); // se mueve abajo
    if (count) return count + 1;
    count = changeGallery(c, x + 1, y, matriz); // si no cambia nada se va a la derecha
    if (count) return count + 1;
    count = changeGallery(c, x, y - 1, matriz); // si no cambia nada se va a arriba
    if (count) return count + 1;
    return 1; // por que ya cambio un caracter
}

void printMatrix(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(2) << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void p2() {
    char matrix[N][M]{};
    matrix[4][5] = '*';
    matrix[3][5] = '*';
    printMatrix(matrix);
    //changeGallery('X', 0, N-1, matrix);
    for (int i = 0; i < 3; i++) {
        changeGallery('1' + i, 0, N - 1 - i, matrix);
    }
    printMatrix(matrix);
}
