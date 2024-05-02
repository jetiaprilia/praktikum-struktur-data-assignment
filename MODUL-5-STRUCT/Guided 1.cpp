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
