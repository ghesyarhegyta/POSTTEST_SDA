#include <iostream>          // buat input output
#include <string>            // biar bisa pake tipe data string
using namespace std;         // biar ga nulis std:: teruss

struct Node {                // ini struktur node buat bikin stack
    char data;               // nyimpen karakter (huruf)
    Node* next;              // pointer yang nunjuk ke node berikutnya
};

void push(Node*& top, char data) {       // fungsi buat masukin data ke stack
    Node* newNode = new Node{data, top}; // bikin node baru, nextnya langsung nyambung ke node yang lagi jadi top
    top = newNode;                       // node baru jadi top
}

char pop(Node*& top) {                   // fungsi buat ngeluarin data dari stack
    if(top == nullptr) return '\0';      // kalo stack kosong, balikin karakter kosong
    Node* temp = top;                    // simpen alamat top buat dihapus nanti
    char val = temp->data;               // ambil data dari node paling atas
    top = top->next;                     // geser top ke node di bawahnya
    delete temp;                         // hapus node lama biar gak boros memori
    return val;                          // balikin data yang diambil
}

string reverseString(string s) {         // fungsi buat ngebalik string
    Node* stackTop = nullptr;            // awalnya stack kosong
    string reversed = "";                // hasil akhir yang udah kebalik

    // push semua karakter
    for(char c : s)                      // looping semua huruf di string s
        push(stackTop, c);                // masukin tiap huruf ke stack

    // pop untuk balik urutan
    while(stackTop != nullptr)           // selama stack masih ada isinya
        reversed += pop(stackTop);        // ambil huruf dari atas stack, mssukin ke string hasil (otomatis kebalik)

    return reversed;                      // balikin string yang udah dibalik
}

int main() {
    string text;                           // buat nyimpen teks input user
    cout<<"Masukkan teks: ";               // tampilkan pesan ke user
    getline(cin,text);                     // baca input satu baris dari user
    cout<<"Teks terbalik: "<<reverseString(text)<<endl; // panggil fungsi buat balik string & tampilin hasil
    return 0;                               // selesaiiiiiiiiiiiiii
}
