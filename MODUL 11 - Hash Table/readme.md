# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Hash Table

Gengs ternyata di dalam materi struktur data ada Hash Table lho, lalu apa itu hash table?..

Hash table adalah sebuah struktur data yang terdiri atas sebuah tabel dan fungsi, yang bertujuan untuk memetakan nilai kunci yang unik untuk setiap record atau baris menjadi angka atau hash lokasi record tersebut ke dalam sebuah tabel.

> Tujuan - Tujuan Hash Table:
- mendapatkan posisi baik lokasi maupun alamat record secara langsung.
- mempercepat pencarian kembali dari banyak data yang disimpan.
- dapat memotong banyak biaya pencarian rektori, seperti menghapus dan memasukkan data.
- mempercepat table look up atau untuk membandingkan data.
- memproses menyimpan dan mencari data lebih cepat.

> Operasi Operasi Hash Table:
- Insert -> diberikan sebuah key dan nilai, insert nilai dalam tabel.
- Remove -> diberikan pada key, lalu temukan nilai yang berhubungan dengan key, kemudian hapus nilai tersebut.
- Getlterator -> mengembalikan iterator yang memeriksa nilai satu demi satu.

Nah gengs, selain pengertian, tujuan, dan operasi - operasi hash table, hash table juga memiliki beberapa kelebihan dan keuntungan lho, lalu apa saja sih kelebihan dan kekurangan has table ini?..

> Kelebihan:
- waktu aksesnya yang cukup cepat. -> jika record yang dicari langsung berada pada angka hash lokasi penyimpanannya.
- hashing relative lebih cepat dari biasanya.
- kecepatan dalam insertions, deletions, maupun searching relatif sama.
- mudah digunakan saat mempresentasikan data dengan frekuensi insert, delete, dan search yang tinggi. 

> Kekurangan:
-> sering adanya kemungkinan terjadi collision atau tabrakan. Collision atau tabrakan sering terjadi saat dimana ada 2 angka yang dimasukkan dalam fungsi hash yang menghasilkan nilai hasil yang sama. [1]

## Guided 

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

Interpretasi:
Program diatas adalah program "Hash Table", struktur data ini menggunakan teknik penambahan, penghapusan, dan pencarian dengan menggunakan constant average time. Tujuan program ini untuk supaya pengguna memahami fungsi dari materi struktur data ini.

Contoh cara kerja hash table:
- (menginisialisasi) dengan ukuran tertentu, dan ukuran ini bisa disesuaikan sesuai kebutuhan.
- (fungsi hash) untuk memetakan nilai yang diberikan dengan kunci tertentu ke dalam indeks, dan untuk menghasilkan nilai pada setiap kunci yang berbeda.
- (pemetaan nilai) ketika sebuah elemen baru ditambahkan ke dalam hash table, lalu menentukan indeks tempat elemen itu yang akan disimpan dalam array.
- (penanganan bentrok) bentrokan bisa terjadi apabila 2 key yang berbeda dapat menghasilkan nilai hash yang sama.
- (operasi utama) untuk melakukan pencarian elemen berdasarkan kunci, untuk melakukan penambahan elemen baru, dan untuk melakukan penghapusan pada elemen.
- (efisiensi) ukuran hash table bisa mempengaruhi efisiensi, di karena ukuran yang terlalu kecil bisa menyebabkan banyak bentrokan atau tabrakan lho, yang diakibatkan ukuran yang sangat besar dan bisa menyebabkan pemborosan memori.  

Cara kerja program diatas: 
kita mendapatkan 1 kunci dan 1 kunci itu memiliki nilai 10, berbeda dengan kunci yang satunya, nah yang satu mendapatkan 4 kunci dan 4 kunci itu tidak memiliki nilai, jadi kunci 4 itu mengembalikan nilai itu menjadi -1. Nah yang bawahnya itu nilai yang dimiliki oleh kunci 1, kunci 2, dan kunci 3. Kunci 1 memiliki nilai 10, kunci 2 memiliki nilai 20, dan kunci 3 memiliki nilai 30.

#### Output:
![Screenshot 2024-06-03 212305](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/440f8491-b0f3-4841-ae7e-3c4319dd94c4)

#### Full ScreenShoot:
![Screenshot 2024-06-03 212326](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/6e14b129-71d4-4f00-8152-570730e2167e)

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

Interpretasi:
Program diatas adalah program "Hash Table", struktur data ini menggunakan teknik penambahan, penghapusan, dan pencarian dengan menggunakan constant average time. Tujuan program ini untuk supaya pengguna memahami fungsi dari materi struktur data ini.

Fungsi operasi program diatas:
- "TABLE_SIZE = 11" -> untuk ukuran tabel hash, dan tabel hash berukuran 11.
- "name dan phone_number" -> hash memiliki 2 variabel, nah variabel ini yang digunakan sebagai kunci dan nilai pada hash map.
- "HashNode" -> untuk mempresentasikan node yang dimiliki oleh hash map.
- "hashFunc(string key)" -> untuk mengubah kunci tersbut menjadi indeks.
- "insert(string name, string phone_number)" -> untuk menyisipkan data (nama) dan data (nomer telp) ke dalam hash map.
- "remove(string name)" -> untuk menghapus data (nama) dari hash map.
- "searchByName(string name)" -> untuk mencari data (nama) berdasarkan kunci. Jika kunci tersebut ditemukan, maka nilai akan dikembalikan.

Cara kerja program diatas:
- Pertama, nomer hp Mistah = 1234, nomer ini sudah dimasukkan ke dalam hash map, begitupun dengan nomer hp Pastah = 5678. Lalu nomer hp Mistah setelah dihapus, nomer telp Miftah sudah dihapus dari has map, jadi nomer hp Miftah sudah tidak tersedia lagi. 

- Kedua, "Hash Table" ini sebuah header yang tidak memiliki elemen, seperti 1,2,3,7,8,9,10. Angka - angka tersebut tidak memiliki elemen seperti kunci dan nilai, berbeda dengan angka 4 dan 6, angka itu memiliki elemen, seperti angka 4 memiliki kata kunci "Pastah" dan memiliki nilai (5678), sedangkan angka 6 memiliki kata kunci "Ghana" dan memiliki nilai (91011). 

#### Output:
![Screenshot 2024-06-03 230245](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/1cb96820-f265-4c8d-90d5-a6371bb9a4c8)

#### Full ScreenShoot:
![Screenshot 2024-06-03 230302](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/07f9edd4-ea75-40e1-8aee-43a65e4351f5)

## Unguided 

### [1]. 1.	Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :a.	Setiap mahasiswa memiliki NIM dan nilai. b.	Program memiliki tampilan pilihan menu berisi poin C. c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 5;

struct Mahasiswa
{
    string name;
    long NIM;
    int grade;
    Mahasiswa *next; 

    Mahasiswa(string nama, long NIM, int nilai) : name(nama), NIM(NIM), grade(nilai), next(nullptr) {}
};

class HashTable
{
private:
    Mahasiswa **table; 
    int hash_func(long key)
    {
        return key % MAX_SIZE;
    }

public:
    HashTable()
    {
        table = new Mahasiswa *[MAX_SIZE](); 
    }

    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i];
            while (current != nullptr)
            {
                Mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    
    void insert(string nama, long NIM, int nilai)
    {
        int index = hash_func(NIM);                                 
        Mahasiswa *new_mahasiswa = new Mahasiswa(nama, NIM, nilai); 
        new_mahasiswa->next = table[index];                         
        table[index] = new_mahasiswa;
    }

    void remove(long NIM)
    {
        int index = hash_func(NIM);        
        Mahasiswa *current = table[index]; 
        Mahasiswa *prev = nullptr;         
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; 
                }
                else
                {
                    prev->next = current->next; 
                }
                delete current; 
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    Mahasiswa *cari_NIM(long NIM)
    {
        int index = hash_func(NIM); 
        Mahasiswa *current = table[index]; 
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                return current; 
            }
            current = current->next;
        }
        return nullptr;
    }

    void cari_nilai(int awal, int akhir)
    {
        cout << "+---------------------+-----------------+---------------+" << endl;
        cout << "|       Name          |       NIM       |     Grade     |" << endl;
        cout << "+---------------------+-----------------+---------------+" << endl;
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i]; 
            while (current != nullptr)
            {
              
                if (current->grade >= awal && current->grade <= akhir)
                {
                    cout << "| " << setw(19) << left << current->name
                         << "| " << setw(15) << current->NIM
                         << "| " << setw(13) << current->grade << " |" << endl;
                }
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+" << endl;
    }

    void traverse()
    {
        cout << "+---------------------+-----------------+---------------+" << endl;
        cout << "|       Name          |       NIM       |     Grade     |" << endl;
        cout << "+---------------------+-----------------+---------------+" << endl;
      
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            Mahasiswa *current = table[i]; 
            while (current != nullptr)
            {

                cout << "| " << setw(19) << left << current->name
                     << "| " << setw(15) << current->NIM
                     << "| " << setw(13) << current->grade << " |" << endl;
                current = current->next;
            }
        }
        cout << "+---------------------+-----------------+---------------+" << endl;
    }
};

int main()
{
    HashTable ht;

    int pilih, nilai, awal, akhir;
    string nama;
    long long NIM;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Menambahkan Data Mahasiswa" << endl;
        cout << "2. Menghapus Data Mahasiswa" << endl;
        cout << "3. Mencari berdasarkan NIM" << endl;
        cout << "4. Mencari berdasarkan Nilai" << endl;
        cout << "5. Menampilkan Semua Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> NIM;
            cout << "Masukkan nilai : ";
            cin >> nilai;
            ht.insert(nama, NIM, nilai);
            cout << "Data berhasil ditambahkan" << endl;
            break;
        case 2:
            cout << "Masukkan NIM yang ingin dihapus : ";
            cin >> NIM;
            ht.remove(NIM);
            break;
        case 3:
            cout << "Masukkan NIM yang ingin dicari : ";
            cin >> NIM;
            {
                Mahasiswa *mahasiswa_ptr = ht.cari_NIM(NIM);
                if (mahasiswa_ptr)
                {
                    cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->name << 
                    " dan memiliki nilai " << mahasiswa_ptr->grade << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                }
            }
            break;
        case 4:
            cout << "Masukkan nilai awal : ";
            cin >> awal;
            cout << "Masukkan nilai akhir : ";
            cin >> akhir;
            ht.cari_nilai(awal, akhir);
            break;
        case 5:
            ht.traverse();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilih != 6);

    return 0;
}
```

Interpretasi:
Program diatas adalah program "Hash Table", struktur data ini menggunakan teknik penambahan, penghapusan, dan pencarian dengan menggunakan constant average time. Ukuran Hash table (H-size) biasanya lebih besar dari jumlah data yang hendak disimpan. Hash tabel juga memiliki "Load Factor" untuk membandingkan antara data yang disimpan dengan ukuran tablenya. Tujuan program ini untuk mengetahui bahwa setiap key yang digunakan untuk memetakan kunci pada bilangan dalam rentang 0 hingga H size -1, dan tujuan lain supaya pengguna memahami fungsi dari materi struktur data ini.

Fungsi kode program diatas: 
- "insert(string nama, long NIM, int nilai)" -> untuk menyisipkan data (nama) data (NIM), dan data (nnilai) ke dalam hash map. Jika kunci dalam hash map sudah ada, maka nilai akan diupdate, begitupun sebaliknya. Jika kunci dalam hash map tidak ada, maka akan membuat node baru dan disimpan ke dalam ektor.
- "remove(long NIM)" -> untuk menghapus data (NIM) dari hash map berdasarkan NIM. Jika kunci ditemukan, maka node akan dihapus dari vektor tersebut.
- "cari_nilai(int awal, int akhir)" -> untuk mencari nilai sesuai berdasarkan urutan nilai di awal dan nilai di akhir.
- "traverse()" -> untuk menampilkan semua data mahasiswa dalam hash table.

Cara kerja program diatas:
- Pertama, masukkan dulu kode yang ada di hash table, lalu masukkan nama mahasiswa, NIM, serta nilai mahasiswa, lalu urutkan lagi sesuai kamu mau masukkin berapa mahasiswa.
- Kedua, setelah udah dimasukkan dan diurutkan, kamu bisa langsung next ke list berikutnya yaitu list "menghapus data mahasiswa", setelah itu data akan otomatis terhapus dari hash map atau hash table.
- Ketiga, setelah itu kita pergi ke list no 3 "mencari berdasarkan NIM", list tersebut akan meminta "NIM cari sendiri".
- Keempat, setelah itu kita bisa pergi lagi ke list no 4,"mencari berdasarkan nilai", nah nilai disini yang dimasukkan itu (nilai akhir) dan (nilai awal), dan otomatis mengeluarkan output dalam berbentuk tabel. 
- Dst ya...

#### Output:
![Screenshot 2024-06-04 001348](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/fe424f7a-c4bd-49d2-8959-1947b2bbc1c5)

#### Full ScreenShoot:
![Screenshot 2024-06-04 001409](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/3d5de1b9-fd92-421c-aba1-689a76dace9f)

## Kesimpulan :
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang "Hash Table" dalam struktur data pemrograman. Hash Table -> arrays dengan sel - sel yang ukurannya telah ditentukan dan dapat berisi data atau key yang berkesesuaian dengan data.

Tipe data Primitif adalah tipe yang berbentuk standar yang tidak diturunkan ke tipe data lainnya. [1]

> Ada beberapa fungsi pada Hash Table:
- mudah dihitung.
- 2 key yang berbeda akan dipetakan pada 2 sel yang berbeda pada array.
- membagi key secara rata pasa seluruh sel.
- sebuah fungsi hash sederhana dengan menggunakan fungsi mod dan bilangan prima.
- dapat menggunakan manipulasi digit dengan kompleksitas rendah dan distribusi key yang rata.[2]

> Contoh gambar fungsi Hash Table:
![Screenshot 2024-06-04 001813](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/561c2894-e6a7-4a68-a1c9-93100eaea0e5)


## Referensi :
[1] Studocu. (n.d.). Summary Hash Table - MODUL HASH TABLE by:  Andreas Putra Wijaya  Christopher Putra  Stefano - Studocu. https://www.studocu.com/id/document/universitas-pelita-harapan/struktur-data-konsentrasi-matematika-komputasi/summary-hash-table/28853068

[2] Modul Online
http://aren.cs.ui.ac.id/sda/resources/sda2010/15_hashtable.pdf

