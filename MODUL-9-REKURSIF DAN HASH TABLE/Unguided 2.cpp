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
