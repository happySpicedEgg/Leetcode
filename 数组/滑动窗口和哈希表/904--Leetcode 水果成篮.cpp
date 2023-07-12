
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//力扣官方题解，使用哈希表
    int totalFruit(vector<int>& fruits) {
        //创建哈希表和循环用的容器
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        //创建左指针和最大值
        /*开始循环，右指针每移动一步就放一个水果进去哈希表，并且记录现在有多少水果了
        （在两种水果的前提下）， 如果水果的种类大于三种，那就把左指针水果扔了，扔干净，顺便把指针指向
        下一个新水果，这个新水果此时后面没有之前left那个水果，顺便又统计新下一轮水果数量，留下一个最大值*/
        for (int right = 0; right < n; ++right) {
            //放水果进去哈希表
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                //哈希表迭代器
                auto it = cnt.find(fruits[left]);
                --it->second;/*扔水果出篮子，就相当于使对应种类的水果数量减一*/
                if (it->second == 0) {//如果篮子为空就扔掉篮子
                    cnt.erase(it);
                }
                ++left;//每扔掉一个水果，左指针就移动一下，知道左指针指向新的水果
            }
            ans = max(ans, right - left + 1);//指针变动后就统计下当前水果数量
        }
        return ans;
    }


int main(){
	vector<int>fruits{ 3,3,3,1,2,1,1,2,3,3,4 };
	cout<< totalFruit(fruits);

}

