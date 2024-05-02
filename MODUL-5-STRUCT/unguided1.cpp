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

