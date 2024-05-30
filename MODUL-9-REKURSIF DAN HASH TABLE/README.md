# <h1 align="center">Laporan Praktikum Modul Rekursif dan Hash Table</h1>
<p align="center">Jeti Aprilia</p>
<p align="center">2311110059</p>

## Dasar Teori
Rekursif adalah salah satu metode dalam dunia matematika dimana definisi sebuah fungsi mengandung fungsi itu sendiri. Dalam dunia pemrograman, rekursi diimplementasikan dalam sebuah fungsi yang memanggil dirinya sendiri.
Rekursi adalah cara untuk menetapkan proses dengan dirinya sendiri Sebagai contoh, berikut ini adalah definisi rekursif dari seorang leluhur seseorang: Orang tua seseorang adalah leluhur orang tersebut. (Basis kasus) Orang tua dari leluhur seseorang adalah juga leluhur orang tersebut. (Langkah rekursif)
Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri. Fungsi rekursif disusun atas dua bagian, yaitu basis dan rekurens. Basis berisi nilai awal yang tidak mengacu pada dirinya sendiri. Bagian ini berfungsi untuk memberikan nilai yang terdefinisi pada fungsi rekursif dan sekaligus menghentikan proses rekursi.

### a. Konsep fungsi rekursif
Konsep pemrograman fungsi rekursif sebenarnya mirip dengan konsep fungsi rekursif dalam matematika yaitu sebagai berikut:
1. Menentukan kasus penyetop atau kasus dasar dimana pemanggilan rekursif tidak lagi diperlukan karena solusinya sudah diperoleh) -> basis
2. Menerapkan suatu langkah untuk menggiring kasus kompleks ke kasus penyetopnya dengan metode yang mencerminkan fungsinya -> rekurens

### b. Kelebihan dan kekurangan fungsi rekursif
1. Algoritma biasanya lebih ringkas dan mudah dipahami
2. Membutuhkan alokasi memori yang besar (kecuali pada fungsi “Tail-Recursive”)
3. Tidak cocok ketika kinerja tinggi diperlukan, karena terjadi overhead pemanggilan fungsi dalam jumlah yang relatif besar

### Hash Table

Table hash adalah sebuah cara untuk menyimpan program ke dalam baris atau kolom sehingga membentuk table yang dapat diakses dengan cepat. Lalu untuk pertemuan antara sel-sel table dan baris dinamakan slot.
Sebuah table hash dapat dibuat dengan array dan sebuah fungsi pemetakan yang disebut hash function. Dalam function ini fungsi mendistribusikan data yang tekah dimasukkan oleh user ke dalam tabel atau larik yang telah disediakan.
Algoritma hash table dapat diimplementasikan untuk mengarsipkan dan mencari suatu data dengan waktu O(1).
Bila ada suatu pola yang dicari, sistem pencarian yang digunakan adalah mencari karakter pertama, dan jika tidak cocok maka akan dicocokkan pada urutan pola karakter yang dicari.

## Guided

#### Guided 1

```C++
#include <iostream>
using namespace std;

//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        cout << n << " ";
        return; // Mengakhiri rekursi saat n == 0
    }
    cout << n << " ";
    countdown(n - 1);
}
int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}
```

#### Guided 2

```C++
#include <iostream>
using namespace std;
void functionB(int n);
void functionA(int n) {
if (n > 0) {
cout << n << " ";
functionB(n - 1); // Panggilan rekursif tidak langsung
}
}
void functionB(int n) {
if (n > 0) {
cout << n << " ";
functionA(n / 2); // Panggilan rekursif tidak langsung
}
}

int main() {
int num = 5;
cout << "Rekursif Tidak Langsung: ";
functionA(num);
return 0;
}

```

#### Guided 3

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory> // untuk std::unique_ptr
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<unique_ptr<HashNode>> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto& node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].emplace_back(make_unique<HashNode>(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        auto& cell = table[hash_val];
        auto it = remove_if(cell.begin(), cell.end(), [&](const unique_ptr<HashNode>& node) {
            return node->name == name;
        });
        if (it != cell.end()) {
            cell.erase(it, cell.end());
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (const auto& node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (const auto& pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    cout << "Phone Hp Ghana : " << employee_map.searchByName("Ghana") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;

    employee_map.print();
    return 0;
}
```

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
Contoh Output:
Masukkan bilangan bulat positif: 5
Faktorial dari 5 adalah: 120

```C++
#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```
#### Output:
https://github.com/jetiaprilia/praktikum-struktur-data-assignment/blob/main/MODUL-9-REKURSIF%20DAN%20HASH%20TABLE/output/Unguided%201.exe

### Penjelasan:
Fungsi `factorial` digunakan untuk menghitung faktorial bilangan n, dengan basis rekusri n <= 1 untuk mengembalikan 1, jika tidak fungsi mengkalikan n dengan hasil n-1
Di fungsi `main` program meminta user memasukkan bilangan bulat positif
Jika yang dimasukkan user bukan bilangan positif maka program akan menampilkan pesan kesalahan
Dengan fungsi `factorial` hasil akan ditampilkan

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
#include <iostream>
using namespace std;

// Deklarasi fungsi
int factorial_helper(int n);
int factorial(int n);

// Fungsi pembantu yang memanggil factorial
int factorial_helper(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Fungsi utama yang memanggil factorial_helper
int factorial(int n) {
    return factorial_helper(n);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```
#### Output:
https://github.com/jetiaprilia/praktikum-struktur-data-assignment/blob/main/MODUL-9-REKURSIF%20DAN%20HASH%20TABLE/output/Unguided%202.exe

### Penjelasan:
Pertama program yang akan mendeklarasikan fungsi yaitu `factorial_helper` dan `factorial`.
`factorial_helper` bertugas untuk jika n <= 1 maka mengembalikan 1, dan jika tidak maka n akan dikalikan sebagai bentuk dari faktorial n-1
`factorial` bertugas untuk memulai proses rekursi dan menciptakan rekursi tidak langsung
Di program inti yaitu `main` program meminta user memasukkan bilangan bulat positif, dan jika bukan bilangan tersebut maka akan ditampilkan pesan kesalahan, dan jika benar maka hasil akan keluar.

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa
memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,
menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan
nilai. Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
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
```
#### Output:
https://github.com/jetiaprilia/praktikum-struktur-data-assignment/blob/main/MODUL-9-REKURSIF%20DAN%20HASH%20TABLE/output/Unguided%203.exe

### Penjelasan:
Dalam hash memiliki penjelasan yang cukup kompleks. Dalam fungsi `Student` untuk menyimpan data berupa NIM dan nilai, `hashFunc`= menghitung nilai hash untuk sebuah NIM, `insert` dan `remove` untuk menambah dan menghapus data, lalu untuk mencari nilai mahasiswa berdasarkan NIM dengan `searchByNIM`, kemudian untuk mencari dan menampilkan data dalam range nilai tertentu= `searchByRange`
Sedangkan untuk menampilkan menu ada fungsi `displayMenu`, dan fungsi `main` untuk eksekusi program dan menampilkan serta menginputkan data.

## Kesimpulan
Rekursif dapat diimplementasikan dalam fungsi yang memanggil dirinya sendiri, dan hanya dapat untuk kasus yang tidak rumit, sedangkan untuk kasus yang lebih kompleks sebaiknya menggunakan fungsi lain. Sedangkan hash adalah sebuah fungsi pemetaan yang dapat menghasilkan program lebih cepat dari Sequential Sort, dengan kompleksitas waktu O(1).

## Referensi
[1] https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-079.pdf

[2] https://repository.uksw.edu/bitstream/123456789/1012/2/ART_Jasson%20Prestiliano_Aplikasi%20tabel%20hash_Full%20text.pdf
