#include <iostream>
#include <vector>

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

    // Menampilkan data array yang dimasukkan oleh pengguna
    cout << "\nData Array :";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor genap :";
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            cout << " " << arr[i];
            if (i != size - 1 && arr[i+1] % 2 == 0) {
                cout << ",";
            }
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor ganjil :";
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            cout << " " << arr[i];
            if (i != size - 1 && arr[i+1] % 2 != 0) {
                cout << ",";
            }
        }
    }
    cout << endl;

    return 0;
}
