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
                cout << arr[a][b][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}