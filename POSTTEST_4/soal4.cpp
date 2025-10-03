#include <iostream>
using namespace std;

struct Node {                      // struktur node buat linked list
    int data;                      // angka yang disimpan
    Node* next;                    // pointer ke node setelahnya
    Node* prev;                    // pointer ke node swbelumnya
};

void sortedInsert(Node*& head, int data) {  // fungsi buat nyisipin angka secaraa urut
    Node* newNode = new Node{data,nullptr,nullptr}; // buat node baru

    // kalo list masi kosong
    if(head == nullptr) {
        newNode->next = newNode->prev = newNode; // next dan prev node baru nunjuk dirinya sendiri
        head = newNode;                          // node baru jadi head
        return;
    }

    // sisip di awal
    if(data < head->data) {                         // klo data lebih kecil dari head
        Node* tail = head->prev;                    // ambil node terakhir
        newNode->next = head;                       // node baru nyambung ke head
        newNode->prev = tail;                       // node baru nyambung balik ke tail
        tail->next = newNode;                       // tail nyambung ke node baru
        head->prev = newNode;                       // head nyambung balik ke node baru
        head = newNode;                             // update head jadi node baru
        return;
    }

    // sisip di tengah/akhir
    Node* current = head;                          // dimulai dari head
    while(current->next != head && current->next->data < data) {
        current = current->next;                   // jalan terus sampe ketemu posisi yang tepat
    }

    newNode->next = current->next;                  // sambung node baru ke node setelah current
    newNode->prev = current;                        // sambung node baru balik ke current
    current->next->prev = newNode;                  // node setelah current nyambung balik ke node baru
    current->next = newNode;                        // current nyambung ke node baru
}

void printList(Node* head) {                        // fungsi buat nampilin isi list
    if(head == nullptr) {                           // kalo list kosong
        cout<<"List kosong"<<endl;
        return;
    }
    Node* current = head;                           // mulai dari head
    do {
        cout<<current->data<<" ";                   // cetak data node
        current = current->next;                    // lanjut ke node berikutnya
    } while(current != head);                       // berhenti kalo balik lagi ke head
    cout<<endl;
}

int main() {
    Node* head = nullptr;                            // list awal kosong

    sortedInsert(head,30);                            // masukin 30
    sortedInsert(head,10);                            // masukin 10
    sortedInsert(head,40);                            // masukin 40
    sortedInsert(head,20);                            // masukin 20

    cout<<"Circular Doubly Linked List (sorted): ";
    printList(head);                                   // nampilin hasil list yang udah terurut

    return 0;
}
