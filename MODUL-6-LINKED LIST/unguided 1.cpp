#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string nama;
    int usia;
    Node* next;

    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void tambahTengah(string nama, int usia, string namaSebelum) {
        Node* newNode = new Node(nama, usia);
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelum) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void hapus(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void ubah(string namaLama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama == namaLama) {
                temp->nama = namaBaru;
                temp->usia = usiaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void tampilkan() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    // Masukkan data awal
    linkedList.tambahDepan("Jeti", 19);
    linkedList.tambahDepan("John", 19);
    linkedList.tambahBelakang("Jane", 20);
    linkedList.tambahBelakang("Michael", 18);
    linkedList.tambahBelakang("Yusuke", 19);
    linkedList.tambahBelakang("Akechi", 20);
    linkedList.tambahBelakang("Hoshino", 18);
    linkedList.tambahBelakang("Karin", 18);

    // Hapus data Akechi
    linkedList.hapus("Akechi");

    // Tambahkan data Futaba di antara John dan Jane
    linkedList.tambahTengah("Futaba", 18, "John");

    // Tambahkan data Igor di awal
    linkedList.tambahDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    linkedList.ubah("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Data setelah operasi:" << endl;
    linkedList.tampilkan();

    return 0;
}
