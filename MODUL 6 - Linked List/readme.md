# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Mungkin bagi kalian materi ini jarang didengar saat disekolah bukan? tetapi bagi kalian yang ambil jurusan berbasis komputer/coding pasti sudah tidak asing lagi nih, nah lalu apa sih linked list itu?

Nah menurut buku yang saya baca, bahwa Linked List adalah struktur yang berupa rangkaian elemen saling berkait, yang dimana tiap elemen dihubungkan ke elemen yang lain melalui pointer. [1]

Linked list -> suatu tipe data, yang dimana data tersebut akan disusun sebagaimana mirip dengan array, namun ada perbedaan yang besar bahwa ukuran linked list tidak statis. Itu artinya bahwa kita dapat melakukan operasi menambahkan elemen serta mengurangi elemen secara runtime.

Linked list mempunyai elemen yaitu ListNode yang didalamnya terdapat data yang disimpan dan pointer ke ListNode sesudahnya atau next. [2]

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
- Hanya bisa diakses secara sekuensial. -> linked list memerlukan transversal dari awal hingga elemen yang diinginkan, sehingga akses data secara acak tidak dapat dilakukan secara efisien.

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
!(<Screenshot 2024-04-27 120238.png>)

#### Screenshout Full:
!(<Screenshot 2024-04-27 120555.png>)