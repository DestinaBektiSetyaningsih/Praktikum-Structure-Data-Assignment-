# <h1 align="center">Laporan Praktikum Modul Priorty Queue dan Heaps</h1>
<p align="center">Destina Bekti Setyaningsih (2311110018) / Sains Data</p>

## Dasar Teori
Priority Queue & Heaps

Nah gengs kalian tau gak nih, kalo disebuah antrian, pasti ada antrian khusus untuk prioritas bukan? kayak VVIP gitu hehehe... 

Nah ternyata VVIP antrian ada di materi Ilmu Komputer lho!. Yap nama materi ini ialah "Priority Queue". Apa itu Priority Queue? 

Priority Queue adalah jenis antrian yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi biasanya diambil sebelum elemen dengan nilai prioritasnya yang lebih rendah. 

Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Saat kita akan menambahkan elemen ke antrean, elemen tersebut dimasukkan ke dalam posisi yang dimana posisi tersebut berdasarkan nilai prioritasnya. 

Antrean prioritas sering digunakan dalam sistem real-time, yang dimana urutan pemrosesan elemen dapat memiliki konsekuensi yang signifikan. Priority queue juga memiliki perpanjangan dari queue, seperti :
- setiap item memiliki prioritas yang terkait dengannya.
- elemen dengan prioritas tinggi di-dequeud sebelum elemen dengan prioritas rendah.
- jika dua elemen memiliki prioritas yang sama, mereka dilayani sesuai urutan dalam antriannya.

> Metode Dalam Priority Queue:
- Push() -> digunakan untuk memasukkan elemen baru ke dalam antrian dengan memperhatikan prioritasnya.
- Pop() -> digunakan untuk menghapus elemen dengan prioritas tertinggi. 
- Size() -> digunakan untuk mendapatkan jumlah elemen yang saat ini ada dalam antrian.
- Empty -> digunakan untuk mengetahui apakah antrian tersebut kosong atau tidak.
- Top() -> untuk merujuk pada elemen dengan prioritas tertinggi yang ada dalam priority queue.
- Swap() -> digunakan untuk proses menukar 2 elemen yang berbeda posisi dalam priority queue.
- Emplace() -> digunakan untuk menambahkan elemen baru ke dalam priority queue dengan menggunakan nilai yang diberikan untuk membuat elemen baru pada saat penambahan.

> Jenis Priorty Queue:
- Ascending Order Priority Queue -> elemen dengan nilai prioritas lebih rendah diberikan prioritas lebih tinggi dalam daftar prioritas.
- Descending Order Priority Queue -> elemen maksimum dalam tumpukan maksimum. [1].

Heap adalah sebuah binary tree
> Tree harus complete binary tree
- Semua level tree mempunyai simpul maksimum kecuali pada level terakhir.
- Pada level terakhir, node tersusun dari kiri ke kanan tanpa ada yang dilewati.

> Perbandingan nilai suatu node dengan nilai node child-nya mempunyai ketentuan berdasarkan jenis heap 
- Max heap mempunyai ketentuan bahwa nilai suatu node lebih besar atau sama dengan (>=) dari nilai childnya.
- Min heap mempunyai ketentuan bahwa nilai suatu node lebih kecil atau sama dengan (<=) dari nilai childnya.

Suatu heap dapat sewaktu - waktu berubah baik itu penambahan elemen (insert) dan penghapusan elemen (delete). [2].

Heap Sort adalah algoritma pengurutan data berdasarkan perbandingan, dan termasuk golongan selectin sort.
Walaupun lebih lambar daripada Quick Sort pada kebanyakan mesin, tetapi Heap Sort mempunyai keunggulan yaitu kompleksitas algoritma pada kasus terburuk = n log n. 

> Ada Beberapa Operasi yang Dapat Terjadi diSebuah Heap, yaitu;
1. Delete-max atau delete-min -> menghapus simpul akar dari sebuah max heap atau min heap.
2. Increase-key atau decrease-key -> mengubah nilai yang tersimpan di suatu simpul.
3. Insert -> menambahkan sebuah nilai ke dalam heap.
4. Merge -> menggabungkan 2 heap untuk membentuk sebuah heap baru yang berisi semua elemen pembentuk heap tersebut.

> Jenis - Jenis Heap:
a. Binary heap -> heap yang dibuat dengan menggunakan pohon binner.
b. Binomial Heap -> heap yang dibuat dengan menggunakan pohon binomial.
c. Fibonacci Heap -> kumpulan pohon yang membentuk minimum heap. [3].

## Guided 
```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1) ;
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i =parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority : " << extractMax() << "\n";

    cout << "Priority Queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changePriority(2, 49);
    cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);
    cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-05-19 223926](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/7217fc1a-2e4b-473f-bad4-a882010e13b9)

#### Screenshoot Full:
![Screenshot 2024-05-19 224010](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/b69d41f8-601e-4d63-a1fa-0e7bb229d912)

Interpretasi:
Program diatas adalah program "priority queue" dan program "heaps". Tujuan program ini dibuat untuk mengetahui elemen mana yang menjadi priority queue. Selain itu tujuan lainnya supaya pengguna memahami fungsi dari materi ini. Cara kerjanya yaitu, menujukkan bahwa antrian prioritas di nomer urut 45, lalu nomer urut 45 adalah antrian yang maksimal, lalu antrian maksimal nomer 45 di extracting, selanjutnya antrian nomer urut 45 diubah menjadi nomer urut 49, setelah itu urutkan.

fungsi kode diatas:
- "parent" -> untuk mengembalikkan nilai dari induk elemen ke 1
- "leftchild" -> untuk mengembalikkan nilai dari kiri ke 1.
- "rightchild" -> untuk mengembalikkan nilai dari kanan ke 1.
- "shiftup" -> untuk memindahkan elemen (i) ke atas, nilai (i) > nilai prioritas induknya.
- "shiftdown" -> untuk memindahkan elemen (i) ke bawah. 

## Unguided 

### [1]. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
  return (i - 1) / 2;
}

int leftChild(int i) {
  return ((2 * i) + 1);
}

int rightChild(int i) {
  return ((2 * i) + 2);
}

void shiftUp(int i) {
  while (i > 0 && H[parent(i)] < H[i]) {
    swap(H[parent(i)], H[i]);
    i = parent(i);
  }
}

void shiftDown(int i) {
  int maxIndex = i;
  int l = leftChild(i);
  if (l <= heapSize && H[l] > H[maxIndex]) {
    maxIndex = l;
  }
  int r = rightChild(i);
  if (r <= heapSize && H[r] > H[maxIndex]) {
    maxIndex = r;
  }
  if (i != maxIndex) {
    swap(H[i], H[maxIndex]);
    shiftDown(maxIndex);
  }
}

void insert(int p) {
  heapSize++;
  H[heapSize] = p;
  shiftUp(heapSize);
}

int extractMax() {
  int result = H[0];
  H[0] = H[heapSize];
  heapSize--;
  shiftDown(0);
  return result;
}

void changePriority(int i, int p) {
  int oldp = H[i];
  H[i] = p;
  if (p > oldp) {
    shiftUp(i);
  } else {
    shiftDown(i);
  }
}

int getMax() {
  return H[0];
}

void remove(int i) {
  H[i] = getMax() + 1;
  shiftUp(i);
  extractMax();
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  cout << "Enter " << n << " elements ";
  for (int i = 0; i < n; ++i) {
    int element;
    cout << "Enter a number for the element " << i + 1 << ": ";
    cin >> element;
    insert(element);
  }

  cout << "Priority Queue: ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << endl;

  cout << "Node with maximum priority: " << extractMax() << endl;

  cout << "Priority queue after extracting maximum: ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << endl;

  changePriority(0, 15);
  cout << "Priority queue after priority change: ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  cout << endl;

  remove(11)
  );
  cout << "Priority queue after removing the element: ";
  for (int i = 0; i <= heapSize; ++i) {
    cout << H[i] << " ";
  }
  return 0;
}

```
#### Output:
![Screenshot 2024-05-19 235440](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/4810ae94-336e-4316-bcfc-3a5c09c7a0d9)

#### Screenshoot Full:
![Screenshot 2024-05-19 235502](https://github.com/DestinaBektiSetyaningsih/Teory-Structure-Praktikum-Assignment-/assets/162566980/b032da09-88f6-4cff-a461-ac5487cf74b6)


Interpretasi:
Program diatas adalah program untuk mengecek nomer mana yang akan menjadi antrian khusus tersebut. tujuan program ini dibuat supaya pengguna memahami materi "priority queue" dan "heaps". Contoh kerjanya yaitu ketika kita ingin menambah elemen dengan nilai prioritas yang tinggi ke antrian prioritas, elemen tersebut dapat disisipkan di dekat bagian depan antrean, sedangkan elemen dengan nilai prioritas rendah dapat disisipkan dibagian belakang.

Fungsi kode diatas :
- "Insert" -> untuk memasukkan elemen baru dengan prioritas P.
- "ExtracMax" -> untuk menghapus elemen dengan prioritas tertinggi dari struktur heap dan mengembalikkan nilai prioritasnya.
- "ChangePriority" -. untuk mengubah prioritas.
- "getMax" -> untuk mengembalikkan nilai prioritas elemen dengan prioritas tertinggi.
- "Remove" -> untuk menghapus elemen. 

Penjelasan Output:
Program diatas memiliki 12 element, lalu tentukan element 12 untuk menjadi element yang pertama itu mau nomer berapa gitu, lalu tentukan nomer mulai dari element 2 = no 1, element 3 = no 2, element 4 = 3, dst sampai dengan element 12 = no 11, setelah itu urutkan prioritas antrian tersebut, dan kita tahu bahwa antrian prioritas pertama ialah nomer 15, selanjutnya nomer 15 adalah nomer maksimum yang ada di antrian prioritas tersebut, dan terakhir terjadi perubahan dan penghapusan antrian tersebut yang mengakibatkan 1 nomer hilang/kehapus. 

## Kesimpulan :
Laporan ini disusun dengan tujuan untuk memahami konsep dasar tentang "Priority Queue" dan "Heaps" dalam pemrograman. Priority Queue adalah struktur data queue yang dimana data tersebut akan memiliki beberapa prioritas yang telah ditentukan.Cara kerja priority queue yaitu, setiap elemen memiliki prioritas tertentu, elemen tersebut ysng memiliki prioritas tertinggi akan diambil terlebih dahulu.

Sedangkan Heaps adalah struktur data yang berbntuk pohon yang memenuhi sifat - sifat heap, yaitu jika S adalah anak dari B, maka nilai yang tersimpan di data B > atau = nilai yang tersimpan di dat S.

Heap memiliki 3 akar, yaitu:
- Complete Binary Tree (CBT).
- Max Heap -> nilai simpul dari (>=) nilai anaknya, sehingga nilai paling besar selalu berada di rootnya.
- Min Heap -> nilai simpul dari (<=) nilai anaknya, sehiingga nilaipaling kecil selalu berada di tootnya. 

## Referensi :
[1] Web Scribd
https://id.scribd.com/document/517079990/STACK-QUEUE-PRIORITY-QUEUE


[2] Repository Unikom
https://repository.unikom.ac.id/36115/1/Bab%20XI%20-%20Heap.pdf


[3] Makalah anak ITB
https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-046.pdf

