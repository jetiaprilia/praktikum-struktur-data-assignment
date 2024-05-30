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
