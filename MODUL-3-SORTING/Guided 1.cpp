#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array menggunakan algoritma buble sort
void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    double tmp;

    // Melakukan pengurutan hingga array sudah
    while (not_sorted) {
        not_sorted = false;
        j++;

        // Membandingkan dan menukar elemen
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                // Menukar elemen
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                // Set not_sorted ke true karena
                not_sorted = true;
            }
        }
    }
}

// Fungsi untuk mencetak isi array
void print_array(double a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6; // Jumlah elemen dalam
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}