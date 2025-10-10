#include <iostream>
using namespace std;

struct Node {               // bikin struktur untuk node tree
    int data;               // nilai data di node
    Node* left;             // anak kiri
    Node* right;            // anak kanan

    Node(int val) {         // constructor juga kayak dijwbn sebelumnya
        data = val; 
        left = nullptr;     // anak kiri belum ada
        right = nullptr;    // anak kanan belum ada
    }
};

Node* insert(Node* root, int val) { // fungsi buat masukin node ke bst
    if (root == nullptr) {          // kalo tree masih kosong
        return new Node(val);       // bikin node baru
    }
    if (val < root->data) {                     // kalo nilai lebih kecil dari root
        root->left = insert(root->left, val);   // taro di subtree kiri
    } else if (val > root->data) {              // kalo lebih besar
        root->right = insert(root->right, val); // taro di subtree kanan
    }
    return root; // balikin root biar struktur treenya tetap kehubung
}

void postOrderTraversal(Node* root) {
    // base case: kalo tree kosong, langsung balik aja (ga usah lanjut)
    if (root == nullptr) return;

    // urutan post-order : kiri -> kanan -> root
    postOrderTraversal(root->left);  // telusuri subtree kiri dulu
    postOrderTraversal(root->right); // baru subtree kanan
    cout << root->data << " ";       // terakhir baru cetak node sekarang
}

int main() {
    Node* root = nullptr;       // tree awalnya kosong
    root = insert(root, 50);    // masukin 50 jadi root
    insert(root, 30);           // masukin 30 ke kiri
    insert(root, 70);           // masukin 70 ke kanan
    insert(root, 20);           // masukin 20 di bawah 30
    insert(root, 40);           // masukin 40 di kanan dari 30
    insert(root, 60);           // masukin 60 di kiri dari 70
    insert(root, 80);           // masukin 80 di kanan dari 70

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // panggil fungsi buat cetak treenya
    // output seharusnya 20 40 30 60 80 70 50 (urut dr kiri-kanan-root)
    cout << endl;
    return 0;
}
