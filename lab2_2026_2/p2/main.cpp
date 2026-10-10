#include <iostream>
#include <climits>
#define N 5
using namespace std;

bool find_bird(int data[N][N], int posX, int posY, int id, bool &canBeFound) {
    if (!canBeFound) return false;
    //cout << posX << " " << posY << " " << data[posX][posY] << endl;
    if (posX < 0 || posX >= N || posY < 0 || posY >= N) {
        canBeFound = false;
        return false;
    }
    if (data[posX][posY] == id) return true;
    if (data[posX][posY] < id) {
        if (find_bird(data, posX + 1, posY + 1, id,canBeFound)) return true;
        if (find_bird(data, posX + 1, posY, id,canBeFound)) return true;
        if (find_bird(data, posX, posY + 1, id,canBeFound)) return true;
    }
    return false;
}

void print_find_bird(int data[N][N], int id) {
    bool canBeFound = true;
    cout << "La anilla " << id;
    if (find_bird(data, 0, 0, id, canBeFound)) cout << " si se encuentre en el aviario. " << endl;
    else cout << " no se encuentre en el aviario. " << endl;
}

int main() {
    int data[N][N]{
        {1, 8, 17, 21, 36},
        {6, 14, 28, 33, 38},
        {9, 16, 29, 35, 41},
        {10, 20, 30, 37, 45},
        {13, 31, 32, 43, 50},
    };
    print_find_bird(data, 55);
    //print_find_bird(data, 18);
    //print_find_bird(data, 43);
    return 0;
}
