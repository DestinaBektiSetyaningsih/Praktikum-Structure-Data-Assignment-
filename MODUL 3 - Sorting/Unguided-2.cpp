#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string nama[], int x) {
    for(int y = 0; y < x-1; y++) {
        for(int z = 0; z < x-y-1; z++) {
            if(nama[z] > nama[z+1]) {
                swap(nama[z], nama[z+1]);
            }
        }
    }
}

int main() {
    string nama[] = {"Siti", "Situ", "Sana", "Ana", "Ani", "Caca", "Cici", "Dida", "Dodo", "Dadi"};
    int x = sizeof(nama)/sizeof(nama[0]);

    bubbleSort(nama, x);

    cout << "10 Nama warga Pak RT setelah diurutkan: ";
    for(int y = 0; y < x; y++) {
        cout << nama[y] << " ";
    }
    cout << endl;

    return 0;
}