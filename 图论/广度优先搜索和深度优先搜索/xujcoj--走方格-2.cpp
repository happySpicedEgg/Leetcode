#include <iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 }; // 表示四个方向
struct node
{
    int x, y;
    string path;
};
// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标
node bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<node> que; // 定义队列
    node begin; begin.x = x; begin.y = y;
    que.push(begin); // 起始节点加入队列
    visited[x][y] = true; // 只要加入队列，立刻标记为访问过的节点
    while (!que.empty()) { // 开始遍历队列里的元素
        node cur, next;
        cur = que.front();
        if (grid[cur.x][cur.y] == 'E')
        {
            return cur;
        }
        que.pop(); // 从队列取元素
        for (int i = 0; i < 4; i++) { // 开始想当前节点的四个方向上下左右去遍历
            int nextx = cur.x + dir[i][0];
            int nexty = cur.y + dir[i][1]; // 获取周边四个方向的坐标
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 坐标越界了，直接跳过
            if (!visited[nextx][nexty] && grid[nextx][nexty] != '#') { // 如果节点没被访问过,并且没有障碍物
                if (i == 0)
                {
                    next.path = cur.path + 'U';
                }
                if (i == 1)
                {
                    next.path = cur.path + 'D';
                }
                if (i == 2)
                {
                    next.path = cur.path + 'L';

                }
                if (i == 3)
                {
                    next.path = cur.path + 'R';

                }
                next.x = nextx; next.y = nexty;
                que.push(next);  // 队列添加该节点为下一轮要遍历的节点
                visited[nextx][nexty] = true; // 只要加入队列立刻标记，避免重复访问
            }
        }
    }
    node error;
    error.path = "-1";
    return error;
}

int main()
{
    vector<vector<char>>grid;
    vector<vector<bool>> visited;
    int n, m, sx, sy;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char>v;  vector<bool>l;
        grid.push_back(v);  visited.push_back(l);
        for (int j = 0; j < m; j++)
        {
            bool b = false; char tep;
            cin >> tep; grid[i].push_back(tep);
            if (grid[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            visited[i].push_back(b);
        }
    }
    cout << bfs(grid, visited, sx, sy).path;
}
