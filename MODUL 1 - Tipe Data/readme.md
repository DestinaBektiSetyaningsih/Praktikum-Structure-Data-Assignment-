# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018)</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

Untuk menampung data biasanya kita memerlukan suatu variabel, setiap variabel harus memerlukan tipe data. Lalu apasi itu tipe data?
Tipe Data ialah gambaran jenis data dan bentuk data lalu di olah dan di jalankan / di operasikan oleh program komputer.

Nah menurut buku yang saya baca, tipe data itu ada 2, yaitu: tipe data primitif dan tipe data kompleks.

Nah pada kali ini saya akan memberikan penjelasan tentang tipe data primitf dan tipe data kompleks.

Tipe Data Primitif = sebuah jenis data yang paling sederhana dalam pemrograman. tipe data ini dapat menyimpan satu nilai yaitu seprti digit, byte, atau karakter.

Tipe Data Abstrak =  sebuah jenis data yang berbentuk matematika yang merujuk pada sejumlah nilai dan operasi yang diizinkan pada suatu tipe data.

Tipe Data Koleksi = sebuah jenis data yang dapat digunakn untuk menyimpan dan menyediakan akses ke berbagai elemen yang berbeda.

## Guided 

```C++
### 1. [Tipe Data Primitif]

#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user enter operatoe i.e, +, -, *, /
    cin >> op;
    // It alllow user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch  (op)
    
    {
    //  If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than ....
    // error message will display
    default:
        cout << "Error! operator is not correct";
    }
    return 0;
}
```
Kode di atas digunakan untuk mencari rumus "Belah Ketupat" menggunakan function cout untuk menampilkan hasil dari keliling dan luas bangun datar itu.

###2. [Tipe Data Abstract]

```C++
#include <stdio.h>

struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1,mhs2;
    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
###3. [Tipe Data Koleksi]

```C++
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;

//Mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
```

## Unguided 

### 1. [Tipe Data Primitif]

Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.
Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari
materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

int hitungKeliling(int s) {
    return 4 * s;
}

int hitungLuas(int d1, int d2) {
    return (d1 * d2) / 2;
}

int main() {
    int sisi, diagonal1, diagonal2, Destina;

    cout << "\nHITUNG BELAH KETUPAT\n";
    cout << "\nMasukkan panjang sisi: "; cin >> sisi;
    cout << "\nMasukkan panjang diagonal 1: "; cin >> diagonal1;
    cout << "\nMasukkan panjang diagonal 2: "; cin >> diagonal2;
    cout << "\nPilih Menu\n";
    cout << "1. Hitung Keliling\n";
    cout << "2. Hitung Luas\n";
    cout << "\nMasukkan Pilihan: "; cin >> Destina;

    switch (Destina) {
        case 1:
            cout << "\nHasil: " << hitungKeliling(sisi);
            break;
        case 2:
            cout << "\nHasil: " << hitungLuas(diagonal1, diagonal2);
            break;
        default:
            cout << "\nMaaf, pilihan Anda salah!";
    }

    return 0;
}

```
#### Output:
(![Screenshot 2024-03-11 081738](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/4509ca1e-4283-4818-b68c-4a1f88220217))

Kode di atas digunakan untuk mencari rumus "Belah Ketupat" menggunakan function cout untuk menampilkan hasil dari keliling dan luas bangun datar itu dan switch untuk menyeleksi kode tersebut

#### Full code Screenshot:
![240309_10h21m35s_screenshot]![Screenshot 2024-03-11 074531](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/b372a86f-8813-4b82-abb7-69bc70096ac4)
![Screenshot 2024-03-11 074549](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/e4eb8bd2-e19a-4d58-b9d5-b5a7648a1da3)

Interpretasi:
program diatas meminta pengguna untuk memasukan nilai keliling dan nilai luas pada bangunan belah ketupat dengan menggunakan cin dan cout, kemudian di simpan pada variabel keliling dan luas.
Kemudian program itu menghitung keliling dan luas dengan cara memanggil fungsi hitungkeliling(sisi), lalu outputnya akan keluar.

### 2. [Tipe Data Abstrak]
Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

Perbedaan antara Class dan Struct: 
- kalo class bersifat private. Data yang terdapat di dalam sebuah class tidak dapat di akses atau dimodifikasi dengan sembarangan, kecuali dengan cara tertentu.
- kalo Struct bersifat publik. Data yang terdapat di dalam sebuah  struct bisa di akses dan di modifikasi langsung dari luar.

```C++
#include <iostream>
using namespace std;

struct Kulkas{
    string minuman;
    string makanan;
    int jumlah;
};

int main(){
    Kulkas isi;
    isi.minuman = "yogurt";
    isi.makanan = "steak";
    isi.jumlah = 5;

    cout << "\naku mempunyai " << isi.jumlah << "kulkas";
    cout << "\nkulkas aku berisi" << isi.makanan;
    cout << "\nkulkas aku berisi" << isi.minuman << endl <<

endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-03-11 084518](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/bd277149-a46c-45cb-b2d9-0e555ede84e9)

#### Full code Screenshot:
![Screenshot 2024-03-11 084503](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/80c33d16-7ff5-4f48-bcb3-f446301bf468)

Interpretasi:
Program ini meminta untuk mendeklarasikan isi variabel. Program menyimpan struct kulkas dan makanan serta minuman berbentuk string. Lalu jumlah berbentuk integer dan variabel isi dari struct kulkas di deklarasikan.

### 3. [Tipe Data Koleksi]
Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari
array dengan map.

Perbedaan Array dan Map:
- Array = array memiliki 1 variabel yang dapat disimpan dalam data list dan kemudian dimanipulasinya yang jauh lebih efektif.
- Map = memetakan kunci ke nilai - nilai yang sesuai. setiap key dalam map, dan setiap kunci memiliki satu nilai yang terkait dengan map.

```C++
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int>skincare;

    skincare["glowing"] = 500000;
    skincare["acne"] = 350000;
    skincare["brightening"] = 200000;

    cout << "\nTipe Skincare Glowing memiliki harga :" <<
skincare["glowing"];
    cout << "\nTipe Skincare Acne memiliki harga :" <<
skincare["acne"];
    cout << "\nTipe Skincare Brightening memiliki harga :" <<
skincare["brightening"];

    string Destina;
    cout << "\n\nCek Tipe Skincare: "; cin >> Destina;
    if(skincare.find(Destina) != skincare.end()){
        cout << "\nStok Tersedia, Silahkan Tanya Penjual " << 
endl;
    } else{
    cout << "\nStok Tidak Tersedia, Silahkan mengikuti pre order." << endl;
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-03-11 094245](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/69d033e6-e6df-4ca3-ae5d-901de51df379)

#### Full code Screenshot:
![Screenshot 2024-03-11 094221](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/c330873d-ce64-4a11-a0c5-31121941ba98)

Interpretasi:
Program diatas meminta pengguna untuk mengecek stok skincare itu tersedia atau tidak. cara mengecek dengan menggunakan function cout, kemudian di simpan pada variabel "tipe skincare". Kemudian program itu akan mengecek ketersedian tipe skincare yang kita butuhkan.

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang tipe data dalam pemrograman. Tipe data yang sudah diperlajari ada 3 yaitu tipe data primitif. tipe data abstrak, dan tipe data koleksi. 

Tipe data Primitif adalah tipe yang berbentuk standar yang tidak diturunkan ke tipe data lainnya. [1]

ada 7 tipe data primitif:
1. Boolean (bool)
2. Character (char)
3. Integer (int)
4. Floating Point (float)
5. Double (double)
6. Valueless (void)
7. Wide Character (wchar_t)[2]

Class bisa diartikan sebagai cetak biru (blueprint) atau prototipe atau bisa dikatakan kerangka yang mendefinisikan variabel - variabel dan method - method umum dari sebuah objek. Class ini bisa dikatakan seperti kesatuan yang integrasi antara method dana dan data yang mengacu pada suatu objek.[1]

Fungsi map ialah sebuah program yang memuat kalkulasi yang akan di lakukan dalam proses map.
Fungsi map ini bertujuan untuk membaca input dalam bentuk pasangan value / key.[3]

## Referensi
[1]Algoritma dan Pemrograman Menggunakan Bahasa Pemrograman Java (Teori dan Aplikasinya). (n.d.). Google Books. https://books.google.co.id/books?id=2nMCEAAAQBAJ&newbks=0&printsec=frontcover&pg=PA47&dq=tipe+data+primitive+pemrograman&hl=en&source=newbks_fb&redir_esc=y#v=onepage&q=tipe%20data%20primitive%20pemrograman&f=false

[2]Google Books. (n.d.). https://www.google.co.id/books/edition/Pengantar_Konsep_Struktur_Data/SSH6DwAAQBAJ?hl=en&gbpv=1&dq=struktur+data&printsec=frontcover

[3]Google Books. (n.d.-b). https://www.google.co.id/books/edition/Tip_dan_Trik_Pemrograman_C++_Dari_Nol_Sa/XpGCDwAAQBAJ?hl=en&gbpv=1&dq=tipe+data+c%2B%2B&printsec=frontcover
