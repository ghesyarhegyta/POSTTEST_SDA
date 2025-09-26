#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    string namaItem;
    string tipe;
    int jumlah;
    Item *next;
    Item *prev;
};

Item *head = nullptr;
Item *tail = nullptr;

string nama;
string nim;
int idCounter = 1;

void tambahItem(const string &namaItem, const string &tipe, int jumlahAwal) {
    Item *baru = new Item{idCounter++, namaItem, tipe, jumlahAwal, nullptr, nullptr};

    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "YEAYY! Item \"" << namaItem << "\" berhasil ditambahkan ke inventory\n";
}

void sisipItem(const string &namaItem, const string &tipe, int jumlahAwal) {
    Item *baru = new Item{idCounter++, namaItem, tipe, jumlahAwal, nullptr, nullptr};

    if (!head) {
        head = tail = baru;
        cout << "YEAYY! Item \"" << namaItem << "\" berhasil disisipkan sebagai item pertama\n";
        return;
    }

    Item *temp = head;
    int count = 1;
    while (temp->next && count < 3) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    baru->prev = temp;

    if (temp->next)
        temp->next->prev = baru;
    else
        tail = baru;

    temp->next = baru;

    cout << "YEAYY! Item \"" << namaItem << "\" berhasil disisipkan di posisi ke-4\n";
}

void hapusItemTerakhir() {
    if (!tail) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "Item \"" << tail->namaItem << "\" dihapus dari inventory.\n";

    Item *hapus = tail;
    tail = tail->prev;

    if (tail) tail->next = nullptr;
    else head = nullptr;

    delete hapus;
}

void gunakanItem(const string &namaCari) {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }

    Item *temp = head;
    while (temp && temp->namaItem != namaCari) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Item \"" << namaCari << "\" tidak ditemukan!\n";
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << temp->namaItem << "\" digunakan, sisa: " << temp->jumlah << endl;

    if (temp->jumlah <= 0) {
        cout << "Jumlah 0, item dihapus dari inventory.\n";

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;

        delete temp;
    }
}

void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n+============= INVENTORY (DEPAN KE BELAKANG) =============+\n";
    Item *temp = head;
    while (temp) {
        cout << "[" << temp->id << "] " << temp->namaItem
             << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
    cout << "+======================================================+\n";
}

void tampilkanInventoryDariBelakang() {
    if (!tail) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n+============= INVENTORY (BELAKANG KE DEPAN) =============+\n";
    Item *temp = tail;
    while (temp) {
        cout << "[" << temp->id << "] " << temp->namaItem
             << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << endl;
        temp = temp->prev;
    }
    cout << "+======================================================+\n";
}

void tampilkanDetailItem() {
    if (!head) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "Cari berdasarkan (1) ID atau (2) Nama: ";
    int opsi;
    cin >> opsi;
    cin.ignore();

    if (opsi == 1) {
        int cariID;
        cout << "Masukkan ID: ";
        cin >> cariID;
        cin.ignore();

        Item *temp = head;
        while (temp && temp->id != cariID) temp = temp->next;

        if (!temp) cout << "Item dengan ID " << cariID << " tidak ditemukan!\n";
        else {
            cout << "\n=== DETAIL ITEM ===\n";
            cout << "ID     : " << temp->id << endl;
            cout << "Nama   : " << temp->namaItem << endl;
            cout << "Tipe   : " << temp->tipe << endl;
            cout << "Jumlah : " << temp->jumlah << endl;
        }
    } else if (opsi == 2) {
        string cariNama;
        cout << "Masukkan Nama: ";
        getline(cin, cariNama);

        Item *temp = head;
        while (temp && temp->namaItem != cariNama) temp = temp->next;

        if (!temp) cout << "Item \"" << cariNama << "\" tidak ditemukan!\n";
        else {
            cout << "\n=== DETAIL ITEM ===\n";
            cout << "ID     : " << temp->id << endl;
            cout << "Nama   : " << temp->namaItem << endl;
            cout << "Tipe   : " << temp->tipe << endl;
            cout << "Jumlah : " << temp->jumlah << endl;
        }
    } else {
        cout << "Opsi tidak valid!\n";
    }
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
        cout << "||               [" << nama << " - " << nim << "]              ||\n";
        cout << "+=============================================+\n";
        cout << "|| 1. Tambah Item Baru                       ||\n";
        cout << "|| 2. Sisipkan Item                          ||\n";
        cout << "|| 3. Hapus Item Terakhir                    ||\n";
        cout << "|| 4. Gunakan Item                           ||\n";
        cout << "|| 5. Tampilkan Inventory dari Depan         ||\n";
        cout << "|| 6. Tampilkan Inventory dari Belakang      ||\n";
        cout << "|| 7. Tampilkan Detail Item                  ||\n";
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
            sisipItem(n, t, jumlahAwal);

        } else if (pilihan == 3) {
            hapusItemTerakhir();

        } else if (pilihan == 4) {
            string n;
            cout << "Nama item yang ingin digunakan: ";
            getline(cin, n);
            gunakanItem(n);

        } else if (pilihan == 5) {
            tampilkanInventory();

        } else if (pilihan == 6) {
            tampilkanInventoryDariBelakang();

        } else if (pilihan == 7) {
            tampilkanDetailItem();

        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan program ini!! <3.\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    while (head) {
        Item *tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}