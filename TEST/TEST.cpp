#include <iostream>
#include <string>
#include <map>
using namespace std;

// 아라비아 숫자를 로마 숫자로 변환하는 함수
string toRoman(int num) {
    string result = "";
    map<int, string, greater<int>> romanMap = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    for (auto const& pair : romanMap) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    return result;
}

// 로마 숫자를 아라비아 숫자로 변환하는 함수
int toArabic(string s) {
    int result = 0;
    map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && romanMap[s[i]] > romanMap[s[i - 1]]) {
            result += romanMap[s[i]] - 2 * romanMap[s[i - 1]];
        }
        else {
            result += romanMap[s[i]];
        }
    }
    return result;
}

int main() {
    char input;
    while (true) {
        cout << "1. 로마 숫자를 아라비아 숫자로 변환하기" << endl;
        cout << "2. 아라비아 숫자를 로마 숫자로 변환하기" << endl;
        cout << "ESC를 누르면 종료합니다." << endl;
        cin >> input;
        if (input == 27) {  // ESC 키 입력
            break;
        }
        else if (input == '1') {  // 로마 숫자를 아라비아 숫자로 변환
            string roman;
            cout << "로마 숫자를 입력하세요 (1~3999까지): ";
            cin >> roman;
            int arabic = toArabic(roman);
            if (arabic == 0) {
                cout << "잘못된 입력입니다." << endl;
            }
            else {
                cout << roman << " = " << arabic << endl;
            }
        }
        else if (input == '2') {  // 아라비아 숫자를 로마 숫자로 변환
            int arabic;
            cout << "아라비아 숫자를 입력하세요 (1~3999까지): ";
            cin >> arabic;
            if (arabic < 1 || arabic > 3999) {
                cout << "잘못된 입력입니다." << endl;
            }
            else {
                string roman = toRoman(arabic);
                cout << arabic << " = " << roman << endl;
            }
        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }
    }
}