// Leetcode--合并区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//双指针法
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //先按左端点排序
    sort(intervals.begin(), intervals.end());
    //创建结果容器
    vector<vector<int>> ans;
    //for循环里的i表示正在处理第i个区间
    for (int i = 0; i < intervals.size(); )
    {
        //第一个t值等于第一个区间的右端点,即指向第一个区间{1,3}里的3
        int t = intervals[i][1];
        //定义一个指针j指向下一个区间
        int j = i + 1;
        //第二个指针j指向下一个区间的左端点，即{2，6}里面的2，看看2是否小于上一区间的的右端点，如果2小于上一个区间{1,3}的3，
        //那前后两个区间存在交集可以合并在一起，即{1，3}和{2，6}可以合并为{1,6}
        //下面的循环表示指针在遍历每个区间的左端点，看看那些区间能和第一个区间合并
        while (j<intervals.size()&&t>=intervals[j][0])
        {
            t = max(t, intervals[j][1]);
            j++;
        }
        //如果跳出循环，那就看看已经合并了谁
        ans.push_back({ intervals[i][0],t });
        //更新下一个要处理的开始区间
        i = j;

    }   
    return ans;
}

int main()
{
    int n,a,b;
    vector<vector<int>> tem;
    vector<vector<int>> intervals;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        intervals.push_back({ a,b });
    }
    tem=merge(intervals);
    for ( int i = 0; i < tem.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << tem[i][j];
            if (j==0)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

