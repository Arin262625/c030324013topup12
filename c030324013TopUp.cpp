#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

struct Pelanggan {
    string nama;
    string namaItem;
    int hargaItem;
};

struct Node {
    Pelanggan data;
    Node* next;
};

Node* head = nullptr;

void inisialisasiData() {
    Node* n1 = new Node{{"Aulia", "Diamond FF", 15500}, nullptr};
    Node* n2 = new Node{{"Adel", "UC PUBG", 14000}, nullptr};
    Node* n3 = new Node{{"Arin", "Diamond ML", 9000}, nullptr};

    head = n1;
    n1->next = n2;
    n2->next = n3;

    cout << "Data pelanggan berhasil dimasukkan.\n";
    getch();
}

void tampilkanPelanggan() {
    system("cls");
    if (head == nullptr) {
        cout << "Belum ada data pelanggan.\n";
    } else {
        cout << left << setw(5) << "No"
             << setw(20) << "Nama"
             << setw(20) << "Item"
             << setw(15) << "Harga Item" << endl;

        int no = 1;
        for (Node* p = head; p != nullptr; p = p->next) {
            cout << setw(5) << no++
                 << setw(20) << p->data.nama
                 << setw(20) << p->data.namaItem
                 << "Rp " << p->data.hargaItem << endl;
        }
    }
    getch();
}

void tambahPelanggan() {
    system("cls");
    Node* baru = new Node;
    cout << "Nama Pelanggan: "; cin >> ws; getline(cin, baru->data.nama);
    cout << "Item yang dipilih: "; getline(cin, baru->data.namaItem);
    cout << "Harga Top Up: Rp "; cin >> baru->data.hargaItem;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != nullptr)
            p = p->next;
        p->next = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
    getch();

    tampilkanPelanggan();
}

void hapusPelanggan() {
    system("cls");
    if (head == nullptr) {
        cout << "Data kosong!\n";
        getch();
        return;
    }
    int no;
    cout << "\nMasukkan nomor pelanggan yang ingin dihapus: ";
    cin >> no;

    if (no < 1) {
        cout << "Nomor tidak valid!\n";
        getch();
        return;
    }
    Node* hapus;
    if (no == 1) {
        hapus = head;
        head = head->next;
    } else {
        Node* p = head;
        for (int i = 1; i < no - 1 && p != nullptr; i++)
            p = p->next;

        if (p == nullptr || p->next == nullptr) {
            cout << "Nomor tidak valid!\n";
            getch();
            return;
        }
        hapus = p->next;
        p->next = hapus->next;
    }

    cout << "Data \"" << hapus->data.nama << "\" berhasil dihapus.\n";
    delete hapus;
    getch();

    tampilkanPelanggan();
}

void totalHarga() {
    system("cls");
    int total = 0;
    for (Node* p = head; p != nullptr; p = p->next)
        total += p->data.hargaItem;

    cout << "Total seluruh harga top up: Rp " << total << endl;
    getch();
}

int main() {
    char pilih;
    do {
        menu();
        pilih = getch();
        switch (pilih) {
            case '1': inisialisasiData(); 
            break;
 
            case '2': tampilkanPelanggan(); 
            break;

            case '3': tambahPelanggan();
            break;

            case '4': hapusPelanggan(); 
            break;

            case '5': totalHarga(); 
            break;

            case '6': 
            break;

            default:
                system("cls");
                cout << "Pilihan tidak tersedia!\n";
                getch();
                break;
        }
    } while (pilih != '6');

    return 0;
}