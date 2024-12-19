#include <iostream>
using namespace std;
void printTable(int number, int start, int end) {
    cout << "Multiplication table of " << number << " from " << start << " to " << end << ":" << endl;
    for (int i = start; i <= end; ++i) {
        cout << number << " * " << i << " = " << number * i << endl;
    }
}
int main() {
    int num, startRange, endRange;
    cout << "Enter the number for the multiplication table: ";
    cin >> num;
    cout << "Enter the start range: ";
    cin >> startRange;
    cout << "Enter the end range: ";
    cin >> endRange;
    if (startRange > endRange) {
        cout << "Invalid range! The start range cannot be greater than the end range." << endl;
    } else {
        printTable(num, startRange, endRange);
    }
    return 0;
}
