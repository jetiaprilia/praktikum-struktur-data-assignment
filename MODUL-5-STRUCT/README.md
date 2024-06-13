# <h1 align="center">Laporan Praktikum Modul Struck</h1>
<p align="center">Jeti Aprilia</p>
<p align="center">2311110059</p>

## Dasar Teori
Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct.

## Guided

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.
```C++
#include <iostream>
using namespace std;

struct Buku{{
    char judul_Buku;
    char pengarang;
    char penerbit;
    int tebal_Halaman;
    double harga_Buku;
}; Buku buku1;
}; Buku buku2;

int main(){

    Buku buku1;
    buku1.judul_Buku = "Midnight";
    buku1.pengarang = "Keigo Highasina";
    buku1.penerbit = "Gramedia Pustaka Utama";
    buku1.tebal_Halaman = 800;
    buku1.harga_Buku = 130000;
    Buku buku2;
    buku2.judul_Buku = "Algoritma Pemrograman";
    buku2.pengarang = "Yunus Prademon";
    buku2.penerbit = "Gramedia Pustaka Utama";
    buku2.tebal_Halaman = 900;
    buku2.harga_Buku = 99000;

//Menampilkan data
    cout << "Informasi Buku" << endl;
    cout << "Judul : " << buku1.judul_Buku << endl;
    cout << "Pengarang : " << buku1.pengarang << endl;
    cout << "Penerbit : " << buku1.penerbit << endl;
    cout << "Tebal Halaman : " << buku1.tebal_Halaman << endl;
    cout << "Harga Buku : " << buku1.harga_Buku << endl;
    cout << "Informasi Buku" << endl;
    cout << "Judul : " << buku2.judul_Buku << endl;
    cout << "Pengarang : " << buku2.pengarang << endl;
    cout << "Penerbit : " << buku2.penerbit << endl;
    cout << "Tebal Halaman : " << buku2.tebal_Halaman << endl;
    cout << "Harga Buku : " << buku2.harga_Buku << endl;

struct Buku buku1{
    Buku buku2{
    char buku1.judul_Buku;
    char buku1.pengarang;
    char buku1.penerbit;
    int buku1.tebal_Halaman;
    double buku1.harga_Buku;
    char buku2.judul_Buku;
    char buku2.pengarang;
    char buku2.penerbit;
    int buku2.tebal_Halaman;
    double buku2.harga_Buku;
}
}
```

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
```C++
#include <iostream>
using namespace std;

struct Hewan {
    string nama_hewan;
    string jenis_kelamin;
    string cara_berkembangbiak;
    string alat_pernafasan;
    string tempat_hidup;
    string apakah_karnivora;
}; Hewan info_hewan;

struct Hewan_Darat{
    int jumlah_kaki;
    string apakah_menyusui;
    string suara;
    Hewan info_hewan;
}; Hewan_Darat hewan1;

struct Hewan_Laut{
    string bentuk_sirip;
    string bentuk_pertahanan_diri;
    Hewan info_hewan;
}; Hewan_Laut hewan2;

int main() {
    // Membuat dan mengisi Hewan
    hewan1.info_hewan.nama_hewan = "Singa" ;
    hewan1.info_hewan.jenis_kelamin = "Jantan";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_pernafasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.apakah_karnivora = " Ya";
    hewan1.apakah_menyusui = "Ya";
    hewan1.suara = " arggg";

    hewan2.info_hewan.nama_hewan = "Hiu" ;
    hewan2.info_hewan.jenis_kelamin = "Jantan";
    hewan2.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan2.info_hewan.alat_pernafasan = "Insang";
    hewan2.info_hewan.tempat_hidup = "Laut";
    hewan2.info_hewan.apakah_karnivora = " Ya";
    hewan2.bentuk_sirip = "Membulat";
    hewan2.bentuk_pertahanan_diri = " Menyerang ";

// Menampilkan informasi Hewan
    cout << " Nama Hewan: " <<hewan1.info_hewan.nama_hewan << endl;
    cout << " Jenis Kelamin: " <<hewan1.info_hewan.jenis_kelamin << endl;
    cout << " Cara Berkembangbiak: " <<hewan1.info_hewan.cara_berkembangbiak<< endl;
    cout << " Alat Pernafasan: " <<hewan1.info_hewan.alat_pernafasan << endl;
    cout << " Tempat Hidup: " <<hewan1.info_hewan.tempat_hidup << endl;
    cout << " Apakah Karnivora: " <<hewan1.info_hewan.apakah_karnivora << endl;
    cout << " Apakah Menyusui " <<hewan1.apakah_menyusui << endl;
    cout << " Suara: " <<hewan1.suara << endl;

    cout << "\n Nama Hewan: " <<hewan2.info_hewan.nama_hewan << endl;
    cout << " Jenis Kelamin: " <<hewan2.info_hewan.jenis_kelamin << endl;
    cout << " Cara Berkembangbiak: " <<hewan2.info_hewan.cara_berkembangbiak<< endl;
    cout << " Alat Pernafasan: " <<hewan2.info_hewan.alat_pernafasan << endl;
    cout << " Tempat Hidup: " <<hewan2.info_hewan.tempat_hidup << endl;
    cout << " Apakah Karnivora: " <<hewan2.info_hewan.apakah_karnivora << endl;
    cout << " Bentuk Sirip " <<hewan2.bentuk_sirip << endl;
    cout << " Bentuk Pertahanan Diri: " <<hewan2.bentuk_pertahanan_diri << endl;

return 0;
}
```

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.
```C++
#include <stdio.h>
#include <string.h>

struct buku {
    char judul[5][50];
    char penulis[5][50];
    int tahun_terbit[5];
    float harga[5];
};

int main() {
    struct buku buku_saya;

    // Mengisi data ke dalam array yang berada dalam struct buku
    strcpy(buku_saya.judul[0], "The Poisson");
    strcpy(buku_saya.penulis[0], "Jeti Aprilia");
    buku_saya.tahun_terbit[0] = 2020;
    buku_saya.harga[0] = 95.50;

    strcpy(buku_saya.judul[1], "Critical Mind");
    strcpy(buku_saya.penulis[1], "Alih Hisyam");
    buku_saya.tahun_terbit[1] = 2025;
    buku_saya.harga[1] = 86.25;

    strcpy(buku_saya.judul[2], "Records of Rainy Days");
    strcpy(buku_saya.penulis[2], "Naela Eli");
    buku_saya.tahun_terbit[2] = 2022;
    buku_saya.harga[2] = 130.00;

    strcpy(buku_saya.judul[3], "Alzhemair");
    strcpy(buku_saya.penulis[3], "Kristina Ningrum");
    buku_saya.tahun_terbit[3] = 2018;
    buku_saya.harga[3] = 73.75;

    strcpy(buku_saya.judul[4], "A Healthy Mind");
    strcpy(buku_saya.penulis[4], "Akbar Firdaus");
    buku_saya.tahun_terbit[4] = 2020;
    buku_saya.harga[4] = 120.00;

    // Menampilkan data dari array yang berada dalam struct buku
    printf("Data Buku:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Buku %d:\n", i+1);
        printf("Judul: %s\n", buku_saya.judul[i]);
        printf("Penulis: %s\n", buku_saya.penulis[i]);
        printf("Tahun Terbit: %d\n", buku_saya.tahun_terbit[i]);
        printf("Harga: %.2f\n", buku_saya.harga[i]);
        printf("\n");
    }

    return 0;
}
```
### Penjelasan
Pertama kita masukkan dulu variable yang akan dicetak pada sebuah struct, seperti judul buku, penerbit, tahun terbit, dan harga buku. Lalu pada `int main` program ini akan meminta rincian yang telah diketahui pada sebuah buku atau barang untuk dapat mencetak struk seperti informasi yang telah disediakan.

### 2.Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?
```C++
#include <stdio.h>
#include <string.h>

struct buku {
    char judul[5][50];
    char penulis[5][50];
    int tahun_terbit[5];
    float harga[5];
};

int main() {
    struct buku buku_saya[3]; // Deklarasi array dari struct buku 

    // Mengisi data ke dalam array yang berada dalam struct buku
    strcpy(buku_saya[0].judul[0], "The Poisson");
    strcpy(buku_saya[0].penulis[0], "Jeti Aprilia");
    buku_saya[0].tahun_terbit[0] = 2020;
    buku_saya[0].harga[0] = 95.50;

    // Mengisi data untuk elemen kedua
    strcpy(buku_saya[1].judul[0], "Critical Mind");
    strcpy(buku_saya[1].penulis[0], "Alih Hisyam");
    buku_saya[1].tahun_terbit[0] = 2025;
    buku_saya[1].harga[0] = 86.25;

    // Mengisi data untuk elemen ketiga
    strcpy(buku_saya[2].judul[0], "Records of Rainy Days");
    strcpy(buku_saya[2].penulis[0], "Naela Eli");
    buku_saya[2].tahun_terbit[0] = 2022;
    buku_saya[2].harga[0] = 130.00;

    // Mengisi data untuk elemen keempat
    strcpy(buku_saya[2].judul[0], "Alzhemair");
    strcpy(buku_saya[2].penulis[0], "Kristina Ningrum");
    buku_saya[2].tahun_terbit[0] = 2018;
    buku_saya[2].harga[0] = 73.75;

    // Mengisi data untuk elemen kelima
    strcpy(buku_saya[2].judul[0], "A Healthy Mind");
    strcpy(buku_saya[2].penulis[0], "Akbar Firdaus");
    buku_saya[2].tahun_terbit[0] = 2020;
    buku_saya[2].harga[0] = 120.00;

    // Menampilkan data dari array yang berada dalam struct buku
    printf("Data Buku:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Buku %d:\n", i+1);
        printf("Judul: %s\n", buku_saya[i].judul[0]);
        printf("Penulis: %s\n", buku_saya[i].penulis[0]);
        printf("Tahun Terbit: %d\n", buku_saya[i].tahun_terbit[0]);
        printf("Harga: %.2f\n", buku_saya[i].harga[0]);
        printf("\n");
    }

    return 0;
}
```
Penjelasan:
Program akan semakin efektif untuk mencetak beberapa struk buku atau barang sekaligus. Dengan memasukkan array untuk mencetak struk buku atau barang program akan mengeksekusi sesuai dengan array yang diminta.

## Kesimpulan
Struct adalah program yang sering dibutuhkan dalam kehidupan sehari-hari. Kegiatan seperti berbelanja di sebuah toko tentu membutuhkan program struk untuk membantu mencetak struk dengan waktu yang singkat dan efisien.

## Referensi
[1]http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf
