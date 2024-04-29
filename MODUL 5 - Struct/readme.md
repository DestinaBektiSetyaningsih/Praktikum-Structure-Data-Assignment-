# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Struct

Kalian pasti sudah tidak asing lagi dengan materi ini. Yeah struct masih dalam bagian tipe data primitif, lalu apa itu struct?

Menurut buku yang saya baca:
Struct digunakan untuk mendeklarasikan tipe data yang merupakan kumpulan dari sejumlah tipe data primitif/tipe data kompleks lainnya serta memberinya nama sebagai pengenal tipe data. Secara fisik, struct disimpan dalam lokasi memori yang berurutan. [1]

Dalam bahasa indonesia tipe structure (struct) yang dikenal dengan istilah struktur. Sesuai dengan namanya, struct adalah tipe data bentukan yang menyimpan lebih dari satu variabel bertipe sama maupun berbeda. 

Oleh karena itu , dapat dianalogikan bahwa struct merupakan sebuah "pembungkus" dari beberapa tipe data yang dibei nama sesuai keinginan. 
Variabel/data elemen yang disebut juga sebagai "variabel/data member" ini dapat memiliki tipe data dan panjang data yang berbeda. Maka dari itu struct dapat digunakan untuk mengelompokkan beberapa data dengan tipe data berbeda dalam sebuah tipe data baru. [2]

## Guided 

```C++
### 1. Tipe Data Struct

#include <iostream>

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
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
#### Output:
![Screenshot 2024-04-27 232708](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/450da7a2-66d5-4bde-b95a-13925e66e98a)

#### Screenshoot Full :
![Screenshot 2024-04-27 232721](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/f43ab9c8-c54d-4849-b01d-4e843ed1ec66)

Interpretasikan:
Program diatas bertujuan untuk menampilkan informasi buku favorit, dan program diatas menggunakan "struct buku" untuk mendefinisikan struktur data buku yang memiliki "judul, penerbit, pengarang, tebal halama, harga buku"


```C++
### 2. Tipe Data Struct
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-27 234928](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/f1dc5bc8-86a7-4e88-ab6e-320dcc6dc95b)

#### Screenshoot full:
![Screenshot 2024-04-27 234946](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/a79b52d6-6f2f-4de7-8488-549be67c13d0)

Interpretasi:
Program diatas bertujuan supaya bisa mengetahui cara berkembang biak, cara bernafas, dan tempat hidup hewan darat maupun hewan laut.  

Fungsi kode - kode diatas:
- "cout" -> untuk menampilkan outputnya.
- "bool" -> untuk membuat keputusan dalam program tersebut dengan bernilai 'true' atau 'false'.
- "string" -> untuk sekumpulan karakter, supaya mudah diakses dan diedit.
- "struct" -> untuk membuat tipe data bentukan yang bisa dikelompokkan dengan beberapa variabel yang terkait dalam satu tempat.

## Guided 

### 1. [Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.]

```C++
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
```

#### Output:
![Screenshot 2024-04-29 090149](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/7276fa4e-2756-4915-a7ee-01209b480642)

#### Screenshoot Full:
![Screenshot 2024-04-29 090216](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/4ac5169b-c43c-40e6-8852-bde8c8c6944c)

Interpretasi:
Program diatas menampilkan beberapa daftar buku yang sudah dimasukkan kedalam kode tersebut. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "struct" yaitu, bisa menyimpan banyak data tanpa memakan banyak waktu dan memori. Program ini mempunyai beberapa fungsi kode dari setiap kodenya masing - masing, seperti:
- Mengisi data buku ke dalam bentuk array dengan variabel "buku".
- Menggunakan Loop "for" ->> untuk mengulangi proses output pada daftar buku tersebut sebanyak 5 kali, dan sesuai dengan apa yang kita inputkan.

### 2. [Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.]

```C++
#include <iostream>
#include <string>
using namespace std;

const int jumlah_buku = 5;

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
```

#### Output:
![Screenshot 2024-04-29 090819](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/f7d71b20-7fe2-4297-9770-5d41ba4ae177)

#### Screenshoot Full:
![Screenshot 2024-04-29 090840](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/119320a0-428a-4c80-9fc1-0d28add2df4e)

Interpretasi:
Program diatas yaitu memasukkan data - data buku supaya menjadi daftar buku. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "struct" yaitu, bisa menyimpan banyak data tanpa memakan banyak waktu dan memori. Cara kerjanya yaitu, pengguna memasukkan daftar buku seperti "judul buku", "penulis", "penerbit", "tebal buku", dan "harga buku" sebanyak 5 kali. Selain itu program ini mempunyai beberapa kode yang memiliki fungsinya masing - masing seperti:
- Fungsi Utama "main" -> untuk titik masuk program, program ini membuat sebuah instance dari struct "Buku", yaitu "daftar_buku" untuk dapat menyimpan informasi tentang buku - buku tersebut.
- Loop Input cara ini bertujuan supaya pengguna memasukkan beberapa data dengan menggunakan fungsi "getline" -> untuk membaca "judul buku" "penulis" "penerbit"  intinya yang berbasis character, selain itu juga Loop ini menggunakan fungsi "cin" -> untuk membaca "tebal buku" "harga buku" intinya yang berbasis integer.
- Loop Output cara ini bertujuan untuk menampilkan informasi data - data buku tersebut yang telah dimasukkan.
- Return -> untuk menandakan bahwa program sudah berakhir dan mengembalikkan ke 0, serta ditandai dengan eksekusi yang sukses.

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang struct dalam pemrograman. Struct adalah kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu variabel. Lalu mengapa struct penting dalam pemrograman? karena ketika kita ingin menyimpan sebuah data, kita membutuhkan "struct" supaya bisa menghemat memori dan mudah untuk diakses serta mudah untuk dimanipulasinya. Struct sendiri juga memiliki kemmiripan dengan array, bedanya struct bisa menampung lebih dari 1 jenis tipe data tersebut. Tipe data struct cocok dipakai untuk menampung data yang berkelompok, misalnya membuat biodata mahasiswa, biodata nama - nama universitas, dsb...

## Referensi
[1] Studocu. (n.d.). Modul senarai berantai - Linked List ( Senarai Berantai) Pengertian Single Linked List pada C++. - Studocu. https://www.studocu.com/id/u/46348016?sid=01714316556

[2] BUKU AJAR PEMROGRAMAN STRUKTUR DATA
By Charisma Tubagus Setyobudhi, B.Eng., M.T.
Google Books. (n.d.). https://www.google.co.id/books/edition/BUKU_AJAR_PEMROGRAMAN_STRUKTUR_DATA/LBLlEAAAQBAJ?hl=en&gbpv=1&dq=materi+linked+list&pg=PR4&printsec=frontcover