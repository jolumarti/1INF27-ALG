#include "Utils.hpp"
#define T 6
#define D 3
void chromoDec2Base(int num, int base,  int cant, int *chromo) {
    for (int i = 0; i < cant; i++) {
        chromo[i] = num % base;
        num /= base;
    }
}
int main() {
    int tablas[T] {
        150,100,80,50,120,10
    };
    int discos[D] {
        250,200,200
    };
    int num_posibilites = pow(D,T);
    int leftover_max = INT_MIN;
    int chromo_max[T]{};
    for (int i = 0; i < num_posibilites; i++) {
        int chromo[T];
        int discoCap[D]{0};
        chromoDec2Base(i, D, T, chromo);
        for (int j = 0; j < T; j++) {
            discoCap[chromo[j]] += tablas[j];
        }
        bool valid = true;
        for (int j = 0; j < D; j++) {
            if (discoCap[j] > discos[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            int leftover_min = INT_MAX;
            for (int j = 0; j < D; j++) {
                int leftover = discos[j] - discoCap[j];
                if (leftover < leftover_min) {
                    leftover_min = leftover;
                }
            }
            if (leftover_min > leftover_max) {
                leftover_max = leftover_min;
                for (int j = 0; j < T; j++) {
                    chromo_max[j] = chromo[j];
                }
            }
        }
    }

    for (int i = 0; i < D; i++) {
        cout << "Disco " << i + 1 << ": " << discos[i] << " MB" << endl;
        for (int j = 0; j < T; j++) {
            if (chromo_max[j] == i) {
                cout << "  Tabla " << j + 1 << ": " << tablas[j] << " MB" << endl;
            }
        }
    }
    for (int j = 0; j < T; j++) {
            cout << "comb " << chromo_max[j]<< ": " << tablas[j] << " MB" << endl;
    }    cout << endl;

    return 0;
}
