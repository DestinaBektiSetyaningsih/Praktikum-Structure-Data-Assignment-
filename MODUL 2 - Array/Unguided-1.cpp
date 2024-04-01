#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int a;
    // Meminta pengguna untuk memasukkan jumlah array
    cout << "Masukkan nilai array: ";
    cin >> a;
    // Deklarasi array dengan ukuran a
    int arr[a];

    // Input array
    cout << "Masukkan " << a << " angka\n";
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke - " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;

    // Output data array
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
