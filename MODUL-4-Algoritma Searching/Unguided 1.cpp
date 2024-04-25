#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk mencari indeks huruf menggunakan Binary Search
int binary_search(const string& sentence, char letter) {
    int left = 0;
    int right = sentence.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sentence[mid] == letter) {
            return mid;
        } else if (sentence[mid] < letter) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Fungsi utama
int main() {
    string sentence;
    char letter;

    // Input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Mengubah kalimat menjadi lowercase
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    // Input huruf yang dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> letter;
    letter = tolower(letter); // Mengubah huruf menjadi lowercase

    // Melakukan pencarian menggunakan Binary Search
    int index = binary_search(sentence, letter);

    // Menampilkan hasil pencarian
    if (index != -1) {
        cout << "Huruf '" << letter << "' ditemukan pada posisi ke-" << (index + 1) << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << letter << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
