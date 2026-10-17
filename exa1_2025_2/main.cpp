#include "p1.hpp"
#include "p2.hpp"
#include "p3.hpp"
#include "p4.hpp"
#include "p5.hpp"

void print_p(const int i) {
    cout << "========= PREGUNTA: " << i  << " =========" << endl;
}
int main() {
    print_p(1);
    p1();
    print_p(2);
    p2();
    print_p(3);
    p3();
    print_p(4);
    p4();
    print_p(5);
    p5();

    return 0;
}
