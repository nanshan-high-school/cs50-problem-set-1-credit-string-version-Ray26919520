#include <iostream>
using namespace std;

int main() {
    string StringNumber;
    cout << "請輸入卡號：";
    cin >> StringNumber;
    int i = 0;
    int num[i];
    int len = StringNumber.length();
    int evensum = 0;
    int oddsum = 0;
    bool even = false;
    if (len == 16) {
        even = !even;
    }
    for (i = 0; StringNumber[i] != '\0'; i++) {
        num[i] = StringNumber[i] - '0';
        if (even) {
            int now = num[i] * 2;
            evensum = evensum + (now % 10) + (now / 10);
        } else {
            oddsum = oddsum + num[i];
        }
        even = !even;
    }
    int checksum = evensum + oddsum;
    if (checksum % 10 != 0) {
        cout << "錯誤卡號~";
        return 0;
    }
    if (len == 15 && num[0] == 3 && num[1] >= 4 && num[1] <= 7) {
        cout << "American Express";
    } else if (len == 16 && num[0] == 5 && num[1] >= 1 && num[5] <= 5) {
        cout << "MasterCard";
    } else if (len == 16 && num[0] == 4) {
        cout << "Visa";
    } else if (len == 13 && num[0] == 4) {
        cout << "Visa";
    } else {
        cout << "錯誤卡號~/n";
    }
}
