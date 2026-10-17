//
// Created by jolumarti on 2026-10-16.
//

#include "p1b.hpp"
#define N 9
#define NOT_FOUND -1

int count_path(char board[N][N], int m_x, int m_y, int x, int y, char c) {
    int new_x = x + m_x;
    int new_y = y + m_y;
    int cont = 0;
    if (board[x][y] == c) cont++;
    if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) return cont;
    cont += count_path(board, m_x, m_y, new_x, new_y, c);
    return cont;
};

void process_path(char board[N][N], int m_x, int m_y, int x, int y, char c) {
    int new_x = x + m_x;
    int new_y = y + m_y;
    if (board[x][y] == c) board[x][y] = '.';
    if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) return;
    process_path(board, m_x, m_y, new_x, new_y, c);
};

void print_matrix(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void find_robot(char board[9][9], int &x, int &y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'D') {
                x = i;
                y = j;
                break;
            }
        }
        if (x != NOT_FOUND) break;
    }
}

void get_max(char board[9][9], char choice, int paths[][2], int x, int y, int &max_id) {
    int max=0;
    for (int i = 0; i < 8; i++) {
        int cont = count_path(board, paths[i][0], paths[i][1], x, y, choice);
        if (cont > max) {
            max = cont;
            max_id = i;
        }
    }
}

void p1b() {
    char board[N][N] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'A', '.', '.', '.', 'B', '.', '.', '.'},
        {'.', '.', 'V', 'A', '.', '.', '.', '.', '.'},
        {'.', 'B', '.', 'D', '.', 'V', 'B', 'A', '.'},
        {'.', '.', 'B', 'B', '.', '.', '.', '.', '.'},
        {'.', 'A', '.', 'B', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', 'B', 'A', '.', '.'},
        {'.', '.', '.', 'V', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.', 'A'}
    };

    cout << "Almacen Inicial:" << endl;
    print_matrix(board);
    char choice;
    int paths[][2]{
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1},
    };
    cout << "Ingrese el color de palet (R/A/B/V):" << endl;
    cin >> choice;
    //choice = 'B';
    int x = NOT_FOUND, y = NOT_FOUND, max_id = NOT_FOUND;
    find_robot(board, x, y);
    if (x == NOT_FOUND) {
        cout << "Robot no encontrado" << endl;
        return;
    }
    get_max(board, choice, paths, x, y, max_id);
    if (max_id != NOT_FOUND) process_path(board, paths[max_id][0], paths[max_id][1], x, y, choice);

    cout << "Almacen Final:" << endl;
    print_matrix(board);
}
