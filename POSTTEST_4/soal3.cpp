#include <iostream>
#include <string>
using namespace std;

struct Node {                     // struktur buat tiap dokumen di antrian
    string document;              // nama dokumennya
    Node* next;                   // pointer ke node berikutnya
};

void enqueue(Node*& front, Node*& rear, string document) { // fungsi buat masukin dokumen ke antrian
    Node* newNode = new Node{document, nullptr};           // bikin node baru buat dokumen
    if(front == nullptr) {                                 // kalau antrian kosong
        front = rear = newNode;                            // node baru jadi front dan rear
    } else {                                               // kalau antrian udah ada
        rear->next = newNode;                              // sambungkan node baru di belakang
        rear = newNode;                                    // update rear jadi node baru
    }
}

string dequeue(Node*& front, Node*& rear) {                // fungsi buat ngeluarin dokumen dari antrian
    if(front == nullptr) return "";                        // kalau antrian kosong, balikin string kosong
    Node* temp = front;                                    // simpen node paling depan
    string doc = temp->document;                           // ambil nama dokumennya
    front = front->next;                                   // geser front ke dokumen berikutnya
    if(front == nullptr) rear = nullptr;                   // kalau kosong setelah diambil, rear juga jadi kosong
    delete temp;                                           // hapus node yang udah diproses
    return doc;                                            // balikin nama dokumen yang diambil
}

void processAllDocuments(Node*& front, Node*& rear) {      // proses semua dokumen di antrian
    while(front != nullptr) {                              // selama masih ada dokumen
        cout<<"Memproses: "<<dequeue(front,rear)<<endl;    // ambil dokumen paling depan dan tampilkan prosesnya
    }
}

int main() {
    Node* front = nullptr;                                 // awalnya antrian kosong
    Node* rear = nullptr;

    enqueue(front,rear,"Document1.pdf");                   // masukin dokumen 1 ke antrian
    enqueue(front,rear,"Report.docx");                     // masukin dokumen 2 ke antrian
    enqueue(front,rear,"Presentation.pptx");               // masukin dokumen 3 ke antrian

    cout<<"Memulai pemrosesan antrian printer:\n";
    processAllDocuments(front,rear);                       // proses semua dokumen sampai habis

    return 0;
}
