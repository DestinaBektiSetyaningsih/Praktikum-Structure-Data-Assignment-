# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Nah gengs kita masih nyambung lagi di materi struktur data dengan judul "stack". Bagi kalian yang masih terdengarr asing, materi ini masih berhubungan dengan string, array, dsb...
Lalu apa itu stack?

Menurut buku yang saya baca, Stack diterjemahkan menjadi tumpukan yang berfungsi untuk menyimpan data sedemikian hingga item terakhir yang disisipkan adalah item pertama dan juga untuk mengimplementasikan protokol "last-in-fist-out" (LIFO). [2]

Secara bahasa,stack adalah sebuah struktur datalinear yang dimana item baru ditambahkan dan diambil dari ujung yang sama, yaitu puncak tumpukan (top of the stack).

secara umum,stack adalah sebuah struktur data yang menyimpan koleksi linear yang mempunyai akses terbatas pada uruan terakhir-masuk-keluar-pertama, lalu menambahkan dan mengambil item yang dibatasi pada satu ujung saja seperti, puncak tumpukan (top of the stack), dan stack kosong (emptykosong), stack kosong ialah stack yang tidak mempunyai item. [1]

> Operasi - operasi stack:
- stack -> untuk membuat stack baru yang kosong.

- isEmpty -> mengembalikan nilai boolean yang menunjukkan apakah stack itu kosong.

- Length -> mengembalikan banyaknya item didalam stack. 

- Pop -> mengembalikan nilai item yang paling atas dan menghapusnya bila stacknya tidak kosong.

- Peek -> mengembalikan nilai dari item 
yang paling atas, tanpa menghapusnya.
- Push (item) -> menambahkan item ke puncak stack.

- isFull -> untuk mengecek apakah stack sudah penuh?.

- Clear -> untuk mengosongkan stack. [2]

## Guided 

```C++
#include <iostream>
using namespace std;

/// setiap stack ada fungsinya
// pop -> untuk menghapus data bagian atas
// countstack -> untuk menilai angka

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```
#### Output:
![Screenshot 2024-05-06 094758](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/f52c34c6-b92d-4660-bc70-82c93db01978)

#### Screenshoot Full:
![Screenshot 2024-05-06 094817](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/cae8469f-a2b7-4841-bb45-c1c76483b445)

Interpretasi:
Dari program diatas kita bisa menyimpulkan bahwa ketika kita ingin menyimpan sebuah data, kita bisa menggunakan kode "stack". 

Program diatas juga dapatb yaitu menyimpan data judul - judul matkul. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "stack" yaitu, bisa menyimpan data, tidak hanya itu ,tetapi juga bisa untuk menambahkan data, dan menghapus data pada posisi akhir pada stack. 

Cara kerjanya yaitu, pengguna memasukkan judul - judul buku seperti "Kalkulus", "Struktur Data", "Matematika Diskrit", dsb.. Selain itu program ini mempunyai beberapa kode yang memiliki fungsinya masing - masing seperti:
- Fungsi Utama "main" -> untuk menambah, mengubah, menghapus pada stack.
- Fungsi "isFull" -> untuk mengecek apakah data stack penuh atau tidak.
- Fungsi "isEmpty" -> untuk mengecek apakah data stack kosong atau tidak.
- Fungsi "pushArray" -> untuk menambahkan dan memasukan judul buku ke stack.
- Fungsi "destroyArray" -> untuk menghapus semua buku yang ada didalam stack.
- Fungsi "countstack" -> Untuk mengembalikan jumlah buku ke dalam stack.


## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya..]

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& sentence) {
    std::stack<char> charStack;
    std::string str = sentence;

    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (char c : str) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        if (charStack.top() != str.back()) {
            return false;
        }
        charStack.pop();
        str.pop_back();
    }

    return true;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

if (isPalindrome(kalimat)) {
    std::cout << "Kalimat tersebut adalah polindrom" << std::endl;
} else {
    std::cout << "Kalimat tersebut bukan polindrom" << std::endl;
}
return 0;
}
```
#### Output:
![Screenshot 2024-05-06 093948](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/e73e6ca8-1beb-401f-aafb-4e881c2b8213)

#### Screenshoot Full:
![Screenshot 2024-05-06 094010](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/2dc7c6ef-e5eb-4708-bc1f-5bc9a4e3461a)

Interpretasi:
Program diatas yaitu untuk memasukkan kalimat, lalu hasil dari kalimat itu akan membentuk kalimat polindrom.Apa itu polindrom? Polindrom adalah kalimat yang memiliki sifat bahwa kalimat tersebut sama ketika dibaca dari awal hingga akhir, dan dari akhir ke awal, seperti bolak-balik aja. Lalu tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "stack" yaitu untuk membantu mengelola operasi pada LIFO dan bisa untuk mengontrol memori yang dimana memori tersebut bisa dialokasikan dan tidak dialokasikan. 
Cara kerja program ini yaitu, sebelum itu note! bahwa setiap bagian "stack" memiliki fungsinya masing - masing. Lanjut cara kerjanya yaitu, kita membuat "bool isPalindrome" tujuannya untuk mengambil string lalu menginputnya, setelah itu kita inisialisasi stack kosong dengan kode "charStack;", setelah itu kita hapus spasi dengan kode "std::transform" dan "::tolower;", setelah itu ulangi setiap karakter yang ada didalam string lalu kita menyimpan karakter dengan kode "charStack.push(c);", setelah itu membandingkan karakter dengan karakter aslinya menggunakan loop yang terus berjalan sehingga stack menjadi kosong "while (!charStack.empty())" dan "charStack.pop();", setelah itu kita cek kalimat polindrom apakah kosong atau tidak dengan menggunakan kode "std::cout", jika kalimat tersebut polindrom maka akan bernilai (true) dan jika bukan kalimat polindrom akan bernilai (false).

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseSentence(string sentence) {
    stack<char> characters;
    for (char c : sentence) {
        characters.push(c);
    }

    while (!characters.empty()) {
        cout << characters.top();
        characters.pop();
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Kalimat: " << kalimat << endl;

    cout << "Hasil: ";
    reverseSentence(kalimat);

    return 0;
}
```
#### Output:
![Screenshot 2024-05-06 084422](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/b9a191a1-405a-4371-8aaf-942b6d0ab80a)

#### Screenshoot Full:
![Screenshot 2024-05-06 084438](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/4e4b2249-b794-49ba-bada-738007908af8)

Interpretasi:
Program diatas yaitu untuk memasukkan kalimat, lalu hasil dari kalimat itu akan membentuk kalimat terbalik. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "stack" yaitu untuk membantu mengelola operasi pada LIFO. Contoh cara kerjanya yaitu ketika ada wadah kosong, lalu kita isi dengan item A,B, dan C, nah jadi ketika kita mengisi/memasukkan item itu disebutnya (push), lalu ketika kita ingin mengambil item C, kan otomatis item C ada diatas yaa, nah kita ambil itu baru disebut (pop).
Fungsi kode dari program diatas:
- Fungsi "reversesentence" -> untuk mengambil sebuah string lalu menginputnya.
- Fungsi "getline" -> untuk membaca baris tesks dari inputnya dan menyimpan dalam sebuah string.
- Fungsi "cout" -> untuk mencetak karakkter (kalimat).
- Fungsi "main" -> untuk memasukkan kalimat dan menyimpannya.

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang stack dalam pemrograman. Stack ialah struktur data dengan sebagai tumpukan data yang mengikuti LIFO. Stack juga memiliki kegunaan yang berbeda - beda seperti, 
- manajemen data efisien.
- manajemen fungsi efisien.
- untuk mengontrol memori.
- manajemen memori cerdas.
- manajemen tumpukan data.
- dsb...

Stack juga ada kelebihannya seperti,
- tidak mudah rusak.
- memiliki fungsi yang sistematis.
- tidak mudah mengizinkan perubahan ukuruan variabel dengan mudahnya.
- mengimplementasi algoritma. 

## Referensi
[1]Modul Praktikum Algoritma & Struktur Data Versi 4.3
By Fajar Suryawan, Husni Thamrin, Dimas Aryo Anggoro, Wiwit Supriyanti, Yunita Ardiyanto 
Google Books. (n.d.). https://www.google.co.id/books/edition/Modul_Praktikum_Algoritma_Struktur_Data/_SlHEAAAQBAJ?hl=en&gbpv=1&dq=algoritma+stack&pg=PA76&printsec=frontcoversy

[2]Buku Ajar Algoritma dan Struktur Data
By Muhammad Benny Chaniago, Cecep Kurnia Sastradipraja
Google Books. (n.d.-b). https://www.google.co.id/books/edition/Buku_Ajar_Algoritma_dan_Struktur_Data/3PKxEAAAQBAJ?hl=en&gbpv=1&dq=algoritma+stack&pg=PA203&printsec=frontcover
