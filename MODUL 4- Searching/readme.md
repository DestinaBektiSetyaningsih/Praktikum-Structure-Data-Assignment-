# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Algoritma Searching

Kalian pasti sudah tidak asing lagi dengan Algoritma satu ini. Yap Algoritma Searching ialah algoritma yang dipelajari secara dasar pada pelajaran komputer. 

Nah kalian tau gak nih pengertian dari algoritma searching sendiri? Algoritma Searching adalah Sekumpulan langkah atau instruksi yang digunakan untuk mencari elemen atau informasi tertentu didalam suatu dataset.

Nah Algoritma ini memiliki 2 jenis lho, kira - kira apa saja ya? 
Inilah jenis Algoritma Searching, diantaranya yaitu:
- Sequential Search (metode pencarian beruntun) -> proses membandingkan setiap elemen dalam list atau array satu per satu secara beruntun, mulai dari elemen pertama, sampai elemen terakhir (elemen yang dicarikan sudah ditemukan). 
- Binary Search -> algoritma pencarian biner yang paling efektif. Algoritma ini memanfaatkan kumpulan elemen yang telah diurutkan dengan mengabaikan setengah dari elemen, setelah dilakukan satu perbandingan.[1]

## Guided 

### 1. [sequential Search]

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
    
}
```
Output:
![Screenshot 2024-04-07 212436](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/bad1f532-1618-40fb-99f1-5f51a64b90d3)

Interpretasi :
Program diatas adalah program Sequential Search yang dimana ketika kita ingin membandingkan atau mencari sebuah indeks dalam list harus di cari satu - persatu. Program diatas ingin mencari angka "10, maka menggunakan if untuk program " cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;" , else untuk program "cout << cari << " tidak dapat ditemukan pada data." << endl;", dan cout yaitu " cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;". Misal seperti contoh di atas ketika kita ingin mencari angka 10 yang ada di indeks ke berapa?, dan ada 10 angka yang tidak berurutan, yaitu data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}, maka kita akan tahu bahwa "angka (10) ditemukan pada indeks ke-9.

### 2. [Binary Search]

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j; 
    for(i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort(data, length);

    // Tampilkan data setelah diurutkan 
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```
Output:
![Screenshot 2024-04-07 212943](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/5320e6fc-ffa8-4d7c-8317-d8afa946d4bc)

Interpretasi :
Program diatas adalah program Binary Search yang dimana algoritma ini paling efektif untuk melakukan suatu perbandingan. Dari program diatas ketika kita ingin mengurutkan sebuah data bisa menggunakan selection sort " selection_sort(data, length);" dan mencari sebuah data kita bisa menggunakan cout "cout << "\n Masukkan data yang ingin anda cari : ";". Misal seperti contoh di atas, ketika kita ingin mencari sebuah angka pada sebuah data, yaitu "Data :   1  8  2  5  4  9  7", lalu kita bisa masukkan data yang kita cari, maka otomatis data tersebut akan terurut seperti "Data diurutkan :   1  2  4  5  7  8  9" dan kita bisa tahu angka yang kita carai berada diindeks keberapa, seperti "Data ditemukan pada index ke- 3". 

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
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
```
#### Output:
![Screenshot 2024-04-08 135814](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/9ec072c0-d063-4602-8467-71936a7e4517)

Interpretasi:
Program diatas adalah program Binary Search yang dimana algoritma ini paling efektif untuk melakukan suatu perbandingan. 
Dari program diatas kita bisa mengetahui jika kita ingin mencari indeks huruf dalam kata/kalimat bisa menggunakan "findindeks". program diatas menggunakan perulangan "for" untuk mencari huruf yang ada didalam kata/kalimat. Kita juga tahu bahwa "int main()" berfungsi sebagai meminta untuk dimasukkan kata dan huruf yang ingin dicari. Misal seperti contoh di atas, ketika kita ingin mencari sebuah kata/ atau kalimat pada sebuah data, yaitu "Masukkan kata: Lauren", masukkan huruf yang ingin dicari, seperti "Masukkan huruf yang ingin dicari: r", dan akan keluar hasilnya, yaitu "Huruf 'r' ditemukan pada indeks ke-3 dalam kalimat". kesimpulan dari program diatas yaitu : Jika kita mencari huruf yang kita cari ditemukan maka fungsi akan mengembalikan indeks, sedangkan jika huruf yang kita cari tidak ditemukan maka fungsi akan dikembalikan menjadi 0.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
#include <iostream>
#include <string>

using namespace std;

int isVowel(char ch) {
    ch = tolower(ch); 
    return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

int countVowels(const string& sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-08 135530](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/e5a20c4c-0ba6-449a-ac51-cad2e562551e)

Interpretasi: 
Program diatas adalah program Binary Search yang dimana algoritma ini paling efektif untuk melakukan suatu perbandingan. Dari program diatas kita bisa mengetahui jika kita ingin mengecek apakah huruf tersebut vokal atau tidak, kita menggunakan fungsi "int isVowel(char ch)" -> (disclaimer: saya udah mencoba menggunakan integer dan boolean, ternyata hasilnya sama). Lalu ketika kita ingin mengubah huruf menjadi kecil, kita bisa menggunakan fungsi "ch = tolower(ch);". Kita juga bisa mengetahui bahwa ketika kita ingin menghitung jumlah huruf vokal dalam suatu kalimat, bisa menggunakan fungsi "int countVowels(const string& sentence)".  Misal seperti contoh di atas, ketika kita ingin mencari sebuah huruf vokal dalam satu kalimat, yaitu "Masukkan kalimat: james", dan akan keluar hasilnya, yaitu "Jumlah huruf vokal dalam kalimat tersebut adalah: 2". Kesimpulan dari program diatas, yaitu: jika fungsi tersebut sedang melakukan pengujian apakah huruf tersebut vokal atau tidak, jika huruf tersebut vokal maka fungsi akan dikembalikan ke nilai 1, sedangkan jika huruf tersebut bukan huruf vokal, maka akan dikembalikan ke nilai 0.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
#include <iostream>
#include <vector>

using namespace std;

int countFours(const vector<int>& data) {
    int count = 0;
    for (int num : data) {
        if (num == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

    int jumlahEmpat = countFours(data);

    cout << "Jumlah angka 4 dalam data adalah: " << jumlahEmpat << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-08 141917](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/93e9774b-21fc-4443-ba7f-f575e2f695b6)

Interpretasi:
Program diatas adalah program Sequential Search yang dimana ketika kita ingin membandingkan atau mencari sebuah indeks dalam list harus di cari satu - persatu. Ketika kita ingin menghitung jumlah angka dalam suatu data, bisa menggunakan fungsi "int countFours(const vector<int>& data)". Misal seperti contoh di atas, ketika kita ingin menghitung sebuah angka dalam suatu data, yaitu "data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4." dan akan keluar hasilnya, yaitu "Jumlah angka 4 dalam data adalah: 4". Maka kesimpulannya adalah: jika angka tersebut benar, maka fungsi akan menambah nilai 1 ke variabelnnya dengan menggunakan fungsi "count".

## Kesimpulan
Laporan ini disusun dengan tujuan supaya para pembaca bisa mengerti dan memahami konsep dari Algoritma Searching, seperti pengertiannya, jenis - jenisnya, hingga cara menjalankannya. Pemrograman Searching sendiri ialah -> metode pencarian data dengan membandingkan setiap elemen larik satu persatu secara urut, mulai dari elemen pertama sampai dengan elemen terakhir. 
Menurut buku yang saya baca ada 2 macam pencarian berurutan, yaitu:
- pencarian pada array yang sudah terurut -> Sequential Search (pencarian yang dilakukan dengan berurutan).
- pencarian pada array yang belum terurut -> Binary Search (pencarian yang dilakukan dengan bagi dua). [2]

## Referensi
[1] BUKU AJAR ALGORITMA PEMROGRAMAN
By M. N. Fakhruzzaman, Ika Qutsiati Utami, Purbandini
Google Books. (n.d.). https://www.google.co.id/books/edition/BUKU_AJAR_ALGORITMA_PEMROGRAMAN/4aC9EAAAQBAJ?hl=en&gbpv=1&dq=algoritma+searching&pg=PA41&printsec=frontcover

[2] Dasar-Dasar Pemrograman
By Shinta Esabella, Miftahul Haq (cetak pertama), Mei 2021
Google Books. (n.d.-b). https://www.google.co.id/books/edition/Dasar_Dasar_Pemrograman/itUvEAAAQBAJ?hl=en&gbpv=1&dq=algoritma+searching&pg=PA100&printsec=frontcover
