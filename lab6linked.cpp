#include<iostream>
using namespace std;
#include <algorithm>
#include <chrono>
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
    
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:

    Stack() {
        top = nullptr;
    }
    
    
    void Push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    
    void Pop() {
        if (top == nullptr) {
            cout << "Error: Stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    
    bool isEmpty() {
        return (top == nullptr);
    }
    
    
    bool isFull() {
        
        return false;
    }
    
    
    int StackTop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    
    void Display() {
        cout << "Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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