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

Node* insert(Node* root, int val) {     // fungsi buat masukin data ke bst
    if (root == nullptr) {              // kalo tree masih kosong
        return new Node(val);           // bikin node baru
    }
    if (val < root->data) {                     // kalo lebih kecil dari root
        root->left = insert(root->left, val);   // taro di kiri
    } else if (val > root->data) {              // kalo lebih besar
        root->right = insert(root->right, val); // taro di kanan
    }
    return root;       // balikin root
}

void preOrderTraversal(Node* root) {
    // base case : kalo kosong, langsung balik (stop rekursi)
    if (root == nullptr) return;

    // urutan pre-order : root -> kiri -> kanman
    cout << root->data << " ";        // cetak node sekarang dulu
    preOrderTraversal(root->left);    // lanjut ke subtree kiri
    preOrderTraversal(root->right);   // terakhir baru subtree kanan
}

int main() {
    Node* root = nullptr;       // tree masih kosong
    root = insert(root, 50);    // 50 jadi root
    insert(root, 30);           // 30 ke kiri
    insert(root, 70);           // 70 ke kanan
    insert(root, 20);           // 20 ke kiri dari 30
    insert(root, 40);           // 40 ke kanan dari 30
    insert(root, 60);           // 60 ke kiri dari 70
    insert(root, 80);           // 80 ke kanan dari 70

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // panggil fungsi buat cetak
    // output seharusnya : 50 30 20 40 70 60 80 (root duluan)
    cout << endl;
    return 0; // selesaiiiii
}
