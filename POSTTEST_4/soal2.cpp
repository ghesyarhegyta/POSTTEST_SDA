#include <iostream>
#include <string>
using namespace std;

struct Node {                // bikin node buat stack
    char data;               // nyimpen karakter
    Node* next;              // nunjuk ke node berikutnya
};

void push(Node*& top, char data) {        // masukin data ke stack
    Node* newNode = new Node{data, top};  // bikin node baru, nextnya nyambung ke top lama
    top = newNode;                        // node baru jadi top
}

char pop(Node*& top) {                    // ngeluarin data dari stack
    if(top == nullptr) return '\0';       // kalo kosong, balikin karakter kosong
    Node* temp = top;                     // simpan top lama
    char val = temp->data;                // ambil datanya
    top = top->next;                      // geser top ke bawah
    delete temp;                          // hapus node lama
    return val;                           // balikin data yang diambil
}

bool areBracketsBalanced(string expr) {    // fungsi buat ngecek kurung seimbang
    Node* stackTop = nullptr;              // stack awalnya kosong

    for(char c : expr) {                   // baca semua karakter di input
        if(c=='(' || c=='{' || c=='[')     // kalo ketemu kurung buka
            push(stackTop, c);             // masukin ke stack
        else if(c==')' || c=='}' || c==']') { // kalo ketemu kurung tutup
            if(stackTop == nullptr)        // kalo stack kosong berarti ga ada pasangan
                return false;              // langsung ga seimbang
            char topC = pop(stackTop);     // ambil kurung buka terakhir dari stack
            if((c==')' && topC!='(') ||    // cek pasangan kurung buka sama tutup harus cocok
               (c=='}' && topC!='{') ||
               (c==']' && topC!='['))
                return false;              // kalo ga cocok, ga seimbang
        }
    }
    return stackTop == nullptr;            // kalo stack kosong di akhir, berarti semua pasangannya cocok
}

int main() {
    string expr;                                    // buat nyimpen input
    cout<<"Masukkan ekspresi bracket: ";            // minta input dari user
    getline(cin, expr);                             // baca input
    cout<<expr<<" -> "<<(areBracketsBalanced(expr) ? "Seimbang" : "Tidak Seimbang")<<endl; // cek & tampilin hasil
    return 0;
}
