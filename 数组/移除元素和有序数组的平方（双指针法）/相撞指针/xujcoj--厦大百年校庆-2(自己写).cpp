
#include <iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
char a[N];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int s = 0; s < m; s++)
	{
		int i = 0, j = n - 2;

		while (i<=j)
		{
			if (a[i]=='B'&&a[i+1]=='G')
			{
				swap(a[i],a[i+1]);
				i++;
			}
			if (a[j]=='B'&&a[j+1] == 'G'&&i<j)
			{
				swap(a[j], a[j +1]);
				j++;
			}
			i++;
			j--;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}

}

