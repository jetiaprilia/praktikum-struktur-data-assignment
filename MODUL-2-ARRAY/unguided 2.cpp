#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Meminta pengguna memasukkan ukuran atau jumlah elemen array tiga dimensi
    int size[3];
    cout << "Masukkan ukuran array tiga dimensi:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Ukuran dimensi ke-" << i + 1 << ": ";
        cin >> size[i];
    }

    // Membuat array tiga dimensi dengan ukuran yang dimasukkan oleh pengguna
    vector<vector<vector<int>>> arr(size[0], vector<vector<int>>(size[1], vector<int>(size[2])));

    // Meminta pengguna memasukkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array:\n";
    for (int i = 0; i < size[0]; ++i) {
        for (int j = 0; j < size[1]; ++j) {
            for (int k = 0; k < size[2]; ++k) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Menampilkan isi array tiga dimensi
    cout << "\nArray tiga dimensi yang dimasukkan:\n";
    for (int i = 0; i < size[0]; ++i) {
        for (int j = 0; j < size[1]; ++j) {
            for (int k = 0; k < size[2]; ++k) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
