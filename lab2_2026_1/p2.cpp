#include "p2.hpp"
#define NOT_FOUND -1
#define M 10

int find_ancestor(int data[M][M], int cur, int opo) {
    if (opo == M) {
        bool is_valid = true;
        for (int i = 0; i < M; i++) {
            if (i != cur) {
                //cout << i << " " << data[i][cur]<< " " << data[cur][i] << endl;
                if (data[i][cur]==0 || data[cur][i]>0) {
                    is_valid = false;
                    break;
                }
            }
        }
        if (is_valid) return cur;
        return NOT_FOUND;
    }
    if (data[cur][opo]==0) return find_ancestor(data, cur, opo+1);
    return find_ancestor(data, opo, opo+1);
}
void p2() {
    int data[M][M]{
        {100, 0, 50, 40, 30, 20, 30, 0, 80, 0},
        {50, 100, 0, 40, 30, 20, 20, 0, 10, 25},
        {80, 30, 100, 40, 30, 0, 30, 20, 10, 60},
        {50, 0, 0, 100, 30, 0, 50, 30, 30, 90},
        {50, 10, 10, 10, 100, 0, 10, 50, 10, 50},
        {20, 0, 0, 0, 0, 100, 90, 20, 40, 20},
        {0, 0, 0, 0, 0, 0, 100, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 50, 100, 50, 20},
        {20, 0, 0, 40, 0, 0, 90, 0, 100, 10},
        {0, 10, 0, 0, 0, 0, 10, 0, 60, 100}
    };
    cout << find_ancestor(data, 0, 1);

}
