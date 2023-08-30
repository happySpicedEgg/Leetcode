// Leetcode 最长连续子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//方法一，排序+滑动窗口
int longestConsecutive(vector<int>& nums)
{
    int n = nums.size();
    if (nums.size() <= 1) {
        return n;
    }
    // 1、排序
    sort(nums.begin(), nums.end());
    // 2、遍历所有连续序列，i记录左端点，j记录右端点
    // res记录已知最长序列的长度，cur记录当前序列的长度

    int res = 0;
    int cur = 1;
    int i = 0,j=1;
    // 3、j向右寻找i为起点的连续序列的长度
    while (j<nums.size())
    {
        // 3.1 nums[j-1] + 1 == nums[j]：元素j加入当前序列，并更新长度
        if (nums[j-1]+1==nums[j])
        {
            cur++;
        }
        // 3.2 nums[j-1] + 1 == nums[j]：遇到重复元素，当前序列的长度不变
        else if(nums[j]!=nums[j-1])
        {
            // 3.3 nums[j-1]与nums[j]既不相等也不相差1：i为起点的连续序列到j就断了，i=j，重开一个新的序列
            i = j;
            res = max(res, cur);
            cur = 1;
        }
        j++;
    }
    // 3.4 还需考虑到j为最后一个元素的情况
    return max(res, cur);

}

//方法二，哈希表
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const int& num : nums) {
        num_set.insert(num);
    }

    int longestStreak = 0;

    for (const int& num : num_set) {
        if (!num_set.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (num_set.count(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}


int main()
{
    vector<int>num = { 100,4,200,1,3,2 };
    cout << longestConsecutive(num);




}

