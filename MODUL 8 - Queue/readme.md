# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Queue

Nah gengs kalian tau gak nih, ada materi yang dimana materi tersebut sama cuman kebalikkanya gitu, nah materi ini ialah materi "Queue". Materi "Queue" ini kebalikannya dari materi stack yang kemarin gengs. Lalu apasih itu arti "Queue"?. Artinya yaitu "Antrian", tetapi berbeda lagi artinya jika digunakan dalam ilmu komputer gengs.

Menurut buku yang saya baca, dalam ilmu komputer. Queue/antrian adalah sebuah struktur data yang memodelkan fenomena antrian. [1]

Nah kamu sudah tahukan kalau antrian menggunakan prinsip "siapa yang datang duluan, dialah pula yang keluar duluan". Nah sifat dari "Queue" itu FIFO, sedangkan "Stack" itu LIFO. Hal itulah yang membuat Queue berkebalikan dengan stack. 

Apa saja yang bisa kita query kesebuah antrian?
- Buatlah sebuah antrian kosong -> bisa menggunakan fungsi Queue().
- Apakah antrian kosong -> bisa menggunakan fungsi isEmpty().
- Berapa panjangkah antriannya -> bisa menggunakan fungsi len(). [1]

Operasi - operasi yang dimiliki Queue:
- Enqueue -> untuk memasukkan ke dalam antrian.
- Dequeue -> untuk mengeluarkan data terdepan dari antrian.
- Clear -> untuk menghapus seluruh antrian.
- isEmpty -> untuk memeriksa apakah antrian kosong.
- isFull -> untuk memeriksa apakah antrian penuh.

Karakteristik Queue:
- Mempunyai elemen - elemen antrian.
- Front (elemen paling depan di antrian).
- Tail (elemen paling akhir di antrian).
- Count (jumlah elemen pada antrian).
- Status penuh dan status kosong. [2]

## Guided 
```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-13 093523](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/cd3b75b4-2152-4c52-97e0-6121a79d89d1)

#### Screenshoot Full:
![Screenshot 2024-05-13 093537](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/a6246561-29af-4eed-8c36-82579cde715b)

Interpretasi:
Program diatas yaitu untuk mengecek atau memasukkan data antrian teller. Tujuan ini bertujuan supaya pengguna memahami fungsi dari "Queue", serta untuk mengecek apakah antriannya kosong atau sudah penuh. 
Cara Kerjanya yaitu, kita masukkan dulu data - data antrian teller seperti antrian 1 Andi dan antrian 2 Maya, setelah itu kita run dan kita masukkan jumlah antrian teller sampai antrian itu kosong. 

## Unguided 

### [1]. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>

struct QueueNode {
    std::string data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* back;
    int size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

    ~Queue() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 5; 
    }

    void enqueue(std::string data) { /// Untuk menambahkan data ke dalam antrian
        if (isFull()) {
            std::cout << "Antrian Penuh" << std::endl;
            return;
        }

        QueueNode* newNode = new QueueNode();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }

        size++;
    }

    void dequeue() { /// Untuk mengahpus data paling depan
        if (isEmpty()) {
            std::cout << "Antrian kosong" << std::endl;
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty()) {
            back = nullptr;
        }
    }

    int count() {
        return size;
    }

    void clear() { /// Untuk menghapus semua data yang ada didalam antrian.
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        back = nullptr;
        size = 0;
    }

    void view() { /// Untuk menampilkan data pada sebuah antrian.
        std::cout << "Data antrian teller: " << std::endl;
        QueueNode* temp = front;
        int i = 1;
        while (temp != nullptr) {
            std::cout << i << ". " << temp->data << std::endl;
            temp = temp->next;
            i++;
        }
    }
};

int main() {
    Queue enqueue;

    queue.enqueue("Andi");
    queue.enqueue("Maya");                                             
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    queue.dequeue();
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    queue.clear();
    queue.view();
    std::cout << "Jumlah antrian = " << queue.count() << std::endl;
    return 0;
}
```

#### Output:
![Screenshot 2024-05-13 081737](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/3899e460-c1cb-45d4-ac34-0f2f65a53962)

#### Screenshoot Full:
![Screenshot 2024-05-13 081749](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/f88fedef-3856-45dd-94ee-75d0db91bad9)


Interpretasi:
Program diatas yaitu untuk memasukkan data, lalu diurutkan untuk menjadi sebuah antrian. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "queue", yaitu untuk membantu mengelola dan menyimpan operasi data pada FIFO.
Contoh cara kerjanya yaitu jika ada elemen data yang terdiri dari 5 indeks (A, B, C, D, E, F), yang dimana data (A) yaitu untuk keluar dari antrian dan juga urutan paling depan dari sebuah antrian, sedangkan data (F)  yaitu data untuk masuk dari antrian dan juga urutan paling akhir dari sebuah antrian.

Fungsi kode - kode diatas:
- "QueueNode" -> untuk menyimpan antrian data dengan node. Node sendiri terdiri dari string dan terdiri dari pointer untuk lanjut ke node tersebut.
- "class Queue" -> queue sendiri mempunyai kelas privat, yang dimana kelas tersebut memiliki beberapa pointer seperti, "front" -> untuk menandai pointer ke node pertama/paling depan dalam sebuah antrian, "back" -> untuk menandai pointer pointer ke node paling akhir dalamsebuah antrian, dan "size".

Penjelasan output:
Ada 2 data antrian teller yaitu antrian 1 atas nama Andi, dan antrian 2 atas nama Maya. Lalu setelah Andi selesai otomatis Maya maju dong ke meja teller, dan si Maya bisa dibilang sebagai pengganti yang pertama. Lalu setelah Andi selesai dan Maya selesai ya pasti otomatis kosong dong. Nah itulah cara kerja struktur data "Queue" ini.

### [2] Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
#include <string>

struct QueueNode {
    std::string nama;
    std::string nim;
    QueueNode* next;
};

class Antrian {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;

public:
    Antrian() : front(nullptr), rear(nullptr), size(0) {}

    ~Antrian() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 5;
    }

    void enqueue(std::string nama, std::string nim) {
        if (isFull()) {
            std::cout << "Antrian Penuh" << std::endl;
            return;
        }

        QueueNode* newNode = new QueueNode();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr; /// menggunakan Null karena kan kita gak tau antrian selanjutnya siapa dan yang pasti tidak mengandung sebuah nilai.

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong" << std::endl;
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty()) {
            rear = nullptr;
        }
    }

    int count() {
        return size;
    }

    void clear() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }

    void view() {
        std::cout << "Data antrian mahasiswa: " << std::endl;
        QueueNode* temp = front;
        int i = 1;
        while (temp != nullptr) {
            std::cout << i << ". Nama: " << temp->nama << ", NIM: " << temp->nim << std::endl;
            temp = temp->next;
            i++;
        }
    }
};

int main() {
    Antrian antrian;

    antrian.enqueue("Destina", "2311110018");
    antrian.enqueue("Satrio", "2331110070");
    antrian.enqueue("Billy", "23331100100");
    antrian.enqueue("Zelda", "23330310085");
    antrian.view();
    std::cout << "Jumlah antrian = " << antrian.count() << std::endl;
    antrian.dequeue();
    antrian.view();
    std::cout << "Jumlah antrian = " << antrian.count() << std::endl;
    antrian.dequeue();
    antrian.view();
    std::cout << "Jumlah antrian = " << antrian.count() << std::endl;
    antrian.dequeue();
    antrian.view();
    std::cout << "Jumlah antrian = " << antrian.count() << std::endl;
    antrian.clear();
    antrian.view();
    std::cout << "Jumlah antrian = " << antrian.count() << std::endl;
    return 0;
}
```

#### Output:
![Screenshot 2024-05-13 092135](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/8e4d49cf-513d-4708-9c69-50d7baf7519b)

#### Screenshoot Full:
![Screenshot 2024-05-13 092149](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/61a1672f-f926-4354-9e84-a21b9514e33a)

Interpretasi:
Program diatas yaitu untuk memasukkan data NIM dan Nama dari Mahasiswa, lalu diurutkan untuk menjadi sebuah antrian. Tujuan program ini dibuat supaya pengguna bisa memahami fungsi dari "queue", yaitu untuk membantu mengelola dan menyimpan operasi data pada FIFO.
Contoh cara kerjanya yaitu jika ada elemen data yang terdiri dari 5 indeks (A, B, C, D, E, F), yang dimana data (A) yaitu untuk keluar dari antrian dan juga urutan paling depan dari sebuah antrian, sedangkan data (F)  yaitu data untuk masuk dari antrian dan juga urutan paling akhir dari sebuah antrian.

Fungsi kode - kode diatas:
- "antrian.enqueue" -> untuk menambahkan data antrian menjadi 4 antrian.
- "antrian.view" -> untuk menampilkan semua data Mahasiswa.
- "antrian.count" -> untuk mencetak jumlah elemen data yang ada didalam antrian.
- "antrian.dequeue" -> untuk menghapus satu - persatu data yang ada didalam antrian. 
- "antrian.clear" -> untuk menghapus atau mengosonngkan semua antrian tersebut. 

Penjelasan output:
Ada 4 data antrian NIM dan Nama Mahasiswa yaitu antrian 1 atas nama Destina, antrian 2 atas nama Satrio, antrian 3 atas nama Billy, dan antrian terakhir atas nama Zelda. Pertama kali saat dipanggil otomatis Destina dong, setelah Destina selesai mengantri dia maju dong, dan otomatis antrian itu tetap bergilir sampai di antrian terakhir yaitu antrian Zelda. Nah setelah Zelda selesai mengantri otomatis antrian itu kosong dong, dan itulah yang dimaksud dengan struktur data Queue ini.

## Kesimpulan
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang "Queue" dalam pemrograman. Queue adalah kumpulan data yang mana penambahan elemen tersebut hanya bisa dilakukan pada suatu ujung yang bernama "ral tail" atau belakang, dan penghapusan dilakukan melalui ujung yang bernama "front/head".

> Fungsi queue ;
- Menangani sebuah antrian.
- Pengolahan data.
- Penyimpan data.
- dan Pemroresan pesan.

> Kelebihan Queue ;
- Menggunakan prinsip FIFO.
- Mudah digunakan.
- Flexibell dan mengurangi waktu para pengantri.
- Mengurangi kegagalan atau kecurangan sistem.

## Referensi
[1] Modul Praktikum Algoritma & Struktur Data Versi 4.3
By Fajar Suryawan, Husni Thamrin, Dimas Aryo Anggoro, Wiwit Supriyanti, Yunita Ardiyanto

[2] Modul Diktat Algoritma dan Struktur Data 2. By Unikom.
https://repository.unikom.ac.id/41990/1/pertemuan%203.pdf 

