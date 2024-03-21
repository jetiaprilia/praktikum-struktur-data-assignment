#include <iostream>

// Fungsi untuk menghitung luas persegi
int calculate_square_area(int side) {
    return side * side;
}

// Fungsi untuk memeriksa apakah suatu bilangan adalah bilangan genap atau ganjil
void check_even_odd(int number) {
    if (number % 2 == 0)
        std::cout << number << " adalah bilangan genap." << std::endl;
    else
        std::cout << number << " adalah bilangan ganjil." << std::endl;
}

int main() {
    // Input panjang sisi persegi dari pengguna
    int side;
    std::cout << "Masukkan panjang sisi persegi: ";
    std::cin >> side;

    // Hitung dan cetak luas persegi
    int area = calculate_square_area(side);
    std::cout << "Luas persegi dengan panjang sisi " << side << " adalah: " << area << std::endl;

    // Input bilangan bulat dari pengguna
    int number;
    std::cout << "Masukkan sebuah bilangan bulat: ";
    std::cin >> number;

    // Periksa dan cetak apakah bilangan tersebut genap atau ganjil
    check_even_odd(number);

    return 0;
}





#include <iostream>

// Fungsi untuk menghitung luas persegi
int hitungLuasPersegi(int sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume kubus
float hitungVolumeKubus(int sisi) {
    return sisi * sisi * sisi;
}

int main() {
    int sisiPersegi;
    std::cout << "Masukkan panjang sisi persegi: ";
    std::cin >> sisiPersegi;

    int luasPersegi = hitungLuasPersegi(sisiPersegi);
    std::cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah: " << luasPersegi << std::endl;

    float volumeKubus = hitungVolumeKubus(sisiPersegi);
    std::cout << "Volume kubus dengan sisi " << sisiPersegi << " adalah: " << volumeKubus << std::endl;

    return 0;
}
