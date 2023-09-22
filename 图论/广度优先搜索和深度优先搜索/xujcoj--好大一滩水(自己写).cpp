#include<iostream>
#include<string>
#include<queue>
using namespace std;
//char d[10][10];
//bool f[10][10];
//int dir[4][2] = { 1,0,0,-1,0,1,-1,0 }, n, m;
//struct Point
//{
//	int x, y;
//};
//int BFS(Point b)
//{
//	Point now, next;
//	queue<Point>q;
//	q.push(b);
//	int num=0;
//	while (q.size())
//	{
//		now = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			next.x = now.x + dir[i][0];
//			next.y = now.y + dir[i][1];
//			if (0 <= next.x && next.x < n && 0 <= next.y && next.y < m)
//			{
//				if (!f[next.x][next.y] && d[next.x][next.y] == 'W')
//				{
//					q.push(next);
//					f[next.x][next.y] = 1;
//					num++;
//				}
//			}
//		}
//	}
//	return num;
//}
//int main()
//{
//	cin >> n >> m;
//	Point s;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			f[i][j] = 0;
//			cin >> d[i][j];
//			
//		}
//	}
//	cin >> s.x >> s.y;
//	if (d[s.x][s.y]=='L')
//	{
//		cout << 0;
//	}
//	else
//	{
//		cout << BFS(s) << endl;
//	}
//	return 0;
//}

typedef long long ll;
int a[114][114] = { 0 };
bool book[114][114];
int ans = 1;
int n, m;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
void dfs(int x, int y) {
    a[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (a[tx][ty] == 0 && tx >= 0 && ty >= 0 && tx < n && ty < m) {
            ans++;
            dfs(tx, ty);
        }
    }
}
int main() {
    cin >> n >> m;
    char b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b;
            if (b == 'W')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    int c, d;
    cin >> c >> d;
    if (a[c][d] == 1)
        cout << 0;
    else {
        dfs(c, d);
        cout << ans;
    }
}