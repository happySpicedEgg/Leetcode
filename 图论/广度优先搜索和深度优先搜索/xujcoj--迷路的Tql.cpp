#include <iostream>
#include<queue>
using namespace std;
//方法一，BFS广度度优先搜索

const int M = 15;
//下上右左
int A[M][M], dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
bool vis[M][M];
//s代表走到这个点已经花费了几步
struct point {
    int x, y, s;
};
point begin_, end_;
int BFS() {
    queue<point> Q;
    Q.push(begin_);
    vis[begin_.x][begin_.y] = true;
    while (!Q.empty()) {
        //设置现在的出发点，就是队列里第一个元素
        point now = Q.front();
        Q.pop();
        if (now.x == end_.x && now.y == end_.y) {
            return now.s;
        }
        point next_;
        //这个代表接下来入队列的点，就是走到next的时候，记录已经走了now.s+1步
        next_.s = now.s + 1;
        for (int i = 0; i < 4; ++i) {
            next_.x = now.x + dir[i][0];
            next_.y = now.y + dir[i][1];
            if (A[next_.x][next_.y] != 9 && !vis[next_.x][next_.y]) {
                Q.push(next_);
                vis[next_.x][next_.y] = true;
            }
        }
    }
    return -1;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        //这个循环代表设置地图，从(1，1)开始设置，先全部设置为围墙9
        for (int i = 0; i <= a + 1; ++i) {
            for (int j = 0; j <= b + 1; ++j) {
                A[i][j] = 9;
                vis[i][j] = false;
            }
        }

        //这个循环正式设置地图
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                scanf("%1d", &A[i][j]);
                if (A[i][j] == 1) {
                    begin_.x = i;
                    begin_.y = j;
                    begin_.s = 0;
                }
                if (A[i][j] == 2) {
                    end_.x = i;
                    end_.y = j;
                }
            }
        }
        printf("%d\n", BFS());
    }
    return 0;
}
//方法二，DFS深度度优先搜索

//const int INF = 1e9;
//int n, m, ans = INF;
////mp是地图
//char mp[30][30];
////vis数组代表某个点是否遍历过
//bool vis[30][30];
//
///*vis标记是否走过该地*/
////按照右左下上的顺序
//int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
////递归函数的意思是以x，y为起点，开始寻找终点，step的意思是走到这个点已经走了多少步
//void DFS(int x, int y, int step)
//{
//	//如果step越界，就说明，寻找失败
//	if (step > ans)
//	{
//		return;
//	}
//	//如果当前这个点是2，那就寻找成功，返回step最短步数，step的意思是走到这个点已经走了多少步
//	if (mp[x][y] == '2')
//	{
//		ans = min(ans, step);
//		return;
//	}
//	//从x，y出发不断按照右左下上的顺序寻找
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dir[i][0], ny = y + dir[i][1];
//
//		/*nx为新移动的x坐标，ny为新移动的y坐标*/
//		//如果下一个寻找的点符合要求，即在边界内，而且下一个点不是墙壁，并且下一个点是没遍历过的点
//		if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '9' && !vis[nx][ny])
//		{
//			//如果下一个寻找的点符合要求，那就设置为已遍历
//			vis[x][y] = true;
//			//递归函数的意思是，nx，ny现在是下一个点，我要从nx，ny开始寻找目标点2，并且我走到nx，ny这个点，我已经走了step+1步了
//			DFS(nx, ny, step + 1);
//			//如果寻找失败，函数返回，那此时x，y重新设置为未遍历状态
//			vis[x][y] = false;
//		}
//	}
//}
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int x, y;
//		cin >> n >> m;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> mp[i][j];
//				vis[i][j] = false;
//
//				/*寻找Tql最远可以走到哪里*/
//				//给起点设置未遍历状态
//				if (mp[i][j] == '1')
//				{
//					x = i; y = j;
//					vis[i][j] = true;
//				}
//			}
//		}
//		ans = INF;
//		//开始以1所在的坐标为起点寻找最短路径
//		DFS(x, y, 0);
//		if (ans == INF)
//		{
//			ans = -1;
//		}
//		cout << ans << endl;
//
//	}
//}

