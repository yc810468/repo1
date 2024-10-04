#include <iostream>

class CircularQueue {
private:
    int arr[20];    // 佇列的陣列，容量為20
    int front;      // 佇列的前端
    int rear;       // 佇列的後端
    int size;       // 佇列的最大容量
    int count;      // 佇列中的元素數量

public:
    // 初始化 front 和 rear，size 為佇列容量
    CircularQueue() : front(0), rear(0), size(20), count(0) {}

    // 判斷佇列是否為空
    bool isEmpty() {
        return count == 0;
    }

    // 判斷佇列是否已滿
    bool isFull() {
        return count == size;
    }

    // 將元素加入佇列
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full, cannot enqueue " << value << "!\n";
        } else {
            arr[rear] = value;
            rear = (rear + 1) % size;  // 循環使用 rear
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
            front = (front + 1) % size;  // 循環使用 front
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
    CircularQueue queue;

    // 將1到20加入佇列
    for (int i = 1; i <= 20; ++i) {
        queue.enqueue(i);
    }
    // 依序取出佇列中的元素
    while (!queue.isEmpty()) {
        std::cout <<  queue.dequeue() << " ";
    }

    return 0;
}
