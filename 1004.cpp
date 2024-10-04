#include <iostream>

class Queue {
private:
    int arr[20];    // 佇列的陣列，容量為20
    int front;      // 佇列的前端
    int rear;       // 佇列的後端
    int count;      // 佇列中的元素數量

public:
    Queue() : front(0), rear(-1), count(0) {}  // 初始化front為0，rear為-1，佇列為空

    // 判斷佇列是否為空
    bool isEmpty() {
        return count == 0;
    }

    // 判斷佇列是否已滿
    bool isFull() {
        return count == 20;
    }

    // 將元素加入佇列
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full, cannot enqueue " << value << "!\n";
        } else {
            rear = (rear + 1) % 20;  // 循環使用陣列
            arr[rear] = value;
            count++;
        }
    }

    // 從佇列中取出元素
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty, cannot dequeue!\n";
            return -1;  // 返回無效值作為標記
        } else {
            int value = arr[front];
            front = (front + 1) % 20;  // 循環使用陣列
            count--;
            return value;
        }
    }

    // 查看佇列的前端元素
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty, no front element!\n";
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue queue;

    // 將1到20加入佇列
    for (int i = 1; i <= 20; ++i) {
        queue.enqueue(i);
    }
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }
    return 0;
}

