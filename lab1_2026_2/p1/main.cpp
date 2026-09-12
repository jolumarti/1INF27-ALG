#include <iostream>
#include <cmath>
#include <climits>
#define E 8
#define E_CAT 2
#define C 4
#define C_CAT 2
#define T 3
#define P 3
using namespace std;
void chromoDec2Base(int *chromo, int  num, int cant, int base) {
    for (int i = 0; i < cant; i++) {
        chromo[i] = num % base;
        num /= base;
    }
}

void findMaxScore(int dataStudents[E][E_CAT], int dataCasa[C][C_CAT], int prueba[P]) {
    int posibilities = (int) pow(P+1, E);
    int max_chromo[E]{};
    int max_score{INT_MIN};

    for (int i = 0; i < posibilities; i++) {
        int chromo[E]{};
        int duraciones[P+1]{};
        int puntaje{};
        chromoDec2Base(chromo, i, E, P+1);
        // calcular duraciones y puntajes totales
        for (int j = 0; j < E; j++) {
            int id_prueba = chromo[j];
            if (id_prueba) { //
                int id_casa = dataStudents[j][0];
                int cant_cualidades = dataStudents[j][1];
                int dura_cualidad =  dataCasa[id_casa-1][0];
                int punt_cualidad =  dataCasa[id_casa-1][1];
                duraciones[id_prueba] += dura_cualidad*cant_cualidades;
                puntaje += punt_cualidad*cant_cualidades;
            }
        }
        // validar que sean menor que las duraciones
        int is_valid = true;
        for (int j = 0; j < P; j++) {
            int duracion = duraciones[j+1];
            if (duracion > prueba[j]) {
                is_valid = false;
                break;
            }
        }
        // encontrar maximo puntaje y guardar el chromo
        if (is_valid && max_score < puntaje) {
            max_score = puntaje;
            for (int j = 0; j < E; j++) {
                max_chromo[j] = chromo[j];
            }
        }
    }
    // impresion de resultados
    for (int j = 0; j < P; j++) {
        cout << "Turno " << j+1 << " = " <<prueba[j] << " minutos\n";
    }
    cout  << "Resultado obtenido: Puntaje maximo = " << max_score << endl;
    cout << "Una distribucion optima posible:" << endl;
    for (int j = 0; j < P; j++) {
        bool first = true;
        cout << "Turno " << j+1 << ": Estudiantes ";
        for (int k = 0; k < E; k++) {
            int turno = max_chromo[k]-1;
            if (turno == j) {
                if (!first) cout << ", ";
                cout << k+1;
                first = false;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int dataStudents[E][E_CAT]{
        {1,3},
        {1,1},
        {2,0},
        {3,1},
        {3,2},
        {4,1},
        {4,2},
        {4,3},
    };
    int dataCasa[C][C_CAT]{
        {5,20},
        {7,30},
        {10,35},
        {12,42},
    };
    int prueba[P]{35,30,25};
    findMaxScore(dataStudents, dataCasa, prueba);
    int prueba2[P]{20,20,20};
    findMaxScore(dataStudents, dataCasa, prueba2);
    return 0;
}
