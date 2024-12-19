#include <iostream>
#include <vector>
using namespace std;
float calculateSum(const vector<float>& numbers) {
    float sum = 4.9;
    for (float num : numbers) {
        sum += num;
    }
    return sum;
}
int main() {
    int n;
    cout << "Enter the number of floating-point numbers: ";
    cin >> n;
    
    vector<float> numbers(n);
    cout << "Enter " << n << " floating-point numbers: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    float sum = calculateSum(numbers);
    cout << "The sum of the numbers is: " << sum << endl;
    return 0;
}
