//
// Created by jolumarti on 9/7/26.
//

#include "p2.hpp"
#define NUM_TEETH 8
#define NUM_TYPE_TEETH 4
#define NUM_DATE 4
// Se usa numero de citas a 4 (0 caso que no vaya a ninguna cita)
void loadCromo(int numOptions,int base, int n,int *cromo) {
    for (int j=0;j<n;j++) {
        cromo[j]=numOptions%base;
        numOptions/=base;
    }

}

void bruteForce(int teeth[NUM_TEETH][4], int teethType[NUM_TYPE_TEETH][3], int dateInfo[NUM_DATE][2]) {
    int numOptions = (int) pow(NUM_DATE,NUM_TEETH);
    int cromo[NUM_TEETH] {};
    int maxTotal = INT_MIN;
    for (int i = 0; i < numOptions; i++) {
        int subDuration[NUM_DATE]{};
        int subTotal[NUM_DATE]{};
        loadCromo(i,NUM_DATE,NUM_TEETH,cromo); // generar la combinacion de citas para cada diente
        for (int j = 0; j < NUM_DATE; j++) {
            for (int k = 0; k < NUM_TEETH; k++) {
                int *tooth = teeth[k];
                int toothDuration=teethType[tooth[2]-1][1]*tooth[3]; // calcula duracion total para cada diente
                int toothTotal=teethType[tooth[2]-1][2]*tooth[3]; // calcula costo total para cada diente
                if (cromo[k]==j) {// calcula total para cada cita
                    subDuration[j]+=toothDuration;
                    subTotal[j]+=toothTotal;
                }
            }
        }
        bool isValid=true;
        int total{0};
        for (int j = 1; j < NUM_DATE; j++) {// valida que la duracion de cada cita no exceda el tiempo disponible
            if (subDuration[j]>dateInfo[j-1][1]) {
                isValid=false;
                break;
            }
            total+=subTotal[j];// calcula el total de la combinacion
        }
        if (isValid && total>maxTotal) {
            maxTotal=total;
        }
    }
    cout << "El total maximo es " << maxTotal << endl;
}


void p2() {
    int teeth[NUM_TEETH][4] { //{ubicacion, cuadrante, tipo, cantCaries}
        {1,1,1,3},
        {2,1,1,1},
        {3,1,2,0},
        {4,1,3,1},
        {5,1,3,2},
        {6,1,4,1},
        {7,1,4,2},
        {8,1,4,3},
    };
    int teethType[NUM_TYPE_TEETH][3] { // {tipo, duracion, ganancia}
        {1,5,20},
        {2,7,30},
        {3,10,35},
        {4,12,42}
    };
    int dateInfo[NUM_DATE][2] { // {cita, duracion}
        {1, 60},
        {2, 45},
        {3, 50},
    };
    bruteForce(teeth, teethType, dateInfo);
}
