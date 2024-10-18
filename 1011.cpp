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
    int findBottom() {
        if (isEmpty()) {
            std::cerr << "堆疊為空！無法找到堆疊末端。" << std::endl;
            exit(EXIT_FAILURE);
        }

        Node* current = top;
        // 迭代直到找到鏈結串列的最後一個節點
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }
    void printStack() {
        if (isEmpty()) {
            std::cout << "堆疊為空！" << std::endl;
            return;
        }
        Node* current = top;
        std::cout << "堆疊內容：";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

    // 向堆疊中添加一些元素
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.printStack();
    // 找到堆疊的末端
    std::cout << "堆疊末端元素: " << stack.findBottom() << std::endl;
    return 0;
}