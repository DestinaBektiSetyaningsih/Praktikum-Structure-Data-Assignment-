# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Rekursif

Nah gengs kalian tau gak nih kalau dibahasa pemrograman ada Algoritma Rekursif. Algoritma ini diimplementasikan dalam sebuah fungsi yang memanggiil dirinya sendiri. Contoh rekursif = fungsi pangkat, fungsi faktorial, dan barisan fibonacci. 

Rekursif ialah suatu proses yang memanggil dirinya sendiri. Dalam rekursif sebenarnya mengandung pengertian prosedur atau fungsi, tetapi yang menjadi perbedaan kalau rekursif bisa memanggil dirinya sendiri, sedangkan prosedur harus dipanggil lewat pemanggil prosedur [1]

Gengs rekursif juga memiliki kelebihan dan kelemahan lho, apa aja sih kelebihan dan kelemahan tersebut?
> Kelebihan:
- Solusi sangatlah efisien.
- Dapat memecahkan masalah yang sulit dengan tahapan yang mudah dan singkat.

>Kelemahan:
- Sulit untuk dipahami.
- Memerlukan stack besar/overrun. [2]

Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri. Fungsi rekursif disusun atas 2 bagian, yaitu basis dan rekurens. 
- Basis -> berisi nilai awal yang tidak mengacu pada dirinya sendiri dan mendefinisikan nilai fungsi pada saat 0.
- Rekurens -> mendefinisikan argumen dalam terminologi dirinya sendiri dan memberi aturan untuk mencari nilai fungsi untuk setiap bilangan bulat berdasarkan nilai fungsi pada bilangan bulat yang lebih kecil (<). [2]

## Guided 
```C++
#include <iostream>
/// Rekursif Langsung
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n-1); ///-> n itu untuk angka awal 
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); //-> 5 adalah n
    cout << endl;
    return 0;
}
```

Interpretasi:
Program diatas adalah program "Function Rekursif Langsung", rekursif ini memanggil secara langsung tanpa melibatkan fungsi lain untuk memanggil fungsi tersebut. Tujuan program ini dibuat untuk memecah elemen/argumen tersebut menjadi lebih kecil. Selain itu tujuan lainnya supaya pengguna memahami fungsi dari materi ini. 
Cara kerjanya yaitu, dengan memanggil dirinya sendiri, seperti elemen diatas memiliki angka awal 5, kemudian memanggil angka itu sendiri tetapi berkurang gitu, jadi angka 4,dan seterusnya sampai angka itu tidak bisa dibagi lagi/habis.

Fungsi kode diatas:
- "coutdown" -> mencetak angka awal sampai angka itu habis atau 0. 

#### Output:
![Screenshot 2024-05-26 204220](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/e114fbd6-75c1-4f2e-9424-9343c3033e87)

```C++
#include <iostream>
/// Rekursif Tidak Langsung
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}
 
int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0; // untuk mengembalikan nilai tersebut
}
```

Interpretasi:
Program diatas adalah program "Function Rekursif Tidak Langsung", rekursif ini memanggil secara tidak langsung karena fungsi ini melibatkan beberapa fungsi lainnya untuk memanggil fungsi tersebut. Tujuan program ini dibuat untuk memecah elemen/argumen tersebut menjadi lebih kecil. Selain itu tujuan lainnya supaya pengguna memahami fungsi dari materi ini. 

Cara kerjanya yaitu, dengan memanggil dirinya sendiri tetapi meminta bantuan fungsi lain, seperti elemen diatas memiliki angka awal 5, kemudian memanggil angka itu sendiri tetapi berkurang gitu, jadi angka 4,dan seterusnya sampai angka itu tidak bisa dibagi lagi/habis, tetapi menggunakan fungsi lain seperti "functionA" memanggil "functionB" dengan menggunakan parameter (n-1), begitupun sebaliknya "functionB" memanggil "functionA" dengan menggunakan parameter (n/2).

#### Output:
![Screenshot 2024-05-26 204414](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/fecb9832-3943-49fd-94e7-d92a07fe5e92)

## Unguided 

### [1]. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Input tidak valid. Silakan masukkan bilangan bulat positif." << endl;
    } 
    else {
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}
```

Interpretasi:
Program diatas adalah program "Function Rekursif Langsung", rekursif ini memanggil secara langsung tanpa melibatkan fungsi lain untuk memanggil fungsi tersebut. Tujuan program ini dibuat untuk menghitung nilai faktorial dan menggabungkan bilangan positif dengan menggunakan fungsi rekursif secara langsung. Selain itu tujuan lainnya supaya pengguna memahami fungsi dari materi ini. 

Cara kerjanya yaitu, kita masukkan terlebih dahulu bilangan bulat positifnya, dan akan otomatis menghasilkan output faktorial dari 5 = 120, fungsi ini memanggil fungsi itu sendiri, seperti "int faktorial", dan untuk hasil menggunakan fungsi "int hasil" yang dimana hasil tersebut akan membentuk numeric. 

#### Output:
![Screenshot 2024-05-27 203641](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/12157e3d-5fa3-4c63-895b-aba240df4b74)

### [2]. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

using namespace std;

int functionA(int n);
int functionB(int n);

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Input tidak valid. Silakan masukkan bilangan bulat positif." << endl;
    } else {

        int hasil = functionA(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}

int functionA(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * functionB(n - 1);
    }
}

int functionB(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * functionA(n - 1);
    }
}
```

Interpretasi:
Program diatas adalah program "Function Rekursif Tidak Langsung", rekursif ini memanggil secara tidak langsung karena fungsi ini melibatkan beberapa fungsi lainnya untuk memanggil fungsi tersebut. Tujuan program ini dibuat untuk menghitung nilai faktorial dan menggabungkan bilangan positif dengan menggunakan fungsi rekursif secara tidak langsung. Selain itu tujuan lainnya supaya pengguna memahami fungsi dari materi ini. 

Cara kerjanya yaitu, kita masukkan terlebih dahulu bilangan bulat positif tersebut, maka akan keluar output dari faktorial 5 = 120, fungsi ini tidak memanggil dirinya sendiri, melainkan meminta bantuan fungsi lain. Seperti "int functionA" akan memeriksa apakah bilangan faktorial itu 0 atau lebih, jika lebih maka function A akan memanggil function B dengan menggunakan parameter (n - 1), begitupun sebaliknya apabila "int functionB" akan memeriksa apakah bilangan faktorial itu 0 atau lebih, jika lebih maka function B akan memanggil function A dengan menggunakan parameter (n - 1). 


#### Output:
![Screenshot 2024-05-27 204229](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/95e26a88-e0a8-4985-b6bf-63ba70c523d9)

## Kesimpulan :
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang "Rekursif" dalam pemrograman. Rekursi sendiri adalah kosenp pengulangan yang penting dalam ilmu komputer. Konsep ini dapat digunakan untuk merumuskan solusi sederhana dalam sebuah permasalahan yang sulit untuk diselesaikan secara iteratif dengan menggunakan loop for, while do.

Rekursif memiliki 4 tipe yaitu:
- Tail Recursion -> teknik optimisasi pada fungsi rekursif yang dimana pemanggilan rekursif pada fungsi tersebut.
- Head Recursion -> teknik implementasi fungsi rekursif yang dimana pemanggilan rekursif dilakukan pada bagian awal atau sebelum operasi lainnya dilakukan.
- Nested Recursion -> suatu fungsi yang dilakukan sebagai parameter input dari pemanggilan rekursfi pada fungsi lain.
- Tree Recursion -> fungsi ini yang dimana setiap panggilan rekursif menghasilkan beberapa panggilan rekursif lainnya.

## Referensi :
[1] STRUKTUR DATA DAN ALGORITMA DENGAN C++. (n.d.). Google Books. https://books.google.co.id/books?hl=en&lr=&id=GP_ADwAAQBAJ&oi=fnd&pg=PR7&dq=fungsi+rekursif+bahasa+c%2B%2B&ots=86f5Uu4MbV&sig=fYVQEJbnpCIjoQXGkdSYClouta8&redir_esc=y#v=onepage&q=fungsi%20rekursif%20bahasa%20c%2B%2B&f=false

[2] Modul Online
https://sisfo.itp.ac.id/bahanajar/BahanAjar/Harison/6%20rekursif%20%20induksi%20matematik.pdf

