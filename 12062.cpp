#include <iostream>
#include <vector>
#include <climits> // 用於 INT_MAX
using namespace std;

const int NUMBER = 6; // 範例中的頂點數

void displayMatrix(const vector<vector<int>>& matrix) {
    cout << "此圖的鄰接矩陣如下：" << endl;
    cout << "     ";
    for (int i = 0; i < NUMBER; i++) {
        cout << "vex" << i << " ";
    }
    cout << endl;
    for (int i = 0; i < NUMBER; i++) {
        cout << "vex" << i << " ";
        for (int j = 0; j < NUMBER; j++) {
            if (matrix[i][j] == INT_MAX) {
                cout << "  x  ";
            } else {
                cout << "  " << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(vector<vector<int>>& dist) {
    for (int k = 0; k < NUMBER; k++) {
        for (int i = 0; i < NUMBER; i++) {
            for (int j = 0; j < NUMBER; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void displayShortestPaths(const vector<vector<int>>& dist) {
    cout << "頂點互到各頂點最短路徑的最終結果：" << endl;
    int i=0;
    for (int j = 0; j < NUMBER; j++)
        cout << "從頂點1到頂點" << j+1 << "的最短距離=" << dist[i][j] << endl;
}

int main() {
    // 定義鄰接矩陣，INT_MAX 表示無限大（無路徑）
    vector<vector<int>> graph = {
        {0, 10, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, 20, 25, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 18, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 22, 95},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 77},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};

    displayMatrix(graph);

    vector<vector<int>> dist = graph; // 複製鄰接矩陣
    floydWarshall(dist);

    displayShortestPaths(dist);

    return 0;
}
