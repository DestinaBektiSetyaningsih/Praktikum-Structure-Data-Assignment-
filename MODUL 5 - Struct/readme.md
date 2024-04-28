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
#include <string> // dengan menggunakan std::string

// Mendefinisikan struct buku
struct buku {
    std::string judulBuku;
    std::string pengarang;
    std::string penerbit;
    int tebalHalaman;
    float hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    struct buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    std::cout << "\tBuku Favorit Saya" << std::endl;
    std::cout << "\tJudul Buku : " << favorit.judulBuku << std::endl;
    std::cout << "\tPengarang : " << favorit.pengarang << std::endl;
    std::cout << "\tPenerbit : " << favorit.penerbit << std::endl;
    std::cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << std::endl;
    std::cout << "\tHarga Buku : Rp " << favorit.hargaBuku << std::endl;

    return 0;
}
```

#### Output:


Interpretasi:
Program diatas sama seperti guided 1, yaitu bertujuan untuk menampilkan informasi buku favorit, dan program diatas menggunakan "struct buku" untuk mendefinisikan struktur data buku yang memiliki "judul, penerbit, pengarang, tebal halama, harga buku". Meskipun sama seperti guided 1, tetapi program ini memiliki kode yang berbeda dengan guided 1, seperti setiap item yang terdapat pada struct buku berupa array. Program diatas memiliki bebarapa fungsi, seperti 
- "std::cout" -> digunakan untuk menampilkan output ke layar. Lalu kenapa harus ada 'std'? karena untuk mengakseskan fungsi cout yang terdapat di beberapa namespace. begitupun dengan "std::string"
- "float" -> untuk bilangan yang memiliki bagian desimal.

### 2. [Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.]

```C++
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
```

#### Output:


Interpretasi:
Program diatas menggunakan kode array yang berisi 5 elemen dari stuktur "buku". Program diatas juga menampilkan informasi dari setiap buku dalam array "array_buku" dengan menggunakan loop "for", loop bisa digunakan untuk mengisi dan menampilkan data dari elemen array. Dengan menggunakan array tersebut kode dapat menyimpan dan mengelola informasi tentang beberapa buku dalam data yang terstruktur. 

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang struct dalam pemrograman. Struct adalah kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu variabel. Lalu mengapa struct penting dalam pemrograman? karena ketika kita ingin menyimpan sebuah data, kita membutuhkan "struct" supaya bisa menghemat memori dan mudah untuk diakses serta mudah untuk dimanipulasinya.

## Referensi
[1] Studocu. (n.d.). Modul senarai berantai - Linked List ( Senarai Berantai) Pengertian Single Linked List pada C++. - Studocu. https://www.studocu.com/id/u/46348016?sid=01714316556

[2] BUKU AJAR PEMROGRAMAN STRUKTUR DATA
By Charisma Tubagus Setyobudhi, B.Eng., M.T.
Google Books. (n.d.). https://www.google.co.id/books/edition/BUKU_AJAR_PEMROGRAMAN_STRUKTUR_DATA/LBLlEAAAQBAJ?hl=en&gbpv=1&dq=materi+linked+list&pg=PR4&printsec=frontcover