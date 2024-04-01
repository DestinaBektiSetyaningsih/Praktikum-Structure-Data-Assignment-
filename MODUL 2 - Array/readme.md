# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018)</p>

## Dasar Teori

Dalam Bahasa Pemrograman sering kali kita tidak asing dengan kata "Array", nah Array itu apasih? 

Menurut buku yang saya dapatkan, Array sering disebut sebagai Larik. Array merupakan konsep struktur data paling dasar dalam pemrograman yang dimana suatu variabel mampu menyimpan lebih dari satu nilai. 
Nah jadi jika kamu ingin mempelajari bahasa pemrograman, pasti bertemu dengan materi array. Lalu penjelasan array yang lengkap yaitu Array adalah kumpulan dari nilai - nilai bertipe data sama dalam urutan tertentu yang menggunakan sebuah nama yang sama. Nilai - nilai data yang ada di array disebut elemen - elemen array yang ditunjukkan oleh suatu indeks.

Array harus dideklarasikan sebelum dapat digunakan. Array hanya mampu menyimpan beberapa nilai yang hanya sejenis tipe datanya, tidak boleh campur tipe data yang berbeda ke dalam satu jenis array tertentu.
Contoh:
a. array integer value -> hanya dapat menyimpan nilai - nilai integer saja.
b. array long value -> hanya dapat menyimpan nilai - nilai long saja.
c. dsb...[2]

.> Jenis - jenis Array :
a. array berdimensi satu (one dimensional array) dapat mewakili 1 bentuk vektor.
b. array berdimensi dua (two dimensional array) dapat mewakili bentuk dari suatu matriks.
c. array berdimensi tiga (three dimensioanl array) dapat mewakili bentuk suatu ruang. [1]

*Pembahasan : 
a. Array Satu Dimensi = kumpulan elemen - elemen indetik yang tersusun dalam satu baris. Elemen tersebut memiliki tipe data yang sama, tetapi isi dari elemen tersebut boleh berbeda.

b. Array Dua Dimensi = kumpulan elemen yang terdiri dari beberapa baris dan beberapa kolom, bisa juga berbentuk matriks yang bertipe sama.

c. Array Tiga Dimensi = kumpulan elemen yang terdiri dari beberapa ruang.

Penggunaan array tetap sama caranya, namun ada perbedaan yang terletak pada jumlah indeksnya saja. [3]



## Guided 

```C++
### 1. [Array Tiga Dimensi]

#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi Array
    int arr[2][3][3];
    // Input elemen
    for (int x= 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array [" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x <<"]["<< y <<"][" << z <<"] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Output:
![Screenshot 2024-03-24 095251](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/2a7c9f2f-7de8-476f-a970-a864394d0879)

Dari hasil output diatas kita bisa menyimpulkan bahwa ketika kita ingin memasukkan sebuah angka pada array, kita harus memasukkan sebanyak 17 kali dan otomatis data array juga menginput 17 elemen data. Input array dan Data array bertujuan untuk mengatur nilai dalam sebuah array program 3 dimensi. 

```C++
### 2. [Array Nilai Maksimal]

#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan Panjang Array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan" << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai Mkasimum adalah " << maks << "berada di array ke-" << lokasi << endl;
}
```
Output:
![Screenshot 2024-03-24 105352](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/2315a4cc-265c-4a75-85ea-1e8c18cb4a82)


Dari output di atas kita bisa menyimpulkan bahwa ketika kita ingin mencari panjang array kita harus masukkan dulu angka dasarnya, lalu kita cari sampai ke indeks yang ditemukan. dan Nilai Maksimum adalah 12 dan berada di indeks ke 11.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Masukkan nilai array: ";
    cin >> a;
    int arr[a];

    cout << "Masukkan " << a << " angka\n";
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke - " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;

    cout << "Data Array : ";
    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor Genap : ";
    for (int i = 0; i < a; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < a; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << ", ";
        }
    }
}

```

#### Output:
![Screenshot 2024-03-25 125443](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/6e29518d-1d07-412c-aaee-d865a48fba0b)

#### Full code Screenshot:
![Screenshot 2024-03-25 125602](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/1e83c22c-8099-4c59-80de-fb4234fa2746)

Interpretasi:
Pertama kita mendeklarasikan variabel terlebih dahulu,lalu kita meminta pengguna untuk memasukkan jumlah array. Setelah itu kita input array dengan "cout << "Masukkan " << a << " angka\n";". Lalu setelah input dan output array kita masukkan nomor genap dan ganjil dengan menggunakan fungsi "cout". Program ini digunakan untuk mencari nilai array yang dipadukan dengan nomor genap dan juga nomor ganjil. 

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Masukkan Nilai A : ";
    cin >> a;
    cout << "Masukkan Nilai B : ";
    cin >> b;
    cout << "Masukkan Nilai C : ";
    cin >> c;

    cout << endl;
    int arr[a][b][c];

    for (int x = 0; x < a; x++)
    {
        for (int y = 0; y < b; y++)
        {
            for (int z = 0; z < c; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[a][b][c];
            }
        }
        cout << endl;
    }

    for (int x = 0; a < x; x++)
    {
        for (int y = b; y < y; y++)
        {
            for (int z = 0; c < z; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[a][b][c] << endl;
            }
        }
    }
    cout << endl;

    for (int x = 0; a < x; x++)
    {
        for (int y = 0; b < y; y++)
        {
            for (int z = 0; c < z; z++)
            {
                // Cetak elemen array
                cout << arr[a][b][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

```

#### Output:
![Screenshot 2024-03-25 125934](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/eca60ec6-4902-4735-8dde-b5100b86748f)

#### Full code Screenshot:
![Screenshot 2024-03-25 125946](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/544711d1-8b8f-43d1-a923-00e20aa40221)

Interpretasi:
Pertama kita mendeklarasikan variabel terlebih dahulu, cara ini supaya mudah menyimpan Nilai - Nilai yang ada di data tersebut. Lalu meminta pengguna untuk masukkan nilai A, nilai B, dan nilai C, lalu deklarasikan lagi array tiga dimensi dengan ukuran sesuai input pengguna. Setelah itu buatlah perulangan untuk input elemen array, biasanya pengguna diminta untuk memasukkan nilai untuk setiap elemen array. Setelah Langkah - Langkah tersebut akan menghasilakn output seperti diatas, lalu kita masukkan Nilai A, Nilai B, Nilai c, Nilai Input Array.

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
using namespace std;

int main()
{
    int a, i, maks, min, lokasi_maks, lokasi_min, total = 0, op;

    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];

    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << i << ": ";
        cin >> array[i];
        total += array[i];
    }

    // Inisialisasi variabel `maks` dan `min` dengan nilai elemen array pertama
    maks = min = array[0];
    lokasi_maks = lokasi_min = 0;

    // perulangan untuk mencari nilai maksimum dan minimum
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi_maks = i;
        }
        else if (array[i] < min)
        {
            min = array[i];
            lokasi_min = i;
        }
    }

    // menghitung nilai rata-rata
    float rata_rata = (float)total / a;

    // Menampilkan menu
    do
    {
        cout << "\n===== Menu =====\n";
        cout << "1. Mencari Nilai Maksimum\n";
        cout << "2. Mencari Nilai Minimum\n";
        cout << "3. Mencari Nilai Rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan : ";
        cin >> op;

        switch (op)
        {
        case 1:
            // Output nilai maksimum dan lokasinya
            cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi_maks << endl;
            break;
        case 2:
            // Output nilai minimum dan lokasinya
            cout << "Nilai minimum adalah " << min << " berada di Array ke " << lokasi_min << endl;
            break;
        case 3:
            // Output nilai rata-rata
            cout << "Nilai rata-rata adalah " << rata_rata << endl;
            break;
        case 4:
            // Keluar dari program
            cout << "Thank you!, Code By Kevin" << endl;
            break;
        default:
            // pilihan tidak valid
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (op != 4);

    return 0;
}

```

#### Output:
![Screenshot 2024-03-25 130448](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/b6f06814-0043-401b-980c-32c808a234f8)


#### Full code Screenshot:
![Screenshot 2024-03-25 130523](https://github.com/DestinaBektiS/Praktikum-Modul-2/assets/162097232/035269d8-b06d-4a3a-bbbe-1d56b862457a)


Interpretasi:
Pertama kita mendeklarasikan variabel terlebih dahulu, lalu kita input panjang array dan input nilai elemen array, setelah itu kita Inisialisasi variabel `maks` dan `min` dengan nilai elemen array pertama, lalu masukkan nilai rata", nilai maks, dan nilai min. Tetapi sebelum masukkan kita buat menu tersebut supaya mudah untuk mengoutputnya. Program ini bertujuan untuk mengetahui nilai rata - rata, nilai maks, dan nilai min dari suatu variabel.

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang Array dalam pemrograman. Array yang sudah diperlajari ada beberapa, seperti: array satu dimensi, array dua dimensi, array multi dimensi, dsb...
konsep - konsep dasar ini dapat dikuasai oleh para pembaca, dan pembaca akan dapat mudah menguasai bab array mulai dari cara menggunakan, memasukkan nilai / panjang array, dan yang paling penting bia memanipulasikan data dalam program secara efektif dan efisien. 

## Referensi
[1] Muhammad Benny Chaniago and Cecep Kurnia Sastradipraja, Buku Ajar Algoritma dan Struktur Data, 2022.        Available: Google Books. (n.d.-d). https://www.google.co.id/books/edition/Buku_Ajar_Algoritma_dan_Struktur_Data/3PKxEAAAQBAJ?hl=en&gbpv=1&dq=tentang+Array&pg=PA125&printsec=frontcover

[2] Google Books. (n.d.-e). https://www.google.co.id/books/edition/BUKU_AJAR_PEMROGRAMAN_STRUKTUR_DATA/LBLlEAAAQBAJ?hl=en&gbpv=1&dq=tentang+Array&pg=PA4&printsec=frontcover

[3] Google Books. (n.d.-f). https://www.google.co.id/books/edition/Asyiknya_Belajar_Struktur_Data_di_Planet/2ohzjTuw5MUC?hl=en&gbpv=1&dq=definisi+Array&pg=PA75&printsec=frontcover
