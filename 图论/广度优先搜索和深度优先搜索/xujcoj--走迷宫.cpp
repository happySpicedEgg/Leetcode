#include<iostream>
#include<queue>
using namespace std;
struct Point
{
	//x,y代表坐标点,s代表你走到x,y的时候你已经走了多少步
	int x, y, s, r;
};
int main()
{
	int n, m;
	cin >> n >> m;
	int a[105][105];
	//按照右左下上的顺序走
	int dir[4][2]{ 0,1,0,-1,1,0,-1,0 };
	//三维数组第三个比如[1][1][0]你身上背着0个火箭的行动轨迹或者可能是你使用火箭的降落点，代表没背着火箭经过此地,
	//比如[1][1][1]代表是否背着火箭经过此地
	bool vis[105][105][2]{ false };
	//设置起点，终点和下一个点
	Point Begin, now, Next;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				//如果遇到0，就初始化起点
				Begin.x = i;
				Begin.y = j;
				Begin.r = 1;
				Begin.s = 0;
			}
		}
	}
	queue<Point>Q;
	Q.push(Begin);
	//给开始的点设置1值，不能起点和终点都是0
	a[Begin.x][Begin.y] = 1;
	vis[Begin.x][Begin.y][Begin.r] = true;
	bool tp = false;
	while (Q.size())
	{
		now = Q.front();
		Q.pop();
		//如果你接下来的出发点刚好是0,恭喜你胡了，你找到了终点
		if (a[now.x][now.y] == 0)
		{
			cout << now.s;
			tp = true;
			break;
		}
		Next.s = now.s + 1;
		//不使用火箭背包，或者你已经使用火箭背包，你是这样走的：
		for (int i = 0; i < 4; i++)
		{
			//按照右左下上的顺序走一格
			Next.x = now.x + dir[i][0];
			Next.y = now.y + dir[i][1];
			Next.r = now.r;
			if (Next.x >= 0 && Next.x < n && Next.y >= 0 && Next.y < m)
			{
				//如果你不使用火箭背包，你来到此地，那你将在不使用火箭背包的地图做标记，标记为true
				//如果你使用过了火箭背包，身上now.r==0,没有火箭了,你来到此地，那你将在使用火箭背包的地图做标记，标记为true
				if (!vis[Next.x][Next.y][now.r] && a[Next.x][Next.y] != -1)
				{
					Q.push(Next);
					vis[Next.x][Next.y][now.r] = true;
				}
			}
		}
		//用火箭背包看看怎么走
		for (int i = 0; i < 4; i++)
		{
			//按照右左下上的顺序走两格
			Next.x = now.x + dir[i][0] * 2;
			Next.y = now.y + dir[i][1] * 2;
			//如果此时now这个起点r==0了，没有火箭背包了，那就退出了
			if (now.r - 1 < 0)
				break;
			if (Next.x >= 0 && Next.x < n && Next.y >= 0 && Next.y < m)
			{
				if (!vis[Next.x][Next.y][now.r - 1] && a[Next.x][Next.y] != -1)
				{
					//r==1代表此时还有火箭背包，r==0代表已经用完了,用火箭背包走，下一个要入队列的点，火箭数量是要减一的
					Next.r = now.r - 1;
					Q.push(Next);
					vis[Next.x][Next.y][now.r - 1] = true;
				}
			}
		}
	}
	if (!tp)
	{
		cout << -1;
	}
	return 0;
}