#include <iostream>
#include <vector>

using namespace std;

int countFours(const vector<int>& data) {
    int count = 0;
    for (int num : data) {
        if (num == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

    int jumlahEmpat = countFours(data);

    cout << "Jumlah angka 4 dalam data adalah: " << jumlahEmpat << endl;

    return 0;
}
