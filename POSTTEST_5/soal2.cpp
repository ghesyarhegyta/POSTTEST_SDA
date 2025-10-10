#include <iostream>
using namespace std;

struct Node {               // bikin struktur untuk node tree
    int data;               // nyimpan nilai node
    Node* left;             // anak kiri
    Node* right;            // anak kanan

    Node(int val) {         // constructor biar langsung ngisi data
        data = val;
        left = nullptr;     // anak kiri belum ada
        right = nullptr;    // anak kanan belum ada juga
    }
};

Node* insert(Node* root, int val) {             // fungsi buat masukin data ke bst
    if (root == nullptr) {                      // kalo tree masih kosong
        return new Node(val);                   // bikin node baru
    }
    if (val < root->data) {                     // kalo lebih kecil, taro di kiri
        root->left = insert(root->left, val);
    } else if (val > root->data) {              // kalo lebih besar, taro di kanan
        root->right = insert(root->right, val);
    }
    return root;                                // balikin root
}

int findMinValue(Node* root) {
    // kalo tree kosong, kembalikan -1
    if (root == nullptr) {
        return -1;
    }
    // terus bergerak ke kiri sampe mentok
    while (root->left != nullptr) {     // selama masih punya anak kiri
        root = root->left;              // pindah trs ke kiri
    }
    // node paling kiri = nilai paling kecil
    return root->data;                  // balikin nilainya
}

int main() {
    Node* root = nullptr;       // tree kosong dulu
    root = insert(root, 50);    // jadiin 50 sebagai root
    insert(root, 30);           // masukin 30 ke kiri
    insert(root, 70);           // masukin 70 ke kanan
    insert(root, 20);           // masukin 20 ke kiri lagi
    insert(root, 40);           // masukin 40 ke kanan dari 30

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    // output seharusnya 20
    return 0;
}
