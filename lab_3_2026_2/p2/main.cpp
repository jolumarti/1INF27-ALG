
#include <iostream>
#include <cmath>

using namespace std;

struct Element
{
    int value;
    int value_abs;
    bool charge;
};
struct Node{
    Element data;
    Node* next;
};
struct Pila{
    Node* head;
};
void construct_pila(Pila &pila){
    pila.head = nullptr;
}
bool is_empty_pila(Pila &pila)
{
    return pila.head == nullptr;
}
Element pop(Pila &pila){
    if (pila.head == nullptr){
        cout << "Pila is empty" << endl;
        exit(1);
    }
    Node *temp = pila.head;
    pila.head = pila.head->next;
    Element data = temp->data;
    delete temp;
    return data;
}

void push(Pila &pila, int data){
    Node *new_node = new Node;
    new_node->data.value = data;
    new_node->data.value_abs = abs(data);
    new_node->data.charge = data>0;
    new_node->next = pila.head;
    pila.head = new_node;
}

void print_pila(Pila &pila)
{
    Node *temp = pila.head;
    while (temp != nullptr)
    {
        cout << temp->data.value;
        temp = temp->next;
        if (temp) cout << " ";
    }
    cout << endl;
}
void insertar_pila(Pila &pila, Pila &aux, int data){
    if (is_empty_pila(pila)){
        if (data < 0) push(aux, data);
        else push(pila, data);
        return;
    }
    Element ele_head = pop(pila);
    Element ele_data;
    ele_data.value = data;
    ele_data.charge = data>0;
    ele_data.value_abs = abs(data);
    if (ele_head.charge == ele_data.charge){
        int dif = ele_head.value_abs - ele_data.value_abs;
        if (dif == 0)
        {

        } else if (dif < 0)
        {
            push(pila, ele_head.value);
        } else if (dif > 0)
        {
            push(pila, ele_data.value);
        }
    } else {
        int dif = ele_head.value_abs - ele_data.value_abs;
        if (dif == 0)
        {

        } else if (dif < 0)
        {
            push(pila, ele_head.value);
        } else if (dif > 0)
        {
            push(pila, ele_data.value);
        }
    }
}

int main() {
    Pila pila,aux;
    construct_pila(pila);
    construct_pila(aux);
    insertar_pila(pila, aux,12);
    insertar_pila(pila, aux,7);
    insertar_pila(pila, aux,-5);
    insertar_pila(pila, aux,-15);
    insertar_pila(pila, aux,4);
    insertar_pila(pila, aux,-3);
    insertar_pila(pila, aux,9);
    insertar_pila(pila, aux,-20);
    insertar_pila(pila, aux,6);
    insertar_pila(pila, aux,2);
    insertar_pila(pila, aux,-1);
    // push(pila, aux,-5);
    // push(pila,9);
    // push(pila,27);
    // push(pila,-27);
    // push(pila,-20);
    //print_pila(pila);
    
    print_pila(aux);
    return 0;
}