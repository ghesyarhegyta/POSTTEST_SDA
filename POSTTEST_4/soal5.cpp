#include <iostream>
using namespace std;

// struktur data node
struct Node {
    int data;        // nilai yang disimpan di node
    Node* next;      // pointer ke node berikutnya
    Node* prev;      // pointer ke node sebelumnya
};

// untuk menambahkan node di bagian akhir list
void insertEnd(Node*& head, int data) {
    // buatt node baru
    Node* newNode = new Node{data, nullptr, nullptr};

    // kalo list kosong (belum ada node sama sekali)
    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;  // next dan prev mengarah ke diri sendiri
        head = newNode;                           // node ini jadi head
        return;
    }

    // kalo listnya udah ada isinya
    Node* tail = head->prev;      // tail = node sebelum head
    newNode->next = head;         // node baru diarahin ke head
    newNode->prev = tail;         // dan sebelumnya ke tail
    tail->next = newNode;         // tail lama sekarang nyambung ke node baru
    head->prev = newNode;         // head sebelumnya disambung balik ke node baru
}

// fungsi untuk menampilkan isi list
void printList(Node* head) {
    if (head == nullptr) {                 // kalo list kosong
        cout << "List kosong\n";
        return;
    }
    Node* cur = head;                     // mulai dari head
    do {
        cout << cur->data << " ";         // tampilkan data
        cur = cur->next;                  // lanjut ke node berikutnya
    } while (cur != head);                // berhenti kalo dah balik ke head
    cout << endl;
}

// fungsi utama untuk tukar posisi head dan tail
void exchangeHeadAndTail(Node*& head) {
    // kalo list kosong atau cuma ada 1 node, ga perlu ditukar
    if (head == nullptr || head->next == head) return;

    Node* H = head;        // simpan pointer ke head
    Node* T = head->prev;  // tail = node sebelum head

    // jika cuma ada 2 node, cukup ganti head jadi tail
    if (H->next == T) {
        head = T;
        return;
    }

    // untuk list dengan 3 node atau lebih
    Node* Hnext = H->next;   // node setelah head
    Node* Tprev = T->prev;   // node sebelum tail

    // 1) sambungkan tail ke node setelah head
    T->next = Hnext;         // tail sekarang mengarah ke headNext
    Hnext->prev = T;         // headNext sekarang punya prev ke tail

    // 2) sambungkan head ke node sebelum tail
    Tprev->next = H;         // node sebelum tail mengarah ke headv
    H->prev = Tprev;         // head sekarang punya prev ke node sebelum tail

    // 3) hubungkan head dan tail supaya posisinya benar
    H->next = T;             // head sekarang ngikutin tail
    T->prev = H;             // tail punya prev ke head

    // 4) ganti head jadi tail, karena tail sekarang ada didepan
    head = T;
}

// fungsi main untuk uji program
int main() {
    Node* head = nullptr;          // mulai dengan list kosong

    // buat list awal: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);               // tampilkan sebelum ditukar

    exchangeHeadAndTail(head);     // panggil fungsi tukar

    cout << "List setelah exchange head & tail: ";
    printList(head);               // tampilkan setelah ditukar

    return 0;
}
