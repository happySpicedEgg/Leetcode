
#include<iostream>
#include<vector>
using namespace std;
////方法一，将复杂的逻辑和细节显示出来
//// 二分查找，寻找target的右边界（不包括target）
//// 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
//int getRightBorder(vector<int>& nums, int target) {
//	int left = 0;
//	int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
//	int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
//	while (left <= right) { // 当left==right，区间[left, right]依然有效
//		int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
//		if (nums[middle] > target) {
//			right = middle - 1; // target 在左区间，所以[left, middle - 1]
//		}
//		else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
//			left = middle + 1;
//			rightBorder = left;
//		}
//	}
//	return rightBorder;
//}
//
//// 二分查找，寻找target的左边界leftBorder（不包括target）
//// 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
//int getLeftBorder(vector<int>& nums, int target) {
//	int left = 0;
//	int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
//	int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
//	while (left <= right) {
//		int middle = left + ((right - left) / 2);
//		if (nums[middle] >= target) { // 寻找左边界，就要在nums[middle] == target的时候更新right
//			right = middle - 1;
//			leftBorder = right;
//		}
//		else {
//			left = middle + 1;
//		}
//	}
//	return leftBorder;
//}
//
//vector<int> searchRange(vector<int>& nums, int target) {
//	int leftBorder = getLeftBorder(nums, target);
//	int rightBorder = getRightBorder(nums, target);
//	// 情况一
//	if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
//	// 情况三
//	if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
//	// 情况二
//	return { -1, -1 };
//}

//同思路但代码简化
//5,7,7,8,8,10  target=8

//二分查找左右边界正式开始
int binarySearch(vector<int>& nums,int target,bool lower)
{
	//设置左右边界，还有中间值记录器
	int left = 0; int right = nums.size() - 1; int ans = nums.size();
	//如果是左挡位三个指针肯定指着左边界，然后右指针往左移动来结束循环，此时可直接返回ans
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid]>target||(lower&&nums[mid] >= target))
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	//返回ans
	return ans;

}
    //二分查找入口
vector<int> searchRange(vector<int>& nums,int target) 
{
	//先找左边界
	int left = binarySearch(nums, target, true);
	//再找右边界，记住，找右边界函数的值返回时候要减1
	int right = binarySearch(nums, target, false) - 1;
	//如果函数返回的左边界小于等于右边界并且右边界小于nums.size(),并且左右边界都等于target就返回左右边界容器
	if (left<=right&&right<nums.size()&&nums[left]==target&&nums[right]==target)
	{
		return vector<int>{left, right};
	}
	//否则返回-1，-1
	return { -1,-1 };
}

int main() {
	vector<int>nums;

	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);



	vector<int>temp = searchRange(nums, 8);

	for (int s : temp) {
		cout << s << " ";
	}

}