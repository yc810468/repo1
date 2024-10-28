#include <iostream>
#include <vector>

const int N = 12; // 迷宮的大小
int maze[N][N] = {                      //設計迷宮
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// 方向向量：上、下、左、右
int dx[] = {-1, 1, 0, 0};   //左右向量
int dy[] = {0, 0, -1, 1};   //上下向量

// 判斷某個位置是否有效
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0;
}

// 遞迴尋找所有迷宮解法的函數
void findAllPaths(int x, int y, int endX, int endY, std::vector<std::pair<int, int>>& path, std::vector<std::vector<std::pair<int, int>>>& solutions) {
    if (x == endX && y == endY) {  // 找到一條完整的路徑
        path.push_back({x, y});
        solutions.push_back(path);  // 儲存此解
        path.pop_back();
        return;
    }

    if (!isValid(x, y)) {  // 位置無效
        return;
    }

    maze[x][y] = -1;  // 標記當前點已訪問
    path.push_back({x, y});

    // 遍歷四個方向
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        findAllPaths(nx, ny, endX, endY, path, solutions);
    }

    // 回溯
    path.pop_back();
    maze[x][y] = 0;  // 恢復當前點的狀態
}

int main() {
    int startX = 1, startY = 1; //初始位置
    int endX = 10, endY = 10;   //終點位置
    std::vector<std::pair<int, int>> path;  //儲存一條「路徑」上的所有點
    std::vector<std::vector<std::pair<int, int>>> solutions;    //儲存多條路徑
    std::cout << "\n 顯示迷宮：\n";
    for(int i=0;i<N;i++)
    {
        std::cout << "\t";
        for(int j=0;j<N;j++)
        {
            if(maze[i][j]==1)
                std::cout <<"██";
            else
                std::cout <<"  ";
        }
        std::cout << std::endl;
    }
    findAllPaths(startX, startY, endX, endY, path, solutions);  //// 遞迴尋找所有迷宮解法

    // 輸出所有解
    if (!solutions.empty()) {
        std::cout << "共有 " << solutions.size() << " 種解法：\n";
        for (size_t i = 0; i < solutions.size(); ++i) {
            std::cout << "解法 " << i + 1 << ":\n";
            for (const auto& coord : solutions[i]) {
                std::cout << "(" << coord.first << ", " << coord.second << ") ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "沒有找到任何解法。\n";
    }

    return 0;
}
