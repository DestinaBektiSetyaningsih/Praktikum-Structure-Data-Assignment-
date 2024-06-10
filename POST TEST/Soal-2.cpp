// Tulislah fungsi rekursif yang menerima sebuah bilangan bulat dan mengembalikan nilai faktorial dari n.

#include <iostream>
using namespace std;

int faktorial!() {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}

int main () {
    int num;
    cout << "masukkan bilangan bulat: " ;
    cin >> (num);

    cout << "bilangan bulat" << (num) << "adalah" << endl;
}
