#include <iostream>

using namespace std;

int functionA(int n);
int functionB(int n);

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Input tidak valid. Silakan masukkan bilangan bulat positif." << endl;
    } else {

        int hasil = functionA(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}

int functionA(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * functionB(n - 1);
    }
}

int functionB(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * functionA(n - 1);
    }
}