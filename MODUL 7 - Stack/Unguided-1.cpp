#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& sentence) {
    std::stack<char> charStack;
    std::string str = sentence;

    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (char c : str) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        if (charStack.top() != str.back()) {
            return false;
        }
        charStack.pop();
        str.pop_back();
    }

    return true;
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

if (isPalindrome(kalimat)) {
    std::cout << "Kalimat tersebut adalah polindrom" << std::endl;
} else {
    std::cout << "Kalimat tersebut bukan polindrom" << std::endl;
}
return 0;
}