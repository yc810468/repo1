#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) {
            std::cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            std::cout << "Stack is empty!\n";
            return -1; // returns -1 to indicate error
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    for(int i=1;i<=10;i++){
        stack.push(i);
    }
    while(stack.peek()!=-1){
         std::cout << stack.peek() << "\n";
         stack.pop();
    }
   

    return 0;
}