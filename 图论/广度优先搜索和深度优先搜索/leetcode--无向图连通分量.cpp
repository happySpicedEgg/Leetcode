//由于leetcode要会员，所以我在xujcoj上面写
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1e5 + 5;

typedef long long ll;
vector<int>G[MAXN];
bool vis[MAXN];
//方法一，深度优先搜素

//DFS函数（递归）可以看成是这样一个超级操作——就是把一个点所在的连通分量全部遍历完,x值代表要遍历的节点，p代表若要遍历这个节点，
//它是由什么节点延伸的？
void DFS(int x,int p) 
{
	//先设置已遍历
	vis[x] = true;
	//再遍历每个节点邻接表与某节点相连的每一个节点
	for (int i = 0; i < G[x].size(); i++)
	{
		//如果此节点是由p节点衍生的，那就不能遍历，而且
		//如果是已经遍历过的节点那就没必要再遍历
		if (G[x][i] == p || vis[G[x][i]]) 
		{
			continue;
		}
		else
		{
			//如果不是上面的情况，那就DFS这个邻接表的节点
			DFS(G[x][i], x);
		}

	}

}
//方法二，深度优先搜索
void BFS(int x)
{
	queue<int>Q;
	//把节点x push进去
	Q.push(x);
	while (!Q.empty())
	{
		//把头元素拿出来
		int now = Q.front();
		Q.pop();
		vis[now] = true;
		//遍历当前节点的邻接点
		for (int next:G[now])
		{
			if (vis[next])
			{
				continue;
			}
			else
			{
				Q.push(next);
			}
		}


	}
}

void work()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0,x,y; i < m; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = 0;/*设定答案数值*/
	//循环每一个节点，i代表每个节点
	for (int i = 1; i <= n; i++)
	{
		//如果此节点还未被访问，那就DFS，遍历这个节点
		if (!vis[i])
		{
			//DFS(i, -1);
			BFS(i);
			ans++;
		}
	}
	cout << ans;

}


int main()
{
	work();
}

