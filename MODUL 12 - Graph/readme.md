# <h1 align="center">Laporan Praktikum Modul Graph and Tree</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
GRAPH AND TREE
//
gengs kalian tau gak nih didalam algoritma terdapat 2 struktur data, yaitu -> struktur data linier dan struktur data non linier.

Apa saja Struktur Data Linier?
- Array.
- Stack.
- Queue.
- Linked List.

Lalu apa saja Struktur Data Non Linier?
- Graph.
- Tree.
- Map / Hash Table.

Apa saja perbedaan dari struktur data linier dan struktur data non linier ?...
> Struktur Data Linier -> struktur data ini memiliki elemen - elemen yang disusun secara beurutan satu demi satu. Karena elemen tersebut disusun dalam urutan tertentu dan mudah untuk di implementasikan.
> Struktur Data Non Linier -> struktur data ini memiliki elemen - elemen yang tidak berada dalam urutan apa pun.    Struktur data ini disusun secara hierarkis yang dimana 1 elemen akan terhubung ke satu atau lebih pada elemen tersebut.

Nah gengs karena kita sudah mempelajari semua struktur data linier, kali ini kita akan mempelajari struktur data non linier. Didalam struktur data non linier ada 3 materi yaitu "Graph", "Tree", dan "Map/Hash Table".

Beberapa "Graph" yang populer yaitu:
- Spanning Tree and Minimum Spanning Tree.
- Strongly Connected Components.
- Adjacency Matrix.
- Adjacency List.

Beberapa "Tree" yang populer yaitu:
- Binary Tree.
- Binary Search Tree.
- AVL Tree.
- B- Tree.
- B+ Tree.
- Red-Black Tree. [1]

#### GRAPH:
Graph = jenis struktur data yang terdiri dari berbagai node yang saling terhubung. Node pada jenis ini disebut "simpul", yang dimana akan ada garis yang menghubungkan dari setiap simpul tersebut. Graph menggambarkan suatu kumpulan objek yang dimana pasangan dari objek tersebut terhubung oleh sebuah link. [2]

Ada 4 macam Graph:
- Graf Tak Berarah -> graf yang sisi - sisinya tidak mengarah ke sembarang arah (sisi - sisinya dua arah).
- Graf Berarah -> graf yang sisi - sisinya mengarah ke arah tertentu. [1]
- Graf Terhubung (directed graph) -> graf yang selalu ada lintasan dari suatu simpul ke simpul lainnya dan terhubung ke semua simpul.
- Graf Tak Terhubung (undirected graph) -> graf yang tidak ada di lintasan simpul tersebut dan tidak semua simpul terhubung dengan garis. 
Note = jika sebuah simpul tidak terhubung ke semua simpul lainnya, disebut "isolated vertex". [2]

#### TREE:
Tree = salah satu jenis struktur data non linear yang memiliki pola seperti pohon. Jenis ini termasuk ke dalam data hierarkis, karena sering digunakan untuk menyimpan dan menyusun data di berbagai levelnya dan disebut dengan kumpulan node yang saling terhubung. [2]

Ada 2 macam Tree:
- Spanning Tree (Pohon Merentang) -> sub graf dari graf terhubung tak berarah, yang mencakup semua simpul dari graf dengan jumlah tepi seminimal mungkin.
Note = jika sebuah simpul terlewatkan, maka itu bukan pohon merentang, dan banyaknya pohon merentang dengan n simpul-simpul yang dapat dibuat dari suatu graf lengkap.

- Minimum Spanning Tree -> pohon merentang minimum dari suatu graf ditemukan menggunakan algoritma, yaitu "Algoritma Prim" = algoritma yang menggunakan graf sebagai input dan menemukan himpunan bagian dari sisi - sisi graf tersebut yang membentuk pohon yang mencakup setiap simpulnya. "Algoritma Kruskal" = algoritma pohon merentang minimum yang mengambil graf sebagai input, dan menemukan himpunan bagian dari sisi - sisi graf tersebut yang membentuk pohon, yang mencakup setiap simpulnya dan memiliki jumlah bobot minimum diantara pohon yng dapat dibentuk dari grafik. [1]

~*Binary tree ialah salah satu istilah yang sering digunakan dalam struktur data ini, karena setiap node memiliki paling banyak dua child = "left child" dan "right child. binary tree sering untuk implementasi menggunakan link.

> Istilah - istilah yang terdapat dalam jenis struktur data ini:
- Root -> node yang terletak dibagian paling atas.
- Child node -> turunan dari setiap node.
- Parent node -> node yang berisi child node/sub node.
- Siblings -> node yang asalnya dari parent node yang sama.
- Leaf node -> node yang tidak memiliki keturunan lagi.
- Internal node -> simpul yang memiliki minimal satu chid node.
- Edge -> garis yang menghubungkan antara 2 buah simpul dalam tree.
- Height of node -> jumlah edge dari sebuah node ke leaf node yang paling dalam.
- Depth of node -> banyaknya edge dari root ke sebuah node.
- Height of tree -> panjang jalur terpanjang dari root node ke leaf node sebuah tree.
- Degree of node -> jumlah cabang yang melekat pada simpul.
- Subtree -> setiap simpul  dari tree beserta turunannya. [2]

## Guided 

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] ={
    (0,7,0,0,0,0,0),
    (0,0,5,0,0,15,0),
    (0,0,0,0,5,0,0),
    (0,5,0,0,2,4,0),
    (23,0,0,10,0,0,0),
    (0,0,0,0,7,0,3),
    (0,0,0,0,9,4,0),
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << ":" ;
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

Interpretasi:
Program diatas adalah program untuk menampilkan graf yang berbentuk matriks dan menggambarkan koneksi antar kota di Jawa Barat dan Yogyakarta. Tujuan program ini dibuat supaya pembaca dapat memahami materi Graph ini, dan mengetahui bahwa graf bisa untuk menggambarkan koneksi antar kota di Jawa Barat dan Yogyakarta.

Kode diatas memiliki beberapa fungsi, seperti:
- "string simpul[7]" -> menggunakan string karena untuk menyimpan nama - nama kota. Simpul 7 artinya program graph diatas memiliki 7 buah simpul, yaitu ciamis, bandung, bekasi, tasikmalaya, cianjur, purwokerto, dan yogyakarta.
- "int busur[7][7]" -> menggunakan integer karena untuk menunjukkan jarak perjalanan antar kota. Seperti, ciamis memiliki hubungan jarak dengan purwokerto, bandung tidak memiliki hubungan jarak dengan kota lain, begitupun seterusnya..
- "void tampilGraph" -> untuk menampilkan graph yang telah dibuat.

#### Output:
![Screenshot 2024-06-10 154035](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/97768fad-818c-4812-a4c0-ddaabd1f233b)

```C++
#include<iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder (node -> left);
        cout << node -> data << " ";
        inOrder(node -> right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven -> left = one;
    // 7
    // /\
    // 1 NULL

    seven -> right = nine;
    // 7
    // /\
    // 1 9

    one -> left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one -> right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine -> left = eight;
    // 7
    // /\
    // 1 9
    // / \ / \
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```

Interpretasi:
Program diatas adalah program untuk membentuk sebuah pohon dengan memiliki urutan pre order, in order, post order. Tujuan program ini dibuat supaya pembaca dapat memahami materi Tree ini, dan mengetahui bahwa materi ini pasti berstruktur. 

Kode - kode di dalam program tersebut:
- "TNode", fungsi ini memiliki 3 bagian yaitu data, left, dan right. Nah 3 bagian itu memiliki fungsinya masing-masing seperti, data -> untuk menyimpan nilai integer, left dan right memiliki kesamaan fungsi -> yaitu sama - sama memiliki pointer yang menunjukkan node anak dari node  saat ini.
- "preorder", menggunakan data - left - right untuk menampilkan node - node pada pohon.
- "inorder", menggunakan left - data - right  untuk menampilkan node - node pada pohon, dan
- "postorder", menggunakan left - right - data  untuk menampilkan node - node pada pohon.

#### Output:
![Screenshot 2024-06-10 154057](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/30899e00-7006-49c6-8761-5e82a8ba0503)


## Unguided 

### [1]. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Graph {
    vector<string> simpul_graph;
    vector<vector<int>> bobot_graph;
};

int main() {
    int jumlah_simpul;
    int nama_2311110018;
    
    cout << "Masukkan Jumlah Simpul: ";
    cin >> jumlah_simpul;
    
    Graph graf;
    graf.simpul_graph.resize(jumlah_simpul);
    graf.bobot_graph.resize(jumlah_simpul, vector<int>(jumlah_simpul));
    
    cout << "Masukkan Nama Simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> graf.simpul_graph[i];
    }
    
    cout << "Masukkan Bobot Antar Simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << graf.simpul_graph[i] << "-->" << graf.simpul_graph[j] << " = ";
            cin >> graf.bobot_graph[i][j];
        }
    }
    
    
    cout << "\t";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << graf.simpul_graph[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << graf.simpul_graph[i] << "\t";
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << graf.bobot_graph[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
```

Interpretasi:
Program diatas adalah program untuk membuat graph, yang dimana dalam graph tersebut terdapat simpul dan bobot graph. Tujuan program ini dibuat supaya pembaca dapat memahami materi Graph ini, dan mengetahui bahwa graf bisa untuk menggambarkan koneksi antar pulau di Palu dan di Bali.

Cara kerja program diatas = cara kerjanya yaitu pertama kita masukkan terlebih dahulu jumlah simpulnya yaitu (2), lalu kita masukkan nama simpul 1 (BALI) dan simpul 2 (PALU), setelah itu tentukan bobot antar simpul, bobot ini di ibaratkan dengan titik jarak wilayah A dengan wilayah B, seperti wilayah BALI - BALI = 0, BALI - PALU = 3, PALU - BALI = 4, dan PALU - PALU = 0. Nah selesai deh, setelah itu bobot akan membentuk sebuah matriks, jadi kita tahu bahwa jarak dari BALI - PALU yaitu 3, dan PALU - BALI = 4, sedangkan PALU - PALU = 0 dan BALI - BALI = 0, karena ya di ibaratkan titik wilayah A bertemu dengan A jadi 0, begitupun dengan wilayah B bertemu dengan B jadi 0 juga.

Kode diatas memiliki beberapa fungsi, seperti:
- "simpul_graph" -> sebuah vektor string yang bisa untuk  menyimpan nama - nama dalam simpul graf tersebut.
- "bobot_graph" -> sebuah vektor integer yang bisa untuk menyimpan bobot - bobot dalam simpul graf tersebut.


#### Output:
![Screenshot 2024-06-09 210232](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/96d10243-1e0a-40d0-914b-2f4dfd9d2086)

#### Full ScreenShoot:
![Screenshot 2024-06-09 210337](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/6b0848f9-7f5b-4f15-a65b-8431452a49de)

### [2]. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

class Tree {
private:
    Node* root;

    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    Node* findNode(Node* node, const string& value) {
        if (node == nullptr) return nullptr;
        if (node->data == value) return node;
        Node* foundNode = findNode(node->left, value);
        if (foundNode == nullptr) {
            foundNode = findNode(node->right, value);
        }
        return foundNode;
    }

    void printChildren(Node* node) {
        if (node->left) {
            cout << "Left child: " << node->left->data << endl;
        } else {
            cout << "Left child: None" << endl;
        }
        if (node->right) {
            cout << "Right child: " << node->right->data << endl;
        } else {
            cout << "Right child: None" << endl;
        }
    }

    void printDescendants(Node* node) {
        if (node == nullptr) return;
        queue<Node*> q;
        q.push(node);
        bool hasDescendants = false;
        cout << "Descendants of " << node->data << ": ";
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current != node) {
                cout << current->data << " ";
                hasDescendants = true;
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        if (!hasDescendants) {
            cout << "None";
        }
        cout << endl;
    }

public:
    Tree() : root(nullptr) {}

    void insertRoot(const string& value) {
        if (root == nullptr) {
            root = new Node{value, nullptr, nullptr};
            cout << "Root node " << value << " berhasil ditambahkan." << endl;
        } else {
            cout << "Root Tersedia." << endl;
        }
    }

    void insertLeftChild(const string& parent, const string& leftChild) {
        Node* parentNode = findNode(root, parent);
        if (parentNode == nullptr) {
            cout << "Parent node tidak tersedia." << endl;
            return;
        }
        if (leftChild != "None") {
            if (parentNode->left == nullptr) {
                parentNode->left = new Node{leftChild, nullptr, nullptr};
            } else {
                cout << "Left child tersedia untuk " << parent << endl;
            }
        }
    }

    void insertRightChild(const string& parent, const string& rightChild) {
        Node* parentNode = findNode(root, parent);
        if (parentNode == nullptr) {
            cout << "Parent node tidak tersedia." << endl;
            return;
        }
        if (rightChild != "None") {
            if (parentNode->right == nullptr) {
                parentNode->right = new Node{rightChild, nullptr, nullptr};
            } else {
                cout << "Right child tersedia untuk " << parent << endl;
            }
        }
    }

    void findAndPrintNode(const string& value) {
        Node* node = findNode(root, value);
        if (node != nullptr) {
            cout << "Node ditemukan: " << node->data << endl;
            printChildren(node);
        } else {
            cout << "Node tidak ditemukan." << endl;
        }
    }

    void preOrderTraversal() {
        cout << "PreOrder Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal() {
        cout << "InOrder Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal() {
        cout << "PostOrder Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }

    void printChildren(const string& value) {
        Node* node = findNode(root, value);
        if (node != nullptr) {
            printChildren(node);
        } else {
            cout << "Node tidak tersedia." << endl;
        }
    }

    void printDescendants(const string& value) {
        Node* node = findNode(root, value);
        if (node != nullptr) {
            printDescendants(node);
        } else {
            cout << "Node tidak tersedia." << endl;
        }
    }
};

int main() {
    Tree tree;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Data untuk root node\n";
        cout << "2. Tambah left child\n";
        cout << "3. Tambah right child\n";
        cout << "4. Find node\n";
        cout << "5. PreOrder Traversal\n";
        cout << "6. InOrder Traversal\n";
        cout << "7. PostOrder Traversal\n";
        cout << "8. Print Child\n";
        cout << "9. Print Descendants\n";
        cout << "10. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        string value, leftChild, rightChild;
        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk root node: ";
                cin >> value;
                tree.insertRoot(value);
                break;
            case 2:
                cout << "Masukkan nama parent node: ";
                cin >> value;
                cout << "Masukkan nama left child: ";
                cin >> leftChild;
                tree.insertLeftChild(value, leftChild);
                break;
            case 3:
                cout << "Masukkan nama parent node: ";
                cin >> value;
                cout << "Masukkan nama right child: ";
                cin >> rightChild;
                tree.insertRightChild(value, rightChild);
                break;
            case 4:
                cout << "Masukkan nama node yang dicari: ";
                cin >> value;
                tree.findAndPrintNode(value);
                break;
            case 5:
                tree.preOrderTraversal();
                break;
            case 6:
                tree.inOrderTraversal();
                break;
            case 7:
                tree.postOrderTraversal();
                break;
            case 8:
                cout << "Masukkan node yang ingin dicetak child-nya: ";
                cin >> value;
                tree.printChildren(value);
                break;
            case 9:
                cout << "Masukkan nama node yang ingin dicetak descendants-nya: ";
                cin >> value;
                tree.printDescendants(value);
                break;
            case 10:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 10);

    return 0;
}
```

Interpretasi:
Program diatas adalah program untuk membuat Binary Tree, yang dimana struktur data ini memiliki node - node yang saling terhubung pada setiap node. Tujuan program ini dibuat supaya pembaca dapat memahami materi Tree ini, dan mengetahui bahwa Tree bisa memiliki 2 arah yaitu, left dan right.

Cara kerja program diatas = cara kerjanya yaitu pertama kita masukkan terlebih dahulu nomer yang ada dimenu tersebut, lalu masukkan daerah - daerah yang ingin kalian buat pohon, setelah semua selesai klik menu 10 yaitu exit.

Kode diatas memiliki beberapa fungsi, seperti:
- "insert root" -> untuk menambahkan node root pada binary tree.
- "Insert Left Child" -> untuk menambahkan arah kiri dari sebuah node dalam binary tree.
- "Insert Right Child" -> untuk menambahkan arah kanan dari sebuah node dalam binary tree.
- "Find Node" -> untuk mencari node yang ada didalam binary tree
- "Print Descendants" -> untuk mencetak bawahan dari node tersebut.

#### Output:

![Screenshot 2024-06-10 153701](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/a5774b81-3056-4c28-99f2-702a1a16e155)

#### Full ScreenShoot:
![Screenshot 2024-06-10 153720](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/2120cdc5-03be-4e96-91f9-3574ab45089c)

## Kesimpulan :
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang "Graph and Tree" dalam struktur data pemrograman. 
Graph merupakan struktur data yang terdiri dari simpul - simpul (vertex) yang terhubung oleh sisi (edge). Sedangakn Tree merupakan struktur data yang terdiri dari simpul - simpul yang saling terhubung secara hierarkis.

Saya mendapatkan ilmu baru dan pelajaran dari laporan tersebut. Dari laporan diatas kita bisa menyimpulkan bahwa Graph dan Tree masuk ke dalam struktur data pemrograman non linear, karena struktur data ini memiliki elemen - elemen yang tidak berada dalam urutan apa pun. 

## Referensi :
[1] STRUKTUR DATA DAN IMPLEMENTASI ALGORITMA (SDIA) Pemrograman Python C C++ Java By ZAYID MUSIAFA · 2022.
Google Books. (n.d.). https://www.google.co.id/books/edition/STRUKTUR_DATA_DAN_IMPLEMENTASI_ALGORITMA/6Q1pEAAAQBAJ?hl=en&gbpv=1&dq=materi+graph+and+tree+dalam+struktur+data&pg=PA17&printsec=frontcover

[2] DASAR PEMROGRAMAN : Teori & Aplikasi
By Oki Arifin, Fathurrahman Kurniawan Ikhsan, Randi Farmana Putra, Fitriani Nur Utami, Ari Kusuma Wardana, Erika Fahmi Ginting, Meriska Defriani, Achmad Zulfajri Syaharuddin, Kartikadyota Kusumaningtyas, Dewi Kania Widyawati, Henry Kurniawan, Haris Kurniawan · 2023. 
Google Books. (n.d.-b). https://www.google.co.id/books/edition/DASAR_PEMROGRAMAN_Teori_Aplikasi/HZnCEAAAQBAJ?hl=en&gbpv=1&dq=materi+graph+and+tree+dalam+struktur+data&pg=PA52&printsec=frontcover