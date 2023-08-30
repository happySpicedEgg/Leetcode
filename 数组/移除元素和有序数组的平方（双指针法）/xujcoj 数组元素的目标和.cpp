
#include<iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];
int n, m, x;


//对撞指针，先把b数组的j指针挪到a[i] + b[j] < x处，再想办法挪动a数组指针，挪到天胡为止
int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    for (int i = 0, j = m - 1; i < n; ++i)
    {
        //先把b数组的j指针挪到a[i] + b[j] < x处，结尾i++后看看是否太大了，是否>x，如果>x那就把j指针挪到a[i] + b[j] < x处
        while (j >= 0 && a[i] + b[j] > x) j--;
        //再想办法挪动a数组指针，挪到天胡为止，这里是判断是否天胡，如果没天胡，那就结尾i++；
        if (a[i] + b[j] == x)
        {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}