#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseSentence(string sentence) {
    stack<char> characters;
    for (char c : sentence) {
        characters.push(c);
    }

    while (!characters.empty()) {
        cout << characters.top();
        characters.pop();
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Kalimat: " << kalimat << endl;

    cout << "Hasil: ";
    reverseSentence(kalimat);

    return 0;
}