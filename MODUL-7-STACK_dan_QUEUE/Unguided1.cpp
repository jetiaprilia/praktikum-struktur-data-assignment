#include <iostream>
#include <stack>
#include <cctype>

bool isPalindrome(std::string sentence) {
    // Menghapus semua karakter non-alphanumeric dan mengubah menjadi lowercase
    std::string clean_sentence;
    for (char c : sentence) {
        if (std::isalnum(c)) {
            clean_sentence += std::tolower(c);
        }
    }

    // Inisialisasi stack
    std::stack<char> stack;

    // Memasukkan setengah karakter pertama ke dalam stack
    int length = clean_sentence.length();
    for (int i = 0; i < length / 2; ++i) {
        stack.push(clean_sentence[i]);
    }

    // Membandingkan setengah karakter kedua dengan isi stack
    for (int i = (length + 1) / 2; i < length; ++i) {
        if (clean_sentence[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    // Jika stack kosong, berarti kalimat merupakan palindrom
    return true;
}

int main() {
    std::string kalimat;
    std::cout << "Kalimat: ";
    std::getline(std::cin, kalimat);

    if (isPalindrome(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        std::cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}
