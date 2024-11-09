#include <iostream>
#include <vector>
using namespace std;

// 最大堆調整函數（heapify）
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 先假設根節點是最大值
    int left = 2 * i + 1; // 左子節點
    int right = 2 * i + 2; // 右子節點

    // 如果左子節點較大，更新 largest
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子節點較大，更新 largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果 largest 不是根節點，交換並遞歸調整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆積排序函數
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 建立最大堆：從最後一個非葉子節點開始，向上調整堆
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // 提取元素，調整堆
    for (int i = n - 1; i >= 1; --i) {
        // 將當前根節點（最大值）與末尾元素交換
        swap(arr[0], arr[i]);

        // 調整根節點，維持最大堆的屬性
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {26, 5, 77, 1, 61, 4}; // 要排序的數列

    cout << "原始數列: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "排序後數列: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}