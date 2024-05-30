#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <limits> // Untuk std::numeric_limits
using namespace std;

const int TABLE_SIZE = 11;

class Student {
public:
    string NIM;
    int nilai;
    Student(string NIM, int nilai) {
        this->NIM = NIM;
        this->nilai = nilai;
    }
};

class HashTable {
private:
    vector<unique_ptr<Student>> table[TABLE_SIZE];

    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

public:
    void insert(string NIM, int nilai) {
        int hash_val = hashFunc(NIM);
        for (auto& student : table[hash_val]) {
            if (student->NIM == NIM) {
                student->nilai = nilai;
                return;
            }
        }
        table[hash_val].emplace_back(make_unique<Student>(NIM, nilai));
    }

    void remove(string NIM) {
        int hash_val = hashFunc(NIM);
        auto& cell = table[hash_val];
        auto it = remove_if(cell.begin(), cell.end(), [&](const unique_ptr<Student>& student) {
            return student->NIM == NIM;
        });
        if (it != cell.end()) {
            cell.erase(it, cell.end());
        }
    }

    int searchByNIM(string NIM) {
        int hash_val = hashFunc(NIM);
        for (const auto& student : table[hash_val]) {
            if (student->NIM == NIM) {
                return student->nilai;
            }
        }
        return -1; // Indikasi bahwa NIM tidak ditemukan
    }

    void searchByRange(int low, int high) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (const auto& student : table[i]) {
                if (student->nilai >= low && student->nilai <= high) {
                    cout << "NIM: " << student->NIM << ", Nilai: " << student->nilai << endl;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (const auto& student : table[i]) {
                if (student != nullptr) {
                    cout << "[" << student->NIM << ", " << student->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Hapus Data Mahasiswa\n";
    cout << "3. Cari Data Berdasarkan NIM\n";
    cout << "4. Cari Data Berdasarkan Rentang Nilai (80-90)\n";
    cout << "5. Tampilkan Semua Data\n";
    cout << "6. Keluar\n";
}

int main() {
    HashTable studentTable;
    int choice;
    do {
        displayMenu();
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

        if (choice == 1) {
            string NIM;
            int nilai;
            cout << "Masukkan NIM: ";
            getline(cin, NIM);
            cout << "Masukkan nilai: ";
            while (!(cin >> nilai)) {
                cin.clear(); // Menghapus kesalahan cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
                cout << "Masukkan nilai yang valid: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
            studentTable.insert(NIM, nilai);
        } else if (choice == 2) {
            string NIM;
            cout << "Masukkan NIM untuk dihapus: ";
            getline(cin, NIM);
            studentTable.remove(NIM);
        } else if (choice == 3) {
            string NIM;
            cout << "Masukkan NIM untuk dicari: ";
            getline(cin, NIM);
            int nilai = studentTable.searchByNIM(NIM);
            if (nilai == -1) {
                cout << "Data tidak ditemukan.\n";
            } else {
                cout << "Nilai mahasiswa dengan NIM " << NIM << " adalah: " << nilai << endl;
            }
        } else if (choice == 4) {
            cout << "Mahasiswa dengan nilai antara 80 dan 90:\n";
            studentTable.searchByRange(80, 90);
        } else if (choice == 5) {
            studentTable.print();
        } else if (choice != 6) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 6);

    return 0;
}
