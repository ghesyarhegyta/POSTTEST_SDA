#include <iostream>
using namespace std;

struct Node {               // bikin struktur untuk node tree
    int data;               // nyimpan nilai node
    Node* left;             // anak kiri
    Node* right;            // anak kanan

    Node(int val) {         // constructor
        data = val;
        left = nullptr;     // anak kiri belum ada
        right = nullptr;    // anak kanan belum ada
    }
};

Node* insert(Node* root, int val) {     // fungsi buat nambah node ke bst
    if (root == nullptr) {              // kalo tree masih kosong
        return new Node(val);           // bikin node baru okk
    }
    if (val < root->data) {             // kalo nilai kecil dari root, taro kiri
        root->left = insert(root->left, val);
    } else if (val > root->data) {      // kalo nilai lebih besar, taro kanan
        root->right = insert(root->right, val);
    }
    return root;                        // balikin root
}

int findMaxValue(Node* root) {
    // kalo tree kosong
    if (root == nullptr) {
        return -1;                   // balikin -1 aja biar ketauan kosong
    }
    // geser ke kanan terus sampai mentok
    while (root->right != nullptr) { // selama masih ada anak kanan
        root = root->right;          // pindah ke kanan
    }
    // node paling kanan = nilai paling besar
    return root->data;               // ambil datanya
}

int main() {
    Node* root = nullptr;           // tree kosong
    root = insert(root, 50);        // masukin 50 sebagai root
    insert(root, 30);               // masukin 30 ke kiri
    insert(root, 70);               // masukin 70 ke kanan
    insert(root, 20);               // masukin 20 ke kiri bawah
    insert(root, 80);               // masukin 80 ke kanan bawah (ni bkl jadi nilai terbesar)

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    // output seharusnya 80
    return 0; // program selesai
}
