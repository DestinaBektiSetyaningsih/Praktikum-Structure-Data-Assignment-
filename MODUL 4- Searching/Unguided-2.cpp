#include <iostream>
#include <string>

using namespace std;

int isVowel(char ch) {
    ch = tolower(ch); 
    return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

int countVowels(const string& sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}