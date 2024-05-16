#include <iostream>
#include <queue>
#include <cctype>

// Fungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom
bool isPalindrome(std::string sentence) {
    // Menghapus semua karakter non-alphanumeric dan mengubah menjadi lowercase
    std::string clean_sentence;
    for (char c : sentence) {
        if (std::isalnum(c)) {
            clean_sentence += std::tolower(c);
        }
    }

    // Inisialisasi queue
    std::queue<char> queue;

    // Memasukkan setengah karakter pertama ke dalam queue
    int length = clean_sentence.length();
    for (int i = 0; i < length / 2; ++i) {
        queue.push(clean_sentence[i]);
    }

    // Membandingkan setengah karakter kedua dengan isi queue
    for (int i = (length + 1) / 2; i < length; ++i) {
        if (clean_sentence[i] != queue.front()) {
            return false;
        }
        queue.pop();
    }

    // Jika queue kosong, berarti kalimat merupakan palindrom
    return true;
}

int main() {
    int choice;
    std::string sentence;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Input kalimat\n";
        std::cout << "2. Cek apakah kalimat adalah palindrom\n";
        std::cout << "3. Keluar\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); // Menggunakan ini untuk membersihkan buffer sebelum getline
                std::cout << "Masukkan kalimat: ";
                std::getline(std::cin, sentence);
                break;
            case 2:
                if (!sentence.empty()) {
                    if (isPalindrome(sentence)) {
                        std::cout << "Kalimat tersebut adalah palindrom.\n";
                    } else {
                        std::cout << "Kalimat tersebut bukan palindrom.\n";
                    }
                } else {
                    std::cout << "Anda belum memasukkan kalimat.\n";
                }
                break;
            case 3:
                std::cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n";
        }
    } while (choice != 3);

    return 0;
}
