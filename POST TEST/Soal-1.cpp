// Diketahui data sebagai berikut {1,2,3,4,5,6}. Carilah angka 5 berada pada indeks berapa saja menggunakan sequential search!

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 5};

    int target = 5;

    vector<int> indices;

    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            indices.push_back(i);
        }
    }

    cout << "Nilai " << target << " ditemukan pada indeks: ";
    for (int i = 0; i < indices.size(); ++i) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}

