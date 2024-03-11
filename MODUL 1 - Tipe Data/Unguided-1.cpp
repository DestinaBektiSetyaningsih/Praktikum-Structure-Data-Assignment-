#include <iostream>
using namespace std;

int hitungKeliling(int s) {
    return 4 * s;
}

int hitungLuas(int d1, int d2) {
    return (d1 * d2) / 2;
}

int main() {
    int sisi, diagonal1, diagonal2, Destina;

    cout << "\nHITUNG BELAH KETUPAT\n";
    cout << "\nMasukkan panjang sisi: "; cin >> sisi;
    cout << "\nMasukkan panjang diagonal 1: "; cin >> diagonal1;
    cout << "\nMasukkan panjang diagonal 2: "; cin >> diagonal2;
    cout << "\nPilih Menu\n";
    cout << "1. Hitung Keliling\n";
    cout << "2. Hitung Luas\n";
    cout << "\nMasukkan Pilihan: "; cin >> Destina;

    switch (Destina) {
        case 1:
            cout << "\nHasil: " << hitungKeliling(sisi);
            break;
        case 2:
            cout << "\nHasil: " << hitungLuas(diagonal1, diagonal2);
            break;
        default:
            cout << "\nMaaf, pilihan Anda salah!";
    }

    return 0;
}