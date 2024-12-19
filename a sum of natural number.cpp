#include <iostream>
using namespace std;
int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}
int sumRecursive(int n) {
    if (n == 0) {
        return 0; 
    }
    return n + sumRecursive(n - 1); 
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n < 0) {
        cout << "Please enter a positive integer!" << endl;
        return 1; 
    }
    int sumIter = sumIterative(n);
    cout << "Sum of first " << n << " natural numbers (iteratively): " << sumIter << endl;
    int sumRec = sumRecursive(n);
    cout << "Sum of first " << n << " natural numbers (recursively): " << sumRec << endl;
    return 0;
}

