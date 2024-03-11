#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int>skincare;

    skincare["glowing"] = 500000;
    skincare["acne"] = 350000;
    skincare["brightening"] = 200000;

    cout << "\nTipe Skincare Glowing memiliki harga :" <<
skincare["glowing"];
    cout << "\nTipe Skincare Acne memiliki harga :" <<
skincare["acne"];
    cout << "\nTipe Skincare Brightening memiliki harga :" <<
skincare["brightening"];

    string Destina;
    cout << "\n\nCek Tipe Skincare: "; cin >> Destina;
    if(skincare.find(Destina) != skincare.end()){
        cout << "\nStok Tersedia, Silahkan Tanya Penjual " << 
endl;
    } else{
    cout << "\nStok Tidak Tersedia, Silahkan mengikuti pre order." << endl;
    }
    return 0;
}
