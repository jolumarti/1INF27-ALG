#include "p1.hpp"
#include "p2.hpp"
void print_p(const int i) {
    if (i>1) cout << endl;
    cout << "========= PREGUNTA: " << i  << " =========" << endl;
}
int main() {
    print_p(1);
    //p1();
    print_p(2);
    p2();

    return 0;
}
