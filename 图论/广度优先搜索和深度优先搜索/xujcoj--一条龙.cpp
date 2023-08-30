#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int MAXN = 1e2 + 5;
typedef long long ll;

int G[MAXN][MAXN];
int m, p;	
struct node
{
	int x, y;
};
//右左下上
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };

//广度优先搜索
//函数意思为，以(x,y)点为起点，判断能否找到通路，找到通路就返回true，不能返回false
bool BFS(int x, int y)
{
	queue<node>Q;
	//将x,y点入队列，队里为待处理元素，比如（2，2）从对列里出来，那我们就要寻找（2,2)附近的符合要求的点，如果有符合要求的点就入队列
	Q.push({ x,y });
	//进入循环，不断处理弹出队列里的元素，看看这个点周围是否有符合要求的点，如果最后一个点出来，并且没有点入队列了，那就说明这个点周围
	 //没有符合要求的点就退出循环，寻找失败
	while (!Q.empty())
	{
		node now = Q.front();
		//把头元素取出
		Q.pop();
		//判断是否为符合要求的点
		if (G[now.x][now.y]==9) 
		{
			return true;
		}
		//如果不符合要求，那就从右左下上的顺序找，找到一个就入一个
		node next;

		for (int i = 0; i < 4; i++)
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			//判断next的合法性，并且看看是不是按数字递增顺序找
			if (next.x>=1&&next.x<=m&&next.y>=1&&next.y<=p&&G[next.x][next.y]==G[now.x][now.y]+1)
			{
				//如果是递增加一，就入队列，准备作为新一轮起点
				Q.push(next);
			}
		}

	}
	//没找到就返回false
	return false;

}

//深度优先搜索
//这个递归的意思是，以(x, y)点为起点，判断能否找到通路，找到通路就返回true，不能返回false
bool DFS(int x, int y)
{
	//判断是否为符合要求的点

	if (G[x][y] == 9)
	{
		return true;
	}
	node next;
	//如果不符合要求，那就从右左下上的顺序找
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		//判断next的合法性
		//如果找到递增数字，那就递归他，就是如果以1为起点找，你找到了2，那你就重新以2为起点开始四处找
		if (dx >= 1 && dx <= m && dy >= 1 && dy <= p && G[dx][dy] == G[x][y] + 1)
		{
			//带着以2为起点的信念和决心，相信2为起点能够找到，并且返回好消息true
			bool flag = DFS(dx, dy);
			if (flag)
			{
				return true;
			}
		}
	}
	return false;
}


void work()
{
	cin >> m >> p;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			cin >> G[i][j];
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			if (G[i][j] == 1)
			{
				bool flag = DFS(i, j);
				if (flag)
				{
					cout << "Yes"<<endl;
					return ;
				}

			}

		}
	}

	cout << "No" << endl;

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		work();
	}
}

