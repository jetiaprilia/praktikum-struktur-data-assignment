# <h1 align="center">Laporan Praktikum Modul Stack dan Queue</h1>
<p align="center">Jeti Aprilia</p>
<p align="center">2311110059</p>

## Dasar Teori
 Stack adalah kumpulan suatu elemen dimana hanya elemen yang baru dimasukkan yang dapat diakses atau dilihat. Stack merupakan perintah pengumpulan data secara linear yang menyusun data seperti tumpukan dan bersifat Last In First Out(LIFO) yang berarti data yang terakhir masuk adalah data yang pertama keluar.
Operasi Stack yang biasa digunakan diantaranya yaitu :
1. Push
 untuk memasukkan atau menginputkan data
2. Pop
 untuk mengeluarkan data
3. IsFull
 untuk mengetahui jika tumpukan sudah penuh
4. IsEmpty
 untuk mengetahui tumpukan yang kosong, dan
5. Clear
 untuk menghapus seluruh data atau membersihkan data

Sedangkan queue adalah suatu proses antrian dalam suatu kumpulan data yang mana penambahan data atau elemen hanya dapat dilakukan pada sisi belakang sedangkan penghapusan atau pengeluaran elemen dilakukan pada sisi depan. Queue menggunakan sifat FIFO yaitu Fisrt In Fisrt Out, yang mana berarti pada antrian/data yang pertama dimasukkan adalah yang pertama diambil juga. 
Operasi queue adalah sebagai berikut:
1. Created
Digunakan untuk membuat dan menginisialisasi Queue dengan cara membuat Head dan Tail =1 Void
2. Isempty
Digunakan untuk memeriksa isi dari antrian apakah masih dalam keadaan kosong dengan cara memeriksa nilai Tail, jika Tail = -1 maka empty
3. Isfull
Untuk mengecek apakah antrian dalam keadaan penuh atau masih ada ruang kosong yang kosong yang tersisa dengan mengecek nilai Tail >=MAX-1 (karenaMAX-1 adalah batas elemen array pada C) berarti sudah penuh
4. Enqueue
Untuk menambahkan elemen ke dalam antrian dimana penambahan elemen dilakukan atau ditambahkan di elemen paling belakang
5. Dequeue
Digunakan untuk menghapus atau mengambil data elemen terdepan/pertama (head) dari antrian
6. Clear
Untuk menghapus elemen antrian dengan cara membuat Tail dan Head = -1, penghapusan ini bukan berarti menghapus array, namun hanya mengatur indeks pengakses menjadi 1

## Guided

### Guided 1
```c++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

### Guided 2

```c++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
```c++
#include <iostream>
#include <stack>
#include <cctype>

bool isPalindrome(std::string sentence) {
    // Menghapus semua karakter non-alphanumeric dan mengubah menjadi lowercase
    std::string clean_sentence;
    for (char c : sentence) {
        if (std::isalnum(c)) {
            clean_sentence += std::tolower(c);
        }
    }

    // Inisialisasi stack
    std::stack<char> stack;

    // Memasukkan setengah karakter pertama ke dalam stack
    int length = clean_sentence.length();
    for (int i = 0; i < length / 2; ++i) {
        stack.push(clean_sentence[i]);
    }

    // Membandingkan setengah karakter kedua dengan isi stack
    for (int i = (length + 1) / 2; i < length; ++i) {
        if (clean_sentence[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    // Jika stack kosong, berarti kalimat merupakan palindrom
    return true;
}

int main() {
    std::string kalimat;
    std::cout << "Kalimat: ";
    std::getline(std::cin, kalimat);

    if (isPalindrome(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        std::cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}
```

#### Output:

### Penjelasan
Pertama program meminta inputan dari user dengan bentuk memasukkan kalimat. Lalu kalimat tersebut difilter dengan menghapus alphanumeric, lalu diubah menjadi huruf kecil.
Setelah itu program setiap karakter akan dibalik secara otomatis yang lalu dibandingkan setiap karakternya. Dalam perbandingan ini karakter akan difilter dan dikeluarkan jika tidak cocok ditandai dengan nilai false yang menyatakan kalimat tersebut bukan polindrom.
Lalu jika kalimat tersebut adalah polindrom, maka nilainya adalah true. Terakhir program mencetak pernyataan polindrom/bukan polindrom dengan fungsi `isPalindrom`.

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.

```c++
#include <iostream>
#include <queue>
#include <cctype>

// Fungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom
bool isPalindrome(std::string sentence) {
    // Menghapus semua karakter non-alphanumeric dan mengubah menjadi lowercase
    std::string clean_sentence;
    for (char c : sentence) {
        if (std::isalnum(c)) {
            clean_sentence += std::tolower(c);
        }
    }

    // Inisialisasi queue
    std::queue<char> queue;

    // Memasukkan setengah karakter pertama ke dalam queue
    int length = clean_sentence.length();
    for (int i = 0; i < length / 2; ++i) {
        queue.push(clean_sentence[i]);
    }

    // Membandingkan setengah karakter kedua dengan isi queue
    for (int i = (length + 1) / 2; i < length; ++i) {
        if (clean_sentence[i] != queue.front()) {
            return false;
        }
        queue.pop();
    }

    // Jika queue kosong, berarti kalimat merupakan palindrom
    return true;
}

int main() {
    int choice;
    std::string sentence;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Input kalimat\n";
        std::cout << "2. Cek apakah kalimat adalah palindrom\n";
        std::cout << "3. Keluar\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); // Menggunakan ini untuk membersihkan buffer sebelum getline
                std::cout << "Masukkan kalimat: ";
                std::getline(std::cin, sentence);
                break;
            case 2:
                if (!sentence.empty()) {
                    if (isPalindrome(sentence)) {
                        std::cout << "Kalimat tersebut adalah palindrom.\n";
                    } else {
                        std::cout << "Kalimat tersebut bukan palindrom.\n";
                    }
                } else {
                    std::cout << "Anda belum memasukkan kalimat.\n";
                }
                break;
            case 3:
                std::cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n";
        }
    } while (choice != 3);

    return 0;
}
```

#### Output:

### Penjelasan
Setelah running program berjalan pada output akan menampilkan 3 opsi yaitu input kalimat, cek palindrom, dan keluar. Selanjutnya pada input kalimat setelah memasukkan kalimat yang akan di cek palindrom atau bukan, kalimat akan tersimpan dalam variabel `sentence`.
Pada opsi kedua dengan fungsi `isPalindrom` akan memeriksa dan menampilkan hasil palindrom/bukan. Jika pilihan yang dimasukkan tidak valid, program akan menampilkan pesan bahwa terdapat kesalahan dalam menginputkan opsi dan kembali ke menu.
Dalam pemeriksaan Palindrom, porgram akan memfilter, mengubah ke huruf kecil, dan membandingkan sehingga dapat menyatakan kalimat tersebut palindrom/bukan secara otomatis.


#### Kesimpulan
Stack dan Queue adalah program yang simple untuk digunakan, serta cara kerjanya tidak terlalu lama. Keduanya mempunyai persamaan untuk memfilter, mengubah, dan membandingkan, sehingga Stack dan Queue sama bagusnya.

## Referensi
G.A. Ahmad., dkk. (2021). "Pembelajaran Array, Linked List, Stack, dan Queue". 

