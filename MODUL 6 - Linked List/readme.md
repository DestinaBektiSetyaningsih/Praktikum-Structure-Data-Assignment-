# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Mungkin bagi kalian materi ini jarang didengar saat disekolah bukan? tetapi bagi kalian yang ambil jurusan berbasis komputer/coding pasti sudah tidak asing lagi nih, nah lalu apa sih linked list itu?

Nah menurut buku yang saya baca, bahwa Linked List adalah struktur yang berupa rangkaian elemen saling berkait, yang dimana tiap elemen dihubungkan ke elemen yang lain melalui pointer. [1]

Linked list -> suatu tipe data, yang dimana data tersebut akan disusun sebagaimana mirip dengan array, namun ada perbedaan yang besar bahwa ukuran linked list tidak statis. Itu artinya bahwa kita dapat melakukan operasi menambahkan elemen serta mengurangi elemen secara runtime. Linked list mempunyai elemen yaitu ListNode yang didalamnya terdapat data yang disimpan dan pointer ke ListNode sesudahnya atau next. [2]

##### Linked List terdiri dari 4 jenis, yaitu:
> Singly Linked List -> linked list unidirectional, yang artinya hanya bisa dilintasi dengan satu arah, seperti dari simpul kepala(head) ke simpul ekor(tail).

> Doubly Linked List -> linked list bidirectional, yang artinya bisa dilintasinya dengan dua arah. Tidak seperti singly linked list, simpul doubly linked list berisikan satu pointer tambahan yang disebut previous pointer, pointer ini menunjukkan ke simpul sebelumnya.

> Circular Linked List -> linked list unidirectional, tetapi berbeda dengan single list, jenis linked list ini  memiliki simpul terakhir yang menunjukkan ke simpul kepala. Jadi saat melintas, kita harus berhati-hati dan berhenti saat mengunjungi kembali simpul kepala.

> Circular Doubly Linked List -> linked list bidirectional, jenis ini gabungan dari doubly linked list dan circular linked list. Jadi perbedaannya, jenis ini memiliki pointer tambahan yang disebut previous pointer, dan hampir mirip dengan circular linked list, simpul terakhirnya menunjuk pada simpul kepala.

##### Kelebihan dan Kekurangan Linked List
> Kelebihan :
- Penambahan elemen tidak terbatas. -> linked list memungkinkan penambahan elemen tanpa perlu mengalokasikan memori secara berurutan, sehingga memungkinkan untuk diubah secara dinamis.

- Penghapusan elemen lebih cepat. -> operasi penghapusan elemen pada linked list dapat dilakukan dengan mudah dan relatif cepat.

> Kekurangan:
- Hanya bisa diakses secara sekuensial. Linked list memerlukan transversal dari awal hingga elemen yang diinginkan, sehingga akses data secara acak tidak dapat dilakukan secara efisien.

- Memerlukan memori dalam jumlah yang besar. -> linked list memerlukan lebih banyak memori dibandingkan dengan array, karena setiap elemen harus menyimpan alamat/referensi dari elemen berikutnya.  

## Guided 

```C++
### 1. Program Doubly Linked List

#include <iostream>
using namespace std;

///PROGRAM DOUBLE LINKED LIST
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-27 120238](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/a791164a-767e-4a11-bb13-cc61d6226f4b)

#### Screenshout Full:
![Screenshot 2024-04-27 120555](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/c1186275-9947-4c14-94bb-8376ace62916)

Interpretasi:
Program diatas ialah program doubly linked list yang dimana program ini bertujuan untuk membuat sebuah menu pada list daftar. Program ini juga mempunyai beberapa kelas seperti, kelas node yang dimana setiap node berisi intenger data. Didalam kelas node juga mempunyai 2 pointer, pointer "prev" untuk ke node sebelumnya dan pointer "next" untuk ke node selanjutnya. Lalu ada kelas doubly linked list, yang dimana kelas ini berisikan 2 pointer, yaitu "head" dan "tail". 
Fungsi - fungsinya:
- Untuk menambahkan node baru dengan data yang diberikan pada awal pendaftaran "void push(int data)".
- untuk menghapus node pertama dari daftar bisa menggunakan kode "void pop()"
- Untuk memperbaharui data dari node pertama old data lalu berubah menjadi new data menggunakan kode "update(int oldData, int newData)"
- Untuk menghapus semua node dalam daftar list bisa menggunakan "void deleteAll()"
- Untuk mencetak daftar dengan menggunakan kode "void display()".


```C++
### 2. Program Single Linked List Non Circular
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-27 142856](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/df56669b-e8c6-4f79-b531-fdc6dae9388e)

#### Screenshout Full:
![Screenshot 2024-04-27 145726](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/e3b8a653-b1c3-4848-8887-53413bb30794)

Interpretasi:
Program diatas ialah program singly linked list non circular yang dimana program ini bertujuan untuk membuat pengolahan data, pengolahan informasi, dsb...
Program ini memiliki beberapa fungsi, seperti:
- "struct Node" -> untuk mendefinisikan struktur yang terdapat didalam komponen - komponen node (data) dan (next)
- "void init()" -> untuk menginisialisasi linked list dengan mengatur (head) dan (tail) menjadi (NULL)
- "isEmpty()" -> untuk memeriksa apakah linked list sedang kosong atau tidak
-  "void clearList()" -> untuk menghapus seluruh isi linked list.


```C++
### 3. Program Single Linked List Circular
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if(head == NULL)
       return 1; // true
    else
       return 0; // false     
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        bantu->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void HapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;
        
        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }
            
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transversing
        int nomor = 1;
        bantu = head;
        
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masik kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    HapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-27 202344](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/59218f18-b6e5-41f0-b514-52e87c3f16d9)

#### Screenshout Full:
![Screenshot 2024-04-27 202357](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/ce88c1f6-c859-49d6-965f-d84f1f962718)

Interpretasi:
Program diatas ialah program singly linked list circular, program ini adalah struktur data yang terdiri dari node - node yang saling terhubung, yang dimana setiap node memiliki data dan pointer ke node berikutnya. Program ini bertujuan untuk digunakan dalam aplikasi - aplikasi yang memerlukan pengelolaan data dalam bentuk keliling, seperti pengelolaan daftar, pengelolaan queue, dsb..

## Unguided 

### 1. [Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa].

```C++
#include <iostream> 
#include <string> 
using namespace std;

struct Node {
    string list_nama;
    string list_nim;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
void init() {
    head = NULL;
    tail = NULL;
}
bool isEmpty() {
    return head == NULL;
}
void insertDepan(string nama, string nim) {
    Node* baru = new Node;
    baru->list_nama = nama;
    baru->list_nim = nim;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, string nim) {
    Node* baru = new Node;
    baru->list_nama = nama;
    baru->list_nim = nim;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void insertTengah(string nama, string nim, int posisi) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
    } else {
        Node* baru = new Node;
        baru->list_nama = nama;
        baru->list_nim = nim;
        baru->next = NULL;

        Node* bantu = head;
        int nomor = 1;

        while (bantu != NULL && nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        if (bantu == NULL) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

void ubahData(string& namaBaru, string& nimBaru, int posisi) {
    Node* bantu = head;
    int nomor = 1;

    while (bantu != NULL && nomor < posisi) {
        bantu = bantu->next;
        nomor++;
    }

    if (bantu == NULL) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        cout << "Masukkan nama : ";
        cin >> namaBaru;
        cout << "Masukkan NIM : ";
        cin >> nimBaru;
        bantu->list_nama = namaBaru;
        bantu->list_nim = nimBaru;
    }
}

void hapusNode(int posisi) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node* hapus;
    if (posisi == 1) {
        hapus = head;
        head = head->next;
    } else {
        Node* bantu = head;
        int nomor = 1;

        while (bantu != NULL && nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        if (bantu == NULL || bantu->next == NULL) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        if (hapus == tail) {
            tail = bantu;
        }
    }

    cout << "Data " << hapus->list_nama << " berhasil dihapus" << endl;
    delete hapus;
}

void hapusList() {
    Node* bantu = head;
    Node* hapus;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

int hitungList() {
    Node* hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

void tampil() {
    Node* bantu = head;
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
    } else {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (bantu != NULL) {
            cout << bantu->list_nama << "\t" << bantu->list_nim << endl;
            bantu = bantu->next;
        }
    }
}

void menu() {
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. Tampilkan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih Operasi : ";
}

int main() {
    init();
    int pilihan;
    string nama, nim;
    int posisi;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                ubahData(nama, nim, 1);
                cout << "Data telah diubah" << endl;
                break;
            case 5:
                ubahData(nama, nim, hitungList());
                cout << "Data telah diubah" << endl;
                break;
            case 6:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                ubahData(nama, nim, posisi);
                cout << "Data telah diubah" << endl;
                break;
            case 7:
                hapusNode(1);
                break;
            case 8:
                hapusNode(hitungList());
                break;
            case 9:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                hapusNode(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampil();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
#### Output:
![Screenshot 2024-04-28 153740](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/f96f708e-de21-4442-8ad0-34e10879d1d8)

#### Screenshoot Full:
![Screenshot 2024-04-28 162936](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/8be6bfc3-56df-47b0-bb04-2c1d140cfa8f)

Interpretasi:
Program diatas ialah program singly linked list non circular, yang dimana bersifat unidirectional, yang artinya hanya bisa dilintasi dengan satu arah, seperti dari simpul kepala(head) ke simpul ekor(tail). Program diatas memiliki masing-masing fungsi, seperti:

##### > Struktur Node
program menggunakan kode "Node" -> untuk mempresentasikan setiap elemen dalam linked list. setiap node memiliki "list_nama" dan "list_nim", serta "next" untuk melanjutkan ke node berikutnya.

##### > Operasi - operasi Linked List
- "void" -> untuk menunjukkan bahwa suatu fungsi tidak mengembalikkan nilai apapun, artinya fungsi ini tidak bisa mengembalikkan nilai apapun setelah dieksekusi.

- "init" -> untuk menginisialisasi linked list dengan mengatur head dan tail.

- "isEmpty" -> untuk memeriksa apakah linked list kosong dengan memeriksa apakah 'head = NULL'.

- "insertDepan" -> untuk memasukkan node baru dibagian depan list.

- "insertBelakang" -> untuk memasukkan node baru dibagian belakang list.

- "insertTengah" -> untuk memasukkan node baru di posisi bagian tertentu.

- "ubahData" -> untuk mengubah data dari node pada posisi bagian tertentu.

- "hapusNode" -> untuk menghapus node pada posisi bagian tertentu.

- "hapusList" -> untuk menghapus semua node dalam list.

- "hitungList" -> untuk mengembalikkan jumlah node dalam list.

- "tampil" -> untuk menampilkan isi dari list tersebut.

- "main" -> fungsi utama dari program diatas dengan menggunaka main, karena fungsinya untuk menginisialisasi linked list dan memasukkan sebuah loop yang dimana program ini untuk menampilkan menu dan melakukan operasi yang dipilih oleh pengguna berdasarkan pilihan mereka.

### 2. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)].

#### Output:

![Screenshot 2024-04-28 164259](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/6ce54cdd-7eef-4432-869c-54524d00dc3e)

![Screenshot 2024-04-28 164329](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/8e819187-818a-4379-a8b6-cf3bebb7b41d)

![Screenshot 2024-04-28 164343](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/66862083-f857-4635-b029-4f4ebb443138)

![Screenshot 2024-04-28 164357](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/8da2aec7-d275-4deb-a4fa-7b0adc2385fd)

![Screenshot 2024-04-28 164426](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/cb9bed56-00ff-43eb-9879-13a261d20990)

![Screenshot 2024-04-28 164435](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/cd415b77-aae4-46dc-bcaf-046f1de73a6c)

![Screenshot 2024-04-28 164452](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/858f34d9-9cf3-4493-bbee-0c321235d0f9)

![Screenshot 2024-04-28 164506](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/9fc38489-fed0-460a-93fa-4725248689c8)

![Screenshot 2024-04-28 164519](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/30e0ae22-fcf8-4ffc-8cc4-541d9498c321)

![Screenshot 2024-04-28 164530](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/29cda1f3-a03b-492c-baa7-25eaafe957a1)

![Screenshot 2024-04-28 164543](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/54d7bae2-2a74-4432-86dc-179b21ae776c)


### 3. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu ubah ke dalam bentuk list].

a. Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004 

![Screenshot 2024-04-28 172825](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/98db51b8-a127-4c85-b2ea-124793a059e2)

b. Hapus data Denis 

![Screenshot 2024-04-28 172850](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/9cb7710c-42a0-434e-bb0c-fd584de4f3b9)

c. Tambahkan data berikut di awal: 
Owi 2330000 

![Screenshot 2024-04-28 172906](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/478bf7de-3b67-445c-8817-57323474c4b4)

d. Tambahkan data berikut di akhir: 
David 23300100 

![Screenshot 2024-04-28 172917](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/68f6503e-ed66-4eec-bb17-4ff89774e916)

e. Ubah data Udin menjadi data berikut: 
Idin 23300045 

![Screenshot 2024-04-28 172929](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/1317c254-0df5-463d-a87e-d717ebfee94e)

f. Ubah data terkahir menjadi berikut: 
Lucy 23300101 

![Screenshot 2024-04-28 172939](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/fcfb3e80-ab45-4347-aff5-c4788d98c8bb)

g. Hapus data awal

![Screenshot 2024-04-28 172953](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/ffb232e9-37b5-43c4-8327-2c7dfe6f31a9)

h. Ubah data awal menjadi berikut: 
Bagas 2330002 

![Screenshot 2024-04-28 173007](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/49456421-c433-4d0d-9d4c-329f0808838e)

i. Hapus data akhir

![Screenshot 2024-04-28 173027](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/b062f83f-7997-46c8-be8b-a2eee38d82e7)

j. Tampilkan seluruh data

![Screenshot 2024-04-28 173042](https://github.com/DestinaBektiS/Praktikum-Structure-Data-Assignment-/assets/162097232/ab59ba74-656c-418c-8fa1-01473238df77)

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang Linked List dalam pemrograman. Linked List yang sudah diperlajari ada 4  yaitu single linked list circular, single linked list non circular, double linked list circular, dan double linked list non circular.

Materi Linked List ini merupakan salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas adalah senarai berkait (linked list). 

secara teori, linked list adalah sejumlah node yang dihubungkan secara linier dengan bantuan pointer. Lalu ada operasi - operasi dalam linked list, kira - kira apa saja yaa?..

Operasi - Operasi Linked List:
- insert -> untuk menambhkan sebuah simpul baru ke dalam suatu linked list.

- isEmpty -> untukmenentukan apakah linked list tersebut kosong atau tidak.

- Find First -> untuk mencari elemen pertama dalam linked list.

- Find Next -> untuk mencari elemen sesudah elemen tersebut ditunjuk.

- Update -> untuk mengubah elemen yang ditunjuk oleh isi dari sesuatu.

- Delete -> untuk menghapus elemen yang sedang ditunjuk. Jika yang dihapus adalah elemen pertama dari linked list (head), maka (head) akan berpindah ke elemen berikutnya.

- Clear -> untuk menghapus linked list yang sudah ada. Fungsi ini harus ada apabila pengguna ingin mengakhiri program yang menggunakan linked list tersebut. Jika ingin melakukannya, data - data yang dialokasikan ke memori pada program sebelumnya akan tetap tertinggal didalam memori tersebut.

## Referensi
[1] Modul Praktikum Struktur Data, Tim Dosen Teknik Informatika dan Sistem Informasi.
https://digilib.esaunggul.ac.id/public/UEU-Course-9290-7_0141.pdf

[2] Mudah Belajar Pemrograman Dasar C++
By Andi Baso Kaswar, Nurjannah, Satria Gunawan Zain
Google Books. (n.d.). https://google.co.id/books/edition/Mudah_Belajar_Pemrograman_Dasar_C++/_kpKEAAAQBAJ?hl=en&gbpv=1&dq=tipe+data+struct&pg=PA95&printsec=frontcover

