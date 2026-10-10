
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct List{
    Node* head;
};
void construct_list(List &list){
    list.head = nullptr;
}
bool is_empty_list(List &list)
{
    return list.head == nullptr;
}
int pop(List &list){
    if (list.head == nullptr){
        cout << "List is empty" << endl;
        return -1;
    }
    Node *temp = list.head;
    list.head = list.head->next;
    int data = temp->data;
    delete temp;
    return data;
}
int peek(List &list){
    if (list.head == nullptr){
        cout << "List is empty" << endl;
        return -1;
    }
    return list.head->data;
}
void push(List &list, int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = list.head;
    list.head = new_node;
}
void append(List &list, int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (list.head == nullptr){
        list.head = new_node;
        return;
    }
    Node *temp = list.head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
// void push_array(List &list, int *array, int num){
//     for (int i = num-1; i >=0; i--){
//         push(list, array[i]);
//     }
// }
void print_list(List &list)
{
    Node *temp = list.head;
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
        if (temp) cout << " -> ";
    }
    cout << endl;
}
int aislarEquipos(List &list, Node *aux){
    if (is_empty_list(list)) return 0;
    int cont = 0;
    int data = pop(list);
    if (data < 0){
        cont++;
        cont += aislarEquipos(list, aux);
        push(list,data);
    } else{
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        if (aux == nullptr) {
            aux = new_node;
        } else {
            aux->next = new_node;
            new_node->next = aux;
        }
        cont += aislarEquipos(list, aux);
    }
    return cont;
}
int main() {
    List list;
    construct_list(list);
    push(list,106);
    push(list,-105);
    push(list,-104);
    push(list,103);
    push(list,-102);
    push(list,101);
    print_list(list);
    cout << aislarEquipos(list, nullptr) << endl;
    print_list(list);
    return 0;
}