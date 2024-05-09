#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;

    Node(string nama_produk, int harga) {
        this->nama_produk = nama_produk;
        this->harga = harga;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahBelakang(string nama_produk, int harga) {
        Node* newNode = new Node(nama_produk, harga);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void tambahTengah(string nama_produk, int harga, string nama_sebelum) {
        Node* newNode = new Node(nama_produk, harga);
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->nama_produk != nama_sebelum) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk tidak ditemukan" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void hapus(string nama_produk) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->nama_produk != nama_produk) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk tidak ditemukan" << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
        }
        if (temp == tail) {
            tail = tail->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void update(string nama_produk_lama, string nama_produk_baru, int harga_baru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama_produk == nama_produk_lama) {
                temp->nama_produk = nama_produk_baru;
                temp->harga = harga_baru;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void tampilkan() {
        cout << "Nama Produk\tHarga" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama_produk << "\t\t" << temp->harga << endl;
            temp = temp->next;
        }
    }

    void hapusSeluruh() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = nullptr;
    }
};

int main() {
    DoubleLinkedList dll;

    // Masukkan data awal
    dll.tambahBelakang("Originote", 60000);
    dll.tambahBelakang("Somethinc", 150000);
    dll.tambahBelakang("Skintific", 100000);
    dll.tambahBelakang("Wardah", 50000);
    dll.tambahBelakang("Hanasui", 30000);

    int pilihan;
    string nama_produk, nama_sebelum, nama_baru;
    int harga, harga_baru;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> nama_produk;
                cout << "Harga: ";
                cin >> harga;
                dll.tambahBelakang(nama_produk, harga);
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama_produk;
                dll.hapus(nama_produk);
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> nama_produk;
                cout << "Nama Produk baru: ";
                cin >> nama_baru;
                cout << "Harga baru: ";
                cin >> harga_baru;
                dll.update(nama_produk, nama_baru, harga_baru);
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> nama_produk;
                cout << "Harga: ";
                cin >> harga;
                cout << "Nama Produk sebelumnya: ";
                cin >> nama_sebelum;
                dll.tambahTengah(nama_produk, harga, nama_sebelum);
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama_produk;
                dll.hapus(nama_produk);
                break;
            case 6:
                dll.hapusSeluruh();
                break;
            case 7:
                dll.tampilkan();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (pilihan != 8);

    return 0;
}

