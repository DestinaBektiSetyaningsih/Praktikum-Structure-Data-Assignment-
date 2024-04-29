#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct Buku {
  string judulBuku[5];
  string penulis[5];
  string penerbit[5];
  int tebalBuku[5];
  int hargaBuku[5];
};

int main() {
  // Mendeklarasikan variabel buku dengan tipe Buku
  Buku buku;

  // Mengisi data ke dalam array di dalam variabel buku
  buku.judulBuku[0] = "Sejarah DUNIA yang disembunyikan";
  buku.judulBuku[1] = "Insecurity";
  buku.judulBuku[2] = "Overthinking";
  buku.judulBuku[3] = "CANTIK itu LUKA";
  buku.judulBuku[4] = "Konspirasi Alam Semesta";

  buku.penulis[0] = "Jonathan Black";
  buku.penulis[1] = "Alvi Syahrin";
  buku.penulis[2] = "Alvi Syahrin";
  buku.penulis[3] = "Eka Kurniawan";
  buku.penulis[4] = "Fiersa Besari";

  buku.penerbit[0] = "Alvabeta";
  buku.penerbit[1] = "Kawah Media";
  buku.penerbit[2] = "Kawah Media";
  buku.penerbit[3] = "Gramedia Pustaka Utama";
  buku.penerbit[4] = "Media Kita";

  buku.tebalBuku[0] = 636;
  buku.tebalBuku[1] = 264;
  buku.tebalBuku[2] = 268;
  buku.tebalBuku[3] = 520;
  buku.tebalBuku[4] = 238;

  buku.hargaBuku[0] = 165000;
  buku.hargaBuku[1] = 84000;
  buku.hargaBuku[2] = 90000;
  buku.hargaBuku[3] = 94000;
  buku.hargaBuku[4] = 75000;

  // Menampilkan informasi buku
  cout << "\tDaftar Buku" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "\n\tBuku ke-" << i + 1 << endl;
    cout << "\tJudul Buku: " << buku.judulBuku[i] << endl;
    cout << "\tPenulis: " << buku.penulis[i] << endl;
    cout << "\tPenerbit: " << buku.penerbit[i] << endl;
    cout << "\tTebal Buku: " << buku.tebalBuku[i] << " halaman" << endl;
    cout << "\tHarga Buku: Rp " << buku.hargaBuku[i] << endl;
  }

  return 0;
}