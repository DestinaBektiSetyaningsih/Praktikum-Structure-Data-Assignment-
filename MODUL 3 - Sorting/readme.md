# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
ALGORITMA PENGURUTAN (SORTING)

Algoritma adalah sekumpulan tahap sistematis dan beurutan untuk memberikan hasil yang diharapkan, sedangkan Sorting adalah proses pengurutan beberapa data dengan mengacu nilai kunci tertentu sebagai perbandingan yang selanjutnya akan dipusukan apakah bertukar posisi atau tidak. [1]

Algoritma Sorting telah dikenal sejak pertengahan abad ke-20. Algoritma ini ditemukan dengan Timsort yang banyak digunakan, yang berasal dari tahun 2002, dan perpustakaan pertama kali diterbitkan pada tahun 2006. 

Algoritma Sorting memberikan solusi dari banyak masalah yang terjadi pada dunia pengembangan teknologi. Nah Algoritma Sorting juga ada jenis - jenis lho! apa aja sih jenis - jenis tersebut?

> Jenis-jenis Algoritma Sorting:
A.) Bubble Sort -> algoritma sorting sederhana yang mempunyai skema proses dengan menukar elemen/anggota yang berdekatan secara berulang setelah dilakukan perbandingan yang hasil urutannya tidak sesuai. 

Algoritma ini tidak cocok untuk kumpulan data besar karena kompleksitas waktu rata-rata dan kasus terburuknya cukup tinggi.

B.) Selection Sort -> algoritma sorting  yang belum terurut dan menggantikan elemen tersebut dengan elemen diposisi yang tepat dalam list. 

Algoritma ini memiliki kompleksitas waktu rata-rata dan paling buruk, hal ini menunjukkan bahwa algoritma ini tidak cocok untuk sort list yang besar, dan lebih efisien untuk pengurutan list kecil.

C.) Insertion Sort -> algoritma sorting  yang mengurutkan elemen dengan menysipkan setiap elemen ke posisi yang tepat dalam array yang sudah terurut. 

Algoritma ini tidak cocok untuk kumpulan array besar dan lebih efisien untuk array kecil, oleh karena itu kompleksitas waktu rata-rata dan paling buruk. [1]


## Guided 

### 1. [Bubble Sort]
Mengurutkan secara ascending untuk data numerik bertipe double menggunakan
Algoritma Bubble Sort.

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutkan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutkan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Output:
![Screenshot 2024-04-01 133100](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/8ea3f24f-e978-4dba-9edb-32a5790f3e69)

Interpretasi: 
Dari data diatas ada 5 bilangan yang tidak terurut yaitu 22.1, 15.3, 8.2, 33.21, 99.
Karena data tersebut sederhana jadi kita urutkan menggunakan Algoritma Bubble Sort, dan data tersebut menjadi terurut. Data setalah diurutkan yaitu 8.2, 15.3, 22.1, 33.21, 99. 

### 2. [Insertion Sort]
Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort.

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; 1 < length; i++) {
        j = i;

        while (j > 0 && arr[j - i] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting:" << endl;
    print_array(a, length);

    cout << "\nUrutan karakter setelah sorting:" << endl;
    print_array(a, length);
}
```
Output:
![Screenshot 2024-04-01 132826](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/0ef33875-8cef-44bf-9af7-77cd84a7a40c)

Interpretasi:
Dari data diatas kita bisa  mengetahui urutan sebelum dan sesudah sorting. Jika ingin menggunakan fungsi Insertion Sort, maka menerima 2 parameter yaitu "array" dan "length".  

## Unguided 

### 1. [Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!]

```C++
#include <stdio.h>
using namespace std;

void selection_sort(float arr[], int x) {
  for (int y = 0; y < x-1; y++) {
    int maxIndex = y;
    for (int n = y+1; y < x; y++) {
      if (arr[y] > arr[maxIndex]) {
        maxIndex = y;
      }
    }
    if (maxIndex != y) {
      float temp = arr[y];
      arr[y] = arr[maxIndex];
      arr[maxIndex] = temp;
    }
  }
}

void cetak_array(float a[], int length) {
  for(int y=0; y<length; y++) {
    printf("%.1f    ", a[y]);
  }
  printf("\n");
}

int main() {
  // Mengurutkan Nilai Mahasiswa IPS
  float arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Nilai Mahasiswa IPS sebelum diurutkan: ");
  cetak_array(arr, n);
  selection_sort(arr, n);
  printf("Nilai Mahasiswa IPS setelah diurutkan: ");
  cetak_array(arr, n);
  return 0;
}
```

#### Output:
![Screenshot 2024-04-01 132946](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/25fa2170-107a-447d-b1ea-da7b6c305292)

Interpretasi:
Dari kodingan di atas kita bisa tau Nilai Mahasiswa IPS sebelum dan setelah diurutkan. Fungsi Selection Sort pada kodingan diatas menerima 2 parameter, yaitu "array" dan "int x" (void selection_sort(float arr[], int x). Fungsi "void" -> untuk parameter yang bersifat opsional, biasanya fungsi ini tidak mengambil parameter dan juga tidak menerima input. Dan untuk mengurutkan nilai mahasiswa ips, menggunakan fungsi "float arr". Nah Fungsi float -> menentukan sebuah nilai itu float atau double. 

### 2. [Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!]

```C++
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string nama[], int x) {
    for(int y = 0; y < x-1; y++) {
        for(int z = 0; z < x-y-1; z++) {
            if(nama[z] > nama[z+1]) {
                swap(nama[z], nama[z+1]);
            }
        }
    }
}

int main() {
    string nama[] = {"Siti", "Situ", "Sana", "Ana", "Ani", "Caca", "Cici", "Dida", "Dodo", "Dadi"};
    int x = sizeof(nama)/sizeof(nama[0]);

    bubbleSort(nama, x);

    cout << "10 Nama warga Pak RT setelah diurutkan: ";
    for(int y = 0; y < x; y++) {
        cout << nama[y] << " ";
    }
    cout << endl;

    return 0;
}
```

#### Output:
![Screenshot 2024-04-01 133013](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/2dd03ba5-c384-49f6-9349-f68abadf9fd1)

Interpretasi:
Dari kodingan di atas kita bisa tau 10 Naa Warga Pak RT. Program ini mengguakan algoritma Bubble Sort untuk menurutkan nama dalam Ascending dan Descending (void bubbleSort(string nama[], int x)). Setelah mengurutkan kita masukkan menggunakan "integer" dan "string" untuk memasukkan nama. Lalu kita print dengan menggunakan ( cout << "10 Nama warga Pak RT setelah diurutkan: ";).

### 3. [Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!]

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int x;
  cout << "Masukkan jumlah karakter: ";
  cin >> x;

  char karakter[x];

  for (int y = 0; y < x; y++) {
    cout << "Karakter ke-" << y + 1 << ": ";
    cin >> karakter[y];
  }

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
```

#### Output:
![Screenshot 2024-04-01 133100](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/31a047a1-5680-476f-b3cf-d33f095741cb)

Interpretasi:
Dari kodingan diatas kita bisa mengetahui urutan karakter sebelum sorting dengan merubah menjadi Ascending dan Descending. Kenapa kita menggunakan fungsi (cin >> x;)? karena ketika kita  ingin mendapatkan jumlah karakter dari user, fungsi "cin" -> untuk membaca input dari user. Kemudian meminta user untuk masukan satu persatu karakter dengan menggunakan (cout << "Karakter ke-" << y + 1 << ":), lalu kita Menampilkan urutan karakter sebelum sorting (cout << "Urutan karakter sebelum sorting:" << endl;), selanjutnya membuat urutan Ascending dan Descending. 

## Kesimpulan
Laporan ini dibuat supaya kita paham bahwa Algoritma Sorting perbandingan memiliki persyaratan dasar, yaitu perbandingan (n log n) beberapa urutan masukan akan memerlukan kelipatan n log n perbandingan, yang dimana n adalah jumlah elemen dalam array yang akan diurutkan. Algoritma yang tidak berdasarkan perbandingan, seperti menghitung sortir, dapat memiliki kinerja yang lebih baik. [1]

Algoritma Sorting ada 3 macam, yaitu:
- Bubble Sort, kenapa diberi nama Bubble Sort? karena bisa melakukan pengurutan tiap elemen cenderung untuk naik ke atas sampai ke urutan yang sesuai.

Metode Bubble Sort -> dengan cara membandingkan tiap elemen dengan elemen berikutnya, dan melakukan penukaran tempat jika urutannya tidak sesuai. [2]

- Metode Insertion Sort -> pengurutan data dengan cara memilih elemen sebagai kunci (posisi nomor dua), kemudian dibandingkan dengan elemen pada posisi sebelumnya. Jika elemen kunci lebih kecil / lebih besar maka elemen kunci disisipkan. [2]

- Metode Selection Sort -> pengurutan data dalam urutan naik, turun atau yang ditentukan pengguna. Algoritma ini mencari nilai data terkecil dimulai dari posisi 0 hingga posisi N-1, dan jika  terdapat N data dan data terkoleksi dari urutan 0 - N-1. 

Pada laporan ini disusun supaya para pembaca memahami konsep dasar sorting. Sorting adalah proses dasar pada sebuah algoritma dan struktur data, proses dimana menyusun kembali suatu himpunan obyek dengan aturan tertentu. Tujuan Sorting untuk memudahkan pencarian dalam suatu himpunan yang dilakukan berulang.

Secara umum ada 2 jenis pengurutan:
- Pengurutan Menaik (Ascending) = pengurutan data yang dimulai dari nilai terkecil ke nilai terbesar.
- Pengurutan Menurun (Descending) = pengurutan data yang dimulai dari nilai terbesar ke nilai terkecil. [2]

## Referensi
[1] Konsep Algoritma dan Pemrograman : Mengenal Konsep Dasar dan Praktis dalam Bahasa Pascal dan C
By Yeyi Gusla Nengsih, S. Tahun 2022

Google Books. (n.d.). https://www.google.co.id/books/edition/Konsep_Algoritma_dan_Pemrograman_Mengena/7Vd-EAAAQBAJ?hl=en&gbpv=1&dq=sorting+algoritma&pg=PA107&printsec=frontcover

[2]BUKU AJAR PEMROGRAMAN
By Irmawati Irmawati, S.Kom., MMSI. Tahun 2023

Google Books. (n.d.-b). https://www.google.co.id/books/edition/BUKU_AJAR_PEMROGRAMAN/trzlEAAAQBAJ?hl=en&gbpv=1&dq=Algoritma+Sorting&pg=PA85&printsec=frontcover


