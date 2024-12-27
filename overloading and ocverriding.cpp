#include <iostream>
using namespace std;
class OverloadingExample {
public:
    void display(int x) {
        cout << "Integer: " << x << endl;
    }
    void display(double x) {
        cout << "Double: " << x << endl;
    }
    void display(const string &x) {
        cout << "String: " << x << endl;
    }
};
class Base {
public:
    virtual void show() {
        cout << "Base class show function." << endl;
    }
};
class Derived : public Base {
public:
    void show() override { 
        cout << "Derived class show function." << endl;
    }
};
int main() {
    OverloadingExample obj;
    obj.display(42);         
    obj.display(3.14);       
    obj.display("Hello");  
    Base *basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    basePtr->show(); 
    return 0;
}
