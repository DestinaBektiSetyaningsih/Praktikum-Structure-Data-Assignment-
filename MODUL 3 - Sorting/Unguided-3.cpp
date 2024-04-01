#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // Mendapatkan jumlah karakter dari user
  int x;
  cout << "Masukkan jumlah karakter: ";
  cin >> x;

  // Membuat array untuk menyimpan karakter
  char karakter[x];

  // Meminta user untuk memasukkan karakter satu per satu
  for (int y = 0; y < x; y++) {
    cout << "Karakter ke-" << y + 1 << ": ";
    cin >> karakter[y];
  }

  // Menampilkan urutan karakter sebelum sorting
  cout << "Urutan karakter sebelum sorting:" << endl;
  for (int y = 0; y < x; y++) {
    cout << karakter[y];
  }
  cout << endl;

  // Melakukan sorting karakter secara ascending
  sort(karakter, karakter + x);

  // Menampilkan urutan karakter setelah ascending sort
  cout << "Urutan karakter setelah ascending sort:" << endl;
  for (int y = 0; y < x; y++) {
    cout << karakter[y];
  }
  cout << endl;

  // Melakukan sorting karakter secara descending
  reverse(karakter, karakter + x);

  // Menampilkan urutan karakter setelah descending sort
  cout << "Urutan karakter setelah descending sort:" << endl;
  for (int y = 0; y < x; y++) {
    cout << karakter[y];
  }
  cout << endl;

  return 0;
}