#include<iostream>
using namespace std;
int aa[123456] = { 6,1,2,7,5,3,4,9,10,8 };
//递归函数意思是我想要在数组中从l到r位置寻找排序后的第k个数字
int quick_sort(int l, int r, int k)
{
    //如果当l==r，那他的意思就是我想在数组l，l的位置找第一个数字
    if (l >= r) return aa[l];

    //如果l！=r，那就抽盲盒，在数组中间找一个数字，比x大的放右边，比x小的放左边，最后我会得出x排序后是排第几(j - l + 1)个
    int i = l - 1, j = r + 1; int x = aa[(l + r) / 2];
    //不断交换，比x大的放右边，比x小的放左边
    while (i < j)
    {
        while (aa[++i] < x) {

        }
        while (aa[--j] > x){

        }
        if (i < j) swap(aa[i], aa[j]);
    }
    //pivot数字x（盲盒数字）他是排在j - l + 1个位置，j是盲盒数字x的下标
    //如果我抽出来的盲盒太大了，也就是x他排在第7个位置，比想要找的第k，5个数字大，开盲盒失败，那就往盲盒左边的数字（第j个）找第k个数字
    if (j - l + 1 >= k) return quick_sort(l, j, k);
    //如果我抽出来的盲盒，太小了，那就从新数组开始找（那就从盲盒数字x，即下标为j+1的数字开始找）排名第k - (j - l + 1)的数字
    else return quick_sort(j + 1, r, k - (j - l + 1));
}

int main()
{
   /* int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> aa[i];
    cout << quick_sort(0, n - 1, k) << endl;*/

    cout << quick_sort(0, 9, 5) << endl;

    return 0;
}
