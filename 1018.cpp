#include <iostream>

// 定義節點結構
struct Node {
    int data;       // 節點資料
    Node* left;     // 左子樹指標
    Node* right;    // 右子樹指標

    // 建構函數
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 插入節點到二元搜尋樹
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        // 如果根節點為空，則創建一個新節點
        return new Node(value);
    }

    // 根據值的大小插入到左或右子樹
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// 中序遍歷 (左子樹 -> 根節點 -> 右子樹)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);       // 遍歷左子樹
        std::cout << root->data << " ";     // 訪問根節點
        inorderTraversal(root->right);      // 遍歷右子樹
    }
}

int main() {
    Node* root = nullptr;

    // 插入 8 個整數到二元搜尋樹中
    int values[8] ;
    std::cout << "輸入8個整數: ";
    for(int i=0;i<8;i++)
    {
        std::cin >> values[i];
    }
    
    for (int value : values) {
        root = insert(root, value);
    }

    // 中序遍歷
    std::cout << "二元搜尋樹的中序遍歷結果: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
