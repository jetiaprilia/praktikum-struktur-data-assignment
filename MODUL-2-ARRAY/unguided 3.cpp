#include <iostream>
#include <vector>
#include <limits> // Untuk menggunakan nilai maksimum dan minimum dari tipe data

using namespace std;

int main() {
    int size;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> size;

    // Membuat array dengan ukuran yang dimasukkan oleh pengguna
    vector<int> arr(size);

    // Meminta pengguna memasukkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Menginisialisasi variabel untuk menyimpan nilai maksimum, minimum, dan rata-rata
    int max_value = numeric_limits<int>::min(); // Nilai maksimum awal diatur ke nilai minimum yang mungkin
    int min_value = numeric_limits<int>::max(); // Nilai minimum awal diatur ke nilai maksimum yang mungkin
    double sum = 0.0;

    // Menghitung nilai maksimum, minimum, dan menjumlahkan semua elemen
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
        sum += arr[i];
    }

    // Menghitung nilai rata-rata
    double average = sum / size;

    // Menampilkan hasil
    cout << "\nNilai maksimum: " << max_value << endl;
    cout << "Nilai minimum: " << min_value << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}
