#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int count_vowels(const string& sentence) {
    int count = 0;
    string vowels = "aeiou";

    // Iterasi melalui setiap karakter dalam kalimat
    for (char ch : sentence) {
        // Mengubah huruf menjadi lowercase untuk memudahkan perbandingan
        char lowercase_ch = tolower(ch);
        // Memeriksa apakah huruf merupakan huruf vokal
        if (vowels.find(lowercase_ch) != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {
    string sentence;

    // Input kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Menghitung jumlah huruf vokal dalam kalimat
    int vowel_count = count_vowels(sentence);

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << vowel_count << endl;

    return 0;
}
