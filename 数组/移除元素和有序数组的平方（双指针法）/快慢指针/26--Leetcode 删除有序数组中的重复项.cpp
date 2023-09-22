
#include <iostream>
#include<vector>
using namespace std;
//这题用双指针中的快慢指针，你可以这么看我觉得好理解一点
//你可以把快指针j看成是一个搜查官，不停往前找，直到找到与i指针所指的不一样的数字，然后把此时那个
//拿到良民证的数字（也就是与i不一样的数字）加入“新数组”（nums[i] = nums[j]可以看成是搜查官j把不重复的数放入新数组，找到一个放一个然后i++留出空位给下一个良民,不过新数组是覆盖在旧数组上面的）
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        if (nums.empty()){
            return 0;
        }
        
        while (i < nums.size() && j < nums.size()){
            //如果两个指针一样，那就挪动快指针知道快指针遇到下一个不重复的数字
            if (nums[i] == nums[j]){
                j++;
            }
            //如果快指针挪动到了下一个不重复的数字，那慢指针就往前挪一步，将快指针的值赋给慢指针，表示快指针发现新的可以加入的元素

            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i + 1;
    }

int main()
{
    vector<int> nums = { 1,2,3,4,5,6 };
    cout << removeDuplicates(nums)<<endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
}

