#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//递归法实现
class Solution {
public:
    //开始递归调用，确定函数参数和返回值
    void preorder(TreeNode* root, vector<int>& res) {
        //确定终止条件
        if (root == NULL) {
            return;
        }
        //排序，确定单层递归的逻辑
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);

    }

    //调用上方函数
    vector<int> preorderTraversals(TreeNode* root) {
        //创建vector容器储存上方遍历的值
        vector<int>res;
        //调用函数
        preorder(root, res);
        //返回容器
        return res;
    }


    //用迭代法实现前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        //创建堆栈和容器
        stack<TreeNode*> st;
        vector<int> result;
        //如果根节点就为空，那就返回一个空的容器
        if (root==NULL){
            return result;
        }
        //根节点入栈
        st.push(root);
        //当栈不为空从栈顶弹出元素，将遍历来的元素放到vector里，并且将弹出的元素的左右儿子加入栈当中
        while (!st.empty()){
            TreeNode* node = st.top();// 中
            st.pop();
            result.push_back(node->val);
            if (node->right){
                st.push(node->right);// 右（空节点不入栈）
            }
            if (node->left){
                st.push(node->left);  // 左（空节点不入栈）
            }
        }
        return result;
    }
};

int main() {

}