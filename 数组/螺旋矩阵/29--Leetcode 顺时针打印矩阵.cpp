// 29--Leetcode 顺时针打印矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include<iostream>
#include<vector>
using namespace std;
//自己的方法
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //如果给的矩阵为空
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return {};
    }
    vector<int>res;//结果容器
    int n = matrix.size();/*矩阵的长*/
    int n2 = matrix[0].size();/*矩阵的宽*/
    int n3 = n > n2 ? n2 : n;//选出矩阵中边比较小的那条
    int startx = 0, starty = 0;// 定义每循环一个圈的起始位置
    int loop = n3 / 2;// 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
    int mid = n / 2;// 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
    int offset = 1;// 需要控制每一条边遍历的长度，每次循环右边界收缩一位

    int i, j;

    while (loop--) {
        //让i，j从开始startx,starty开始
        i = startx;
        j = starty;
        // 下面开始的四个for就是模拟转了一圈，每到下一个数字就push
		// 模拟填充上行从左到右(左闭右开)
		for (j = startx; j < n2  - offset; j++) {
			res.push_back(matrix[startx][j]);
		}
		// 模拟填充右列从上到下(左闭右开)
		for (i = starty; i < n - offset; i++) {
			res.push_back(matrix[i][j]);
		}
		// 模拟填充下行从右到左(左闭右开)
		for (; j > starty; j--) {
			res.push_back(matrix[i][j]);
		}
		// 模拟填充左列从下到上(左闭右开)
		for (; i > startx; i--) {
			res.push_back(matrix[i][j]);
		}

        // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
        startx++;
        starty++;
        // offset 控制每一圈里每一条边遍历的长度
        offset++;
    }
    // 如果n为奇数并且矩阵为正方形的话，需要单独给矩阵最中间的位置赋值
    if (n % 2 == 1&&n==n2) {
        res.push_back(matrix[mid][mid]);
    }
    else if(n3%2==1){//如果矩阵为长方形
        //如果这个长方形是横着放的
        if (n2>n){
            for (int i = starty; i < n2 - offset+1;i++) {
                res.push_back(matrix[startx][i]);
            }
        }
        //如果这个长方形是竖着放的
        else{
            for (int i = startx; i < n - offset + 1;i++) {
                res.push_back(matrix[i][starty]);
            }
        }
    }
    return res;
}

//大佬的方法
vector<int> spiralOrderMaster(vector<vector<int>>& matrix){
    if (matrix.empty()) return {};
    vector<int> res;
    int l = 0;                      //左边界
    int r = matrix[0].size() - 1;   //右边界
    int t = 0;                      //上边界
    int b = matrix.size() - 1;      //下边界
    while (true){
        //left -> right
        for (int i = l; i <= r; i++) {
            res.push_back(matrix[t][i]);
        }
        if (++t > b) break;
        //top -> bottom
        for (int i = t; i <= b; i++) {
            res.push_back(matrix[i][r]);
        }
        if (--r < l) break;
        //right -> left
        for (int i = r; i >= l; i--) {
            res.push_back(matrix[b][i]);
        }
        if (--b < t) break;
        //bottom -> top
        for (int i = b; i >= t; i--) {
            res.push_back(matrix[i][l]);
        }
        if (++l > r) break;
    }
    return res;
}

int main() {
    vector<vector<int>>matrix{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };


    vector<int>temp2;
    temp2 = spiralOrderMaster(matrix);
    for (int i = 0; i < temp2.size(); i++){
       cout<< temp2[i];
    }

}

