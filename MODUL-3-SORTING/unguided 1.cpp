#include <iostream>

using namespace std;

// Fungsi untuk menukar nilai antara dua variabel
void swap(double *xp, double *yp) {
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Fungsi untuk mengurutkan array descending menggunakan algoritma Selection Sort
void selectionSort(double arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int max_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        // Tukar nilai
        swap(&arr[max_index], &arr[i]);
    }
}

int main() {
    double ips_mahasiswa[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips_mahasiswa) / sizeof(ips_mahasiswa[0]);

    cout << "IPS mahasiswa sebelum diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ips_mahasiswa[i] << " ";
    }
    cout << endl;

    // Panggil fungsi selectionSort untuk mengurutkan IPS
    selectionSort(ips_mahasiswa, n);

    cout << "\nIPS mahasiswa setelah diurutkan secara descending:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ips_mahasiswa[i] << " ";
    }
    cout << endl;

    return 0;
}
