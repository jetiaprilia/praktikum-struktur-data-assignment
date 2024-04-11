#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    char characters[n];

    // Meminta pengguna untuk memasukkan karakter
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    // Pengurutan karakter secara naik
    sort(characters, characters + n);

    // Menampilkan hasil pengurutan naik
    cout << "\nPengurutan karakter secara naik:" << endl;
    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }
    cout << endl;

    // Pengurutan karakter secara turun
    sort(characters, characters + n, greater<char>());

    // Menampilkan hasil pengurutan turun
    cout << "\nPengurutan karakter secara turun:" << endl;
    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }
    cout << endl;

    return 0;
}
