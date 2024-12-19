#include <iostream>
using namespace std;
void passByValue(int a) {
    static int value = 13;
    cout << "Pass by Value: " << endl;
    cout << "Before modification: a = " << a << ", static value = " << value << endl;
    a = 40;  
    value = 10; 
    cout << "After modification: a = " << a << ", static value = " << value << endl;
}
void passByReference(int &b) {
    static int value = 20; 
    cout << "Pass by Reference: " << endl;
    cout << "Before modification: b = " << b << ", static value = " << value << endl;
    b = 90;  
    value = 30; 
    cout << "After modification: b = " << b << ", static value = " << value << endl;
}
int main() {
    int x = 3;
    int y = 7;
    passByValue(x);
    cout << "In main after passByValue: x = " << x << endl;
    passByReference(y);
    cout << "In main after passByReference: y = " << y << endl;
    return 0;
}
