#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
//这里递归法就省略了

class Solution {
public:
    //迭代法
    vector<int> inorderTraversal(TreeNode* root) {
        //创建一个结果容器
        vector<int> result;
        //创建一个堆栈存放待处理节点
        stack<TreeNode*> st;
        //将根节点放入堆栈
        TreeNode* cur = root;

        while (cur!=NULL||!st.empty()){
            if (cur!=NULL){// 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left; // 往左遍历
            }
            else{
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);/*如果刚刚有结点弹出，说明此节点左边以访问过，该访问节点右边*/
                cur= cur->right;// 往右遍历
            }

        }
        return result;
    }
};