#include<vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (nums[fastIndex] != 0) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		for (; slowIndex < nums.size(); slowIndex++) {
			nums[slowIndex] = 0;
		}

	}
};