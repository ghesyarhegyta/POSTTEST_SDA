#include <iostream>         // buat pake fungsi input output (cout, endl, dll)
using namespace std;        // biar ga nulis std:: teruss

struct Node {               // bikin struktur untuk node tree
    int data;               // buat nyimpan nilai dsri node
    Node* left;             // pointer ke anak kiri
    Node* right;            // pointer ke anak kanan

    Node(int val) {         // constructor biar gampang pas bikin node baru
        data = val;         // isi data nodenya
        left = nullptr;     // awalnya anak kiri kosong
        right = nullptr;    // awalnya anak kanan kosong
    }
};

Node* insert(Node* root, int val) { // fungsi buat masukin data ke bst
    if (root == nullptr) {          // kalo belum ada node (kosong)
        return new Node(val);       // bikin node baru & balikin sebagai root
    }
    if (val < root->data) {                      // kalo nilai lebih kecil dari root
        root->left = insert(root->left, val);    // masuk ke kiri
    } else if (val > root->data) {               // kalo nilai lebih besar dari root
        root->right = insert(root->right, val);  // masuk ke kanan
    }
    return root;                                 // balikin root (biar struktur treenya tetap kehubung)
}

int countNodes(Node* root) {
    // kaloo tree kosong, berarti jumlahnya 0
    if (root == nullptr) {
        return 0;
    }
    // kalo ga kosong, hitung node ini (1) + jumlah node kiri + jumlah node kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;          // awalnya tree masi kosong
    root = insert(root, 50);       // masukin data pertama jadi root
    insert(root, 30);              // masukin data ke kiri
    insert(root, 70);              // masukin data ke kanan
    insert(root, 20);              // masukin lagi ke subtree kiri dari 30

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl;
    // outputt harusnya 4
    return 0; // done bang
}
