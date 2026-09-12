#include "Utils.hpp"
#define N 6
#define M 7

void printMatrix(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(2) << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
void findGold(char matriz[N][M], int x, int y, int comb, int prevX, int prevY) {
    if (x < 0 || x >= M || y < 0 || y >= N || comb<=0) {
        return;
    }
    comb--;
    if (matriz[y][x] == '*') {
        findGold(matriz, prevX, prevY, comb, x, y);
        return;
    }
    if (matriz[y][x] == 'O') {
        cout << "Found gold at (" << x << ", " << y<< ")" << endl;
        matriz[y][x] = 'x';
        printMatrix(matriz);
       //return;
    }
    findGold(matriz, x, y-1, comb, x, y);
    findGold(matriz, x+1, y, comb, x, y);
    findGold(matriz, x, y+1, comb, x, y);
    findGold(matriz, x-1, y, comb, x, y);
}
int main() {
    char matriz[N][M] = {
        {0, 'O', 'O', 'O', 'O', 'O', 'O'},
        {0, 'O', 'O', 0, 0, 0, 0},
        {0, 'O', 0, 0, 0, 0, 0},
        {'O', 0, 0, 0, '*', 0, 0},
        {'O', 'O', 0, 0, 0, 0, 0},
        {'O', 'O', 0, 'O', 'O', 0, 0}
    };
    int y=3, x=2, comb = 3;

    findGold(matriz, x, y, comb, x, y+1);
    return 0;
}
