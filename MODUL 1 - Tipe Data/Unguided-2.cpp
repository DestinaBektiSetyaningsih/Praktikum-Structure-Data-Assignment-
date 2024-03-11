#include <iostream>
using namespace std;

struct Kulkas{
    string minuman;
    string makanan;
    int jumlah;
};

int main(){
    Kulkas isi;
    isi.minuman = "yogurt";
    isi.makanan = "steak";
    isi.jumlah = 5;

    cout << "\naku mempunyai " << isi.jumlah << "kulkas";
    cout << "\nkulkas aku berisi" << isi.makanan;
    cout << "\nkulkas aku berisi" << isi.minuman << endl <<

endl;
    return 0;
}