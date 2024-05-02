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
