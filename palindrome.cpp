#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (!isalnum(str[left])) {
            left++;
        } else if (!isalnum(str[right])) {
            right--;
        } else {
          
            if (tolower(str[left]) != tolower(str[right])) {
                return false;
            }
            left++;
            right--;
        }
    }
    return true; 
}
int main() {
    string input;
    cout << "Enter a string to check if it's a palindrome: ";
    getline(cin, input);
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome!" << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }
    return 0;
}
