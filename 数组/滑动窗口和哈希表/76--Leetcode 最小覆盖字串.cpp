#include <iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        //把t字符串加入ht哈希表中，来保存字符串要求
        for (auto c : t) ht[c] ++;
        string res;
        int cnt = 0;
        //从现在开始，右指针i开始向右寻找，每找到一个字母就加入hs哈希表中，如果发现这个数字不是多余的字母，
        //对于ht来说他是有效添加，就代表这个字母还没封顶，那就cnt++
        //（记住，不在ht里面字母不需要cnt++，如果hs[s[i]] ++后，字母s[i]比ht里的要多，那也不用cnt++）
        for (int i = 0, j = 0; i < s.size(); i++) {
            hs[s[i]] ++;
            //不在t里面字母不需要cnt++，如果hs[s[i]] ++后，如果hs[s[i]] ++后，字母s[i]比ht里的要多
            if (hs[s[i]] <= ht[s[i]]) cnt++;
            //每次i++一次，就开始看看j可不可以贪心往右移动，直到j如果再往右滑动就会使cnt减少为止，来求最短的字符串
            while (hs[s[j]] > ht[s[j]]) hs[s[j++]] --;
            //在左指针j往右滑动缩小窗口后，如果cnt==t.size()，恭喜你现在窗口内的字符串达到要求也就是包含s，你现在可以和res比划比划谁最短
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};



