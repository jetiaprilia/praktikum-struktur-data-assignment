#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menukar dua string
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan array string sesuai abjad menggunakan algoritma Bubble Sort
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    string warga[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(warga) / sizeof(warga[0]);

    cout << "Nama-nama warga sebelum diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << warga[i] << " ";
    }
    cout << endl;

    // Panggil fungsi bubbleSort untuk mengurutkan nama warga
    bubbleSort(warga, n);

    cout << "\nNama-nama warga setelah diurutkan sesuai abjad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << warga[i] << " ";
    }
    cout << endl;

    return 0;
}
