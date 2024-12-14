#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 定義雜湊表大小
const int HASH_TABLE_SIZE = 7;

// 哈希函數
int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

// 插入數據到雜湊表
void insertToHashTable(vector<list<int>> &hashTable, int key) {
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}

// 打印雜湊表內容
void printHashTable(const vector<list<int>> &hashTable) {
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "hash [" << i << "]: ";
        for (int val : hashTable[i]) {
            cout << "[" << val << "] -> ";
        }
        cout << "NULL" << endl;
    }
}

int main() {
    // 初始化雜湊表
    vector<list<int>> hashTable(HASH_TABLE_SIZE);

    // 輸入數據
    vector<int> inputData;
    cout << "請輸入任意多個整數數據（輸入非數字以結束輸入）：" << endl;
    int value;
    while (cin >> value) {
        inputData.push_back(value);
    }

    // 插入數據到雜湊表
    for (int key : inputData) {
        insertToHashTable(hashTable, key);
    }

    // 打印雜湊表
    printHashTable(hashTable);

    return 0;
}
