#include <iostream>
#define P_CAT 2

using namespace std;

int findMaxGanancia(int dataProyectos[][P_CAT], int N, int P, int x) {
    if (x >= N || P <= 0) return 0;
    int costo = dataProyectos[x][0];
    int ganancia = dataProyectos[x][1];
    // se cacula la siguiente ganancia sin usar este proyecto
    int sigGananciaProy = findMaxGanancia(dataProyectos, N, P, x + 1);
    int gananciaProy = 0;
    // se evalua si el proyecto esta dentro del costo para sumar o continuar
    if (costo <= P) gananciaProy = findMaxGanancia(dataProyectos, N, P - costo, x + 1) + ganancia;
    //return max(gananciaProy, sigGananciaProy);
    if (sigGananciaProy < gananciaProy) {
        return gananciaProy;
    }
    return sigGananciaProy;
}

void printMax(int dataProyectos[][2], int N, int P) {
    cout << "N = " << N  << " - P = " << P << endl;
    cout << "Beneficio Total: "<< findMaxGanancia(dataProyectos, N, P,0) << endl;
}

int main() {
    int dataProyectos[][P_CAT]{
        {100, 200},
        {50, 300},
        {150, 300},
        {50, 400},
        {50, 200},
        {150, 800},
        {100, 250}
    };
    int N{7};
    int P{400};
    printMax(dataProyectos, N, P);
    int dataProyectos2[][P_CAT]{
        {500, 200},
        {50, 300},
        {150, 300},
        {50, 400},
        {50, 200},
    };
    N = 5;
    P = 200;
    printMax(dataProyectos2, N, P);
    return 0;
}
