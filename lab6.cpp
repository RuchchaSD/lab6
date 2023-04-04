#include<iostream>
using namespace std;
#include <algorithm>
#include <chrono>
using namespace std::chrono;

#define MAX_SIZE 100 

class Stack {
private:
    int top;
    int arr[MAX_SIZE];
public:
    
    Stack() {
        top = -1;
    }
    

    
    void Push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Error: Stack overflow\n";
            return;
        }
        arr[++top] = value;
    }
    
    
    void Pop() {
        if (top < 0) {
            cout << "Error: Stack underflow\n";
            return;
        }
        top--;
    }
    
    
    bool isEmpty() {
        return (top < 0);
    }
    
    
    bool isFull() {
        return (top >= MAX_SIZE - 1);
    }
    
    
    int StackTop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    
    
    void Display() {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    auto start1 = high_resolution_clock::now();
    Stack s;
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop(); 
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    double time1 = (double)duration1.count()/1000.0;

    cout << time1 <<"  millieseconds";

    return 0;
}
