#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan pencarian sequential pada array
int sequential_search(const vector<int>& data, int target) {
    int count = 0;

    // Iterasi melalui setiap elemen array
    for (int num : data) {
        // Jika elemen saat ini sama dengan target, tambahkan ke hitungan
        if (num == target) {
            count++;
        }
    }

    return count;
}

int main() {
    // Data yang diberikan
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4; // Angka yang ingin dicari

    // Menghitung berapa kali angka 4 muncul dalam data
    int count = sequential_search(data, target);

    // Menampilkan hasil
    cout << "Jumlah kemunculan angka " << target << " dalam data adalah: " << count << endl;

    return 0;
}
