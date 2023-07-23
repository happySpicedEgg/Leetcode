#include<iostream>
#include<vector>
using namespace std;
//真正函数开始，这个递归函数的意思是我接下来要对这个数组从l到r这个位置进行排序
void mergeSort(vector<int>& nums, vector<int>&tmp,int l, int r) {
    //如果只排序只有一个数字的数组，那没什么好说的，直接返回就是
    if (l >= r) return;
    //计算待排序数组中间值
    int mid = (l + r) /2;
    //若要对整个数组排好序，那就要先对数组左边排序，然后对数组右边排序，两次超级操作
    mergeSort(nums,tmp, l, mid);
    mergeSort(nums,tmp, mid + 1, r);
    //左右排好序后是这个样子的{6，15，20，42，8，12，38，50}，接着要进行合并
    //若要合并那就要定义临时辅助数组指针p和i左数组指针和右数组指针
    int i = l, j = mid + 1;
    int pos = 0;
    //当左右指针没有一个越界的时候则继续循环，直到一边数组为空，一边数组为还有余孽
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[pos++] = nums[i++];
        }
        else {
            tmp[pos++] = nums[j++];
        }
    }
    //将剩下的余孽加入到辅助数组当中
    while (i <= mid) {
        tmp[pos++] = nums[i++];
    }
    while (j <= r) {
        tmp[pos++] = nums[j++];
    }
    //当辅助数组加完了，现在辅助数组就是排好序的目标数组，现在令原数组等于辅助数组，返回原数组就是排好序的了
    for (int i = 0; i < r - l + 1; ++i) {
        nums[l+i] = tmp[i];
    }
}
//函数入口
    vector<int> sortArray(vector<int>& nums) {
        //先创建一个和nums一样大的数组
        vector<int>tmp(nums.size());
         //再真正进入归并排序函数
        mergeSort(nums,tmp, 0, (int)nums.size() - 1);
        return nums;
    }

    int main()
    {
        vector<int> nums = { 42,15,20,6,8,38,50,12 };
        sortArray(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        return 0;
    }