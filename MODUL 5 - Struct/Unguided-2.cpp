#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan array dari struktur buku dengan ukuran 5
    buku array_buku[5];

    // Mengisi data ke dalam array dari struktur buku
    for (int i = 0; i < 5; i++) {
        array_buku[i].judulBuku = "The Alpha Girl's Guide";
        array_buku[i].pengarang = "Henry Manampiring";
        array_buku[i].penerbit = "Gagas Media";
        array_buku[i].tebalHalaman = 253;
        array_buku[i].hargaBuku = 79000;
    }

    // Menampilkan data dari array dari struktur buku
    cout << "Data Buku:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Buku ke-" << i + 1 << endl;
        cout << "Judul: " << array_buku[i].judulBuku << endl;
        cout << "Pengarang: " << array_buku[i].pengarang << endl;
        cout << "Penerbit: " << array_buku[i].penerbit << endl;
        cout << "Tebal Halaman: " << array_buku[i].tebalHalaman << " halaman" << endl;
        cout << "Harga Buku: Rp " << array_buku[i].hargaBuku << endl;
        cout << endl;
    }

    return 0;
}