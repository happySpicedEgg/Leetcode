#include<vector>
using namespace std;
class Solution {
public:
	//把数组中的良民移入新数组，0不移进去新数组
	void moveZeroes(vector<int>& nums) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (nums[fastIndex] != 0) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		//把新数组剩下数字重置为0
		for (; slowIndex < nums.size(); slowIndex++) {
			nums[slowIndex] = 0;
		}

	}
};