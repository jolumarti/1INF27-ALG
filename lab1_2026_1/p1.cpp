//
// Created by jolumarti on 2026-09-07.
//

#include "p1.hpp"
#define N 10
#define M 10

void printMap(char mapa[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << mapa[i][j] << " ";
        cout << endl;
    }
}
int findArtefacts(int minX, int maxX, int y, int alcance, int direccion, char mapa[N][M]) {
    if (y<0 || y>=N || alcance<0) return 0;
    minX = max(0, minX); // Determinar los límites de búsqueda
    maxX = min(M-1, maxX);
    int count{0};
    for (int i = minX; i <= maxX; i++) { // Buscar artefactos en la fila actual
        if (mapa[y][i]=='A') {
            count++;
            mapa[y][i]='*';
        }
    }
    if (direccion==0) { // Caso inicial se va hacia arriba y abajo
        count +=findArtefacts(minX-1, maxX+1, y-1, alcance-1, -1, mapa);
        count +=findArtefacts(minX-1, maxX+1, y+1, alcance-1, 1, mapa);
        return count;
    }
    return count+findArtefacts(minX-1, maxX+1, y+direccion, alcance-1, direccion, mapa);
}
void p1() {
    char mapa[N][M]{};
    int x{5}, y{5}, alcance{3}, direccion{0};
    mapa[3][3]='A';
    mapa[3][4]='A';
    mapa[4][5]='A';
    mapa[5][4]='A';
    mapa[5][7]='A';
    mapa[7][5]='A';
    printMap(mapa);
    int count = findArtefacts(x, x, y, alcance, direccion, mapa);
    cout << "Artefactos encontrados: " << count << endl;
    printMap(mapa);
}