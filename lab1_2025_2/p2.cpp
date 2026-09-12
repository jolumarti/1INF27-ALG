//
// Created by jolumarti on 9/9/26.
//

#include "p2.hpp"
#define N 6
#define M 11



void printMatrix(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(2) << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

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


void solution1(char matrix[6][11]) {
    for (int i = 0; i < 3; i++) {
        changeGallery('1' + i, 0, N - 1 - i, matrix);
    }
}
void drillGalleries(int c, int x, int y, char matriz[N][M], bool isLast = false) {
    if (matriz[y][x]) return;
    matriz[y][x] = c+'0';
    isLast = y == 0 || isLast; // validar si es la ultima fila o ya se habia llegado a la columna mas alta
    if (x+1 == M) {
        if (!isLast) drillGalleries(c+1, 0, y-1, matriz, isLast); // si no es la ultima columna, se sube una fila y se reinicia la columna
        return;
    }
    if (y+1 < N && !matriz[y+1][x]) drillGalleries(c, x, y+1, matriz, isLast);// ir abajo
    else if (x+1 < M && !matriz[y][x+1]) drillGalleries(c, x+1, y, matriz, isLast);// ir derecha
    else if (y-1 < N && !matriz[y-1][x]) drillGalleries(c, x, y-1, matriz, isLast);// ir arriba
}

void p2() {
    char matrix[N][M]{};
    matrix[N-2][5] = '*';
    matrix[N-3][5] = '*';
    printMatrix(matrix);
    drillGalleries(1, 0, N - 1, matrix);
    //solution1(matrix);

    printMatrix(matrix);
}
