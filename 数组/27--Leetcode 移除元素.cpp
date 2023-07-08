	#include <vector>
	#include <iostream>

	using namespace std;
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (val != nums[fastIndex]) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		return slowIndex;
	}

	

	int main(){
		vector<int>nums = { 1,2,3,3,5,4 };
		int val = 3;
		int temp=removeElement(nums, val);

		for (int x:nums){
			cout << x<<" ";
		}
		cout << endl;
		cout << temp;


	}


