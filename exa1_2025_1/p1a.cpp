//
// Created by jolumarti on 2026-10-15.
//

#include "p1a.hpp"
#define R 12
#define S 8
#define L 3

bool verify_word(char c1, char c2, char c3, int x, int y) {
    char words[][L]{
        {'C', 'E', 'N'},
        {'C', 'N', 'E'},
        {'E', 'C', 'N'},
        {'E', 'N', 'C'},
        {'N', 'C', 'E'},
        {'N', 'E', 'C'},
    };
    char num = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < num; i++) {
        if (words[i][0] == c1 && words[i][1] == c2 && words[i][2] == c3) {
            cout << "(" << x << ", " << y << ")" << endl;
            return true;
        }
    }
    return false;
}

void process_matrix(int matriz[R][S]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if ((j + 2) < S) {
                //right
                if (verify_word(matriz[i][j], matriz[i][j + 1], matriz[i][j + 2], i, j)) continue;
            }
            if ((j + 2) < S && (i + 2) < R) {
                //right+down
                if (verify_word(matriz[i][j], matriz[i + 1][j + 1], matriz[i + 2][j + 2], i, j)) continue;
            }
            if ((i + 2) < R) {
                //down
                if (verify_word(matriz[i][j], matriz[i + 1][j], matriz[i + 2][j], i, j)) continue;
            }
            if ((i + 2) < R && (j - 2) >= 0) {
                //down-left
                if (verify_word(matriz[i][j], matriz[i + 1][j - 1], matriz[i + 2][j - 2], i, j)) continue;
            }
            if ((j - 2) >= 0) {
                //left
                if (verify_word(matriz[i][j], matriz[i][j - 1], matriz[i][j - 2], i, j)) continue;
            }
            if ((i - 2) >= 0 && (j - 2) >= 0) {
                //left-up
                if (verify_word(matriz[i][j], matriz[i - 1][j - 1], matriz[i - 2][j - 2], i, j)) continue;
            }
            if ((i - 2) >= 0) {
                //up
                if (verify_word(matriz[i][j], matriz[i - 1][j], matriz[i - 2][j], i, j)) continue;
            }
            if ((j + 2) < S && (i - 2) >= 0) {
                //up-right
                if (verify_word(matriz[i][j], matriz[i - 1][j + 1], matriz[i - 2][j + 2], i, j)) continue;
            }
        }
    }
}

void p1a() {
    int matriz[R][S]{
        {'C', 'E', 'N', 'Z', 'Y', 'X', 'A', 'U'},
        {'D', 'Y', 'X', 'A', 'B', 'A', 'Y', 'U'},
        {'A', 'Z', 'Y', 'A', 'X', 'B', 'C', 'U'},
        {'B', 'Z', 'Z', 'A', 'E', 'E', 'Y', 'A'},
        {'Y', 'Y', 'B', 'X', 'N', 'C', 'Z', 'Y'},
        {'U', 'U', 'Y', 'Y', 'B', 'N', 'C', 'Z'},
        {'Z', 'Y', 'A', 'A', 'U', 'Y', 'Y', 'E'},
        {'Y', 'U', 'E', 'D', 'Z', 'B', 'B', 'N'},
        {'Z', 'C', 'B', 'X', 'U', 'B', 'A', 'Z'},
        {'N', 'Z', 'B', 'C', 'Y', 'Y', 'A', 'Y'},
        {'X', 'A', 'E', 'Z', 'Z', 'A', 'U', 'Z'},
        {'A', 'C', 'Z', 'X', 'X', 'Y', 'Y', 'Z'}
    };
    process_matrix(matriz);
}
