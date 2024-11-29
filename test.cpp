#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices; // 節點數量
    vector<vector<int>> adjMatrix; // 相鄰矩陣

public:
    // 建構函數
    Graph(int v) : vertices(v), adjMatrix(v, vector<int>(v, 0)) {}

    // 添加邊
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // 無向圖
    }

    // 打印相鄰矩陣
    void printMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 10; // 節點數量
    Graph g(vertices);

    // 添加一些邊
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 1);
    g.addEdge(3, 7);
    g.addEdge(4, 1);
    g.addEdge(4, 7);
    g.addEdge(5, 2);
    g.addEdge(5, 8);
    g.addEdge(6, 2);
    g.addEdge(6, 8);
    g.addEdge(7, 3);
    g.addEdge(7, 4);
    g.addEdge(7, 9);
    g.addEdge(8, 5);
    g.addEdge(8, 6);
    g.addEdge(8, 9);
    g.addEdge(9, 7);
    g.addEdge(9, 8);

    // 打印相鄰矩陣
    g.printMatrix();

    return 0;
}
