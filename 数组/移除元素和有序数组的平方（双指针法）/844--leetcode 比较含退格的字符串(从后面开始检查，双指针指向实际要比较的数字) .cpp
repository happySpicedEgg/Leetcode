#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //设置两个指针的位置，定义跳过次数机会变量
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        //进入循环，通过这个循环的检验，看看是否能通过两个数组一样的考验？
        while (i >= 0 || j >= 0) {
            //现在可以看成i后面的都是与j后面的一样，此时i往前面寻找下一个要比较的数，看看是否和j等等要找的数字一样
            while (i >= 0) {
                //如果i是井号跳过次数+1，就不用拿井号前面那个数字比较，通过这个循环来找下一个比较的数
                if (S[i] == '#') {
                    skipS++, i--;
                }
                else if (skipS > 0) {
                    skipS--, i--;
                }
                //如果找到了下一个要比较的数字，那你就break，去看看指针j怎么找的
                else {
                    break;
                }
            }
            //此时j往前面寻找下一个要比较的数，看看是否和i刚刚要找的数字一样
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                }
                else if (skipT > 0) {
                    skipT--, j--;
                }
                else {
                    break;
                }
            }
            //如果i和j没越过边界，那就看看i，j所指向的值是否相等
            if (i >= 0 && j >= 0) {
                //不等返回false
                if (S[i] != T[j]) {
                    return false;
                }
            }
            //这里能够进去代表i或者j有一个或者两个越界了，
            //那什么情况会进入？假如现在你的i和j后面的数字都比较过了，都是相等的‘
            //但如果i找不到下一位的时候，找不到了，并且j能够找到下一个要比较的数字的时候，就证明两个数组不相等，返回false
            else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};


