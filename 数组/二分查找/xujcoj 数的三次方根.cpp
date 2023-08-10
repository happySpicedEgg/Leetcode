#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    double l = -100, r = 100;
    //无限二分，使l和right无限接近于目标数（假如输入1000，那么目标数字就是10），最后你会惊讶发现，l和r差距十分小的时候
    //就会跳出循环，此时你对l进行四舍五入到小数点后六位，正好就等于目标数字
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%.6lf", l);

}