#include <iostream>
#include <string>
using namespace std;

const int jumlah_buku = 5;
/// Mendefinisikan struktur buku
struct Buku {
    string judul_buku[jumlah_buku];
    string penulis[jumlah_buku];
    string penerbit[jumlah_buku];
    int tebal_buku[jumlah_buku];
    double harga_buku[jumlah_buku];
};

int main() {
    Buku daftar_buku;

    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Masukkan informasi untuk buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, daftar_buku.judul_buku[i]);
        cout << "Penulis: ";
        getline(cin, daftar_buku.penulis[i]);
        cout << "Penerbit: ";
        getline(cin, daftar_buku.penerbit[i]);
        cout << "Tebal Buku: ";
        cin >> daftar_buku.tebal_buku[i];
        cout << "Harga Buku: Rp";
        cin >> daftar_buku.harga_buku[i];
        cin.ignore(); 
    }

    cout << "\nDaftar Buku:" << endl;
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku: " << daftar_buku.judul_buku[i] << endl;
        cout << "Penulis: " << daftar_buku.penulis[i] << endl;
        cout << "Penerbit: " << daftar_buku.penerbit[i] << endl;
        cout << "Tebal Buku: " << daftar_buku.tebal_buku[i] << endl;
        cout << "Harga Buku: Rp" << daftar_buku.harga_buku[i] << endl;
        cout << endl;
    }

    return 0;
}