//
// Created by jolumarti on 2026-09-09.
//

#include "p1.hpp"
#define MAX_CAT 4
#define MAX_P 3

void chromoDec2Bin(int num, int n, int *cromo) {
    for (int i = 0; i < n; i++) {
        cromo[i] = num % 2;
        num /= 2;
    }
}

void findResults(int data[][4], int data_size , int P1, int P2, int P3) {
    int num_posibilities = pow(2, data_size);
    int count{};
    for (int i = 0; i < num_posibilities; i++) {
        int cromo[data_size];
        chromoDec2Bin(i, data_size, cromo);

        int num_priorities[MAX_P]{};
        int slots[24]{};
        bool is_valid = true;
        for (int h = 0; h < 7; h++) slots[h] = 1;
        slots[13] = 1;
        for (int h = 17; h < 23; h++) slots[h] = 1;

        for (int j = 0; j < data_size; j++) {
            if (cromo[j]) {
                int *data_codigo = data[j];
                int priority = data_codigo[1];
                int start = data_codigo[2];
                int duration = data_codigo[3];
                if (priority == 1) duration++;
                for (int h=start; h < start + duration; h++) {
                    if (slots[h] == 0) {
                        slots[h] = 1;
                    } else {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) break;
                num_priorities[priority-1]++;
            }
        }

        if (is_valid && num_priorities[0] >= P1 && num_priorities[1] >= P2 && num_priorities[2] >= P3) {
            int first = true;
            for (int j = 0; j < data_size; j++) {
                int *data_codigo = data[j];
                if (cromo[j]) {
                    if (!first) cout << " | ";
                    cout << data_codigo[0] << " P" << data_codigo[1];
                    first = false;
                }
            }
            cout << endl;
            count++;
        }
    }
    if (!count) cout << "No se encontraron resultados" << endl;
}

void p1() {
    int data[][MAX_CAT] = {
        {1801, 2, 8, 1},
        {1802, 1, 8, 1},
        {1803, 1, 9, 1},
        {1804, 3, 9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };
    int data_size = sizeof(data) / sizeof(data[0]);

    while (true) {
        int P1, P2, P3;
        char c;
        cout << "Ingresa prioridad P1: ";
        cin >> P1;
        cout << "Ingresa prioridad P2: ";
        cin >> P2;
        cout << "Ingresa prioridad P3: ";
        cin >> P3;
        if (P1 < 0 || P2 < 0 || P3 < 0) {
            cout << "Las prioridades deben ser números no negativos." << endl;
            continue;
        }
          //  P1 = P2 = P3 = 2;
        findResults(data, data_size, P1, P2, P3);
        cout << endl << "Desea ingresar otra combinacion de prioridades? (s/n): ";
        cin >> c;
        if (c != 's' && c != 'S') break;
    }
}
