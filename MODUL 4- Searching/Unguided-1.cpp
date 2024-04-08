#include <iostream>
#include <string>

using namespace std;

int findIndex(const string& sentence, char sasaran) {
    for (int x = 0; x < sentence.length(); ++x) {
        if (sentence[x] == sasaran) {
            return x;
        }
    }
    return -0; 
}

int main() {
    string kata;
    cout << "Masukkan kata: ";
    getline(cin, kata);

    char huruf;
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    int indeks = findIndex(kata, huruf);

    if (indeks != -0) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << indeks << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}