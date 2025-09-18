#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
};

Item *head = nullptr;
string nama;
string nim;

void tambahItem(const string &namaItem, const string &tipe, int jumlahAwal) {
    Item *baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    if (!head) {
        head = baru;
    } else {
        Item *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "YEAYY! Item \"" << namaItem << "\" berhasil ditambahkan ke inventory\n";
}

void sisipItem(const string &namaItem, const string &tipe, int jumlahAwal, int posisi) {
    Item *baru = new Item{namaItem, jumlahAwal, tipe, nullptr};
    if (posisi <= 1 || !head) {
        baru->next = head;
        head = baru;
        cout << "YEAYY! Item \"" << namaItem << "\" berhasil disisipkan\n";
        return;
    }
    Item *temp = head;
    int idx = 1;
    while (temp->next && idx < posisi - 1) {
        temp = temp->next;
        idx++;
    }
    baru->next = temp->next;
    temp->next = baru;
    cout << "YEAYY! Item \"" << namaItem << "\" berhasil disisipkan\n";
}

void hapusItemTerakhir() {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Item *temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem(const string &namaCari) {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item *temp = head;
    Item *prev = nullptr;
    while (temp && temp->namaItem != namaCari) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Item \"" << namaCari << "\" tidak ditemukan!\n";
        return;
    }
    temp->jumlah--;
    cout << "Item " << temp->namaItem << " digunakan, sisa : " << temp->jumlah << endl;
    if (temp->jumlah <= 0) {
        cout << "Jumlah 0, item dihapus dari inventory.\n";
        if (!prev) head = temp->next;
        else prev->next = temp->next;
        delete temp;
    }
}

void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n+============= INVENTORY =============+\n";
    Item *temp = head;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << temp->namaItem
             << " (" << temp->tipe << ") - Jumlah: "
             << temp->jumlah << endl;
        temp = temp->next;
    }
    cout << "+=====================================+\n";
}

int main() {
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int jumlahAwal = 23;
    int posisiSisip = 4;

    int pilihan;
    do {
        cout << "\n+=============================================+\n";
        cout << "||         GAME INVENTORY MANAGEMENT         ||\n";
        cout << "||              [" << nama << " - " << nim << "]               ||\n";
        cout << "+=============================================+\n";
        cout << "|| 1. Tambah Item Baru                       ||\n";
        cout << "|| 2. Sisipkan Item                          ||\n";
        cout << "|| 3. Hapus Item Terakhir                    ||\n";
        cout << "|| 4. Gunakan Item                           ||\n";
        cout << "|| 5. Tampilkan Inventory                    ||\n";
        cout << "|| 0. Keluar                                 ||\n";
        cout << "+=============================================+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string n, t;
            cout << "Nama Item: ";
            getline(cin, n);
            cout << "Tipe Item: ";
            getline(cin, t);
            tambahItem(n, t, jumlahAwal);
        } else if (pilihan == 2) {
            string n, t;
            cout << "Nama Item: ";
            getline(cin, n);
            cout << "Tipe Item: ";
            getline(cin, t);
            sisipItem(n, t, jumlahAwal, posisiSisip);
        } else if (pilihan == 3) {
            hapusItemTerakhir();
        } else if (pilihan == 4) {
            string n;
            cout << "Nama item yang ingin digunakan: ";
            getline(cin, n);
            gunakanItem(n);
        } else if (pilihan == 5) {
            tampilkanInventory();
        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan program ini!! <3.\n";
        } else {
            cout << "Nooo pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    while (head) {
        Item *tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}