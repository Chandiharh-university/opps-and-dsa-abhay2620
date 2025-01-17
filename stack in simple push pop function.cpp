#include <iostream>
using namespace std;
class Stack {
private:
    int *arr;       
    int top;        
    int capacity;   
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  
    }
    ~Stack() {
        delete[] arr;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; 
        }
        int poppedValue = arr[top--];
        return poppedValue;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        return arr[top];
    }
};
int main() {
    Stack stack(5);
    stack.push(10);  
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << " popped from stack" << endl;  
    stack.push(40);
    cout << "Top element is: " << stack.peek() << endl;  
    return 0;
}
