#include <iostream>
using namespace std;
class Queue {
private:
    int *arr;       
    int front;      
    int rear;       
    int capacity;   
    int size;       
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        this->size = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isFull() {
        return size == capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  
        arr[rear] = value;
        size++;
        cout << value << " enqueued to the queue" << endl;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;  
        }
        int dequeuedValue = arr[front];
        front = (front + 1) % capacity;  
        size--;
        return dequeuedValue;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        return arr[front];
    }
};
int main() {
    Queue queue(5);
    queue.enqueue(14);  
    queue.enqueue(18);
    queue.enqueue(23);
    cout << queue.dequeue() << " dequeued from queue" << endl; 
    queue.enqueue(29);
    cout << "Front element is: " << queue.peek() << endl;  
    return 0;
}
