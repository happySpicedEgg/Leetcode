#include <iostream>
using namespace std;
//方法一
int hisSqrt(int x) {
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}
//方法二
int mySqrt(int x) {
        int left = 0;
        int right = x;
        if (x == 1) {
            return 1;
        }

        while (left != right && right - left > 1) {
            int middle = (left + right) / 2;
            if ((long long)middle * middle == x) {
                return (int)middle;
            }
            else if ((long long)middle * middle > x) {
                right = middle;
            }
            else {
                left = middle;
            }
        }
        if (left * left > x && left * left < x) {
            return (int)left - 1;
        }
        else {
            return (int)left;
        }

 }


int main(){
    cout << mySqrt(4);


}

