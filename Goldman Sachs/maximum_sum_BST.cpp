#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class nodeVal{
    public:
    int min,max,sum;
    nodeVal(int min,int max,int sum){
        this->min=min;
        this->max=max;
        this->sum=sum;
    }
};
class Solution {
public:
    int ans=0;
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
    nodeVal solve(TreeNode *root){
    if(!root) return nodeVal(INT_MAX,INT_MIN,0);
    nodeVal left=solve(root->left);
    nodeVal right=solve(root->right);
    if(root->val>left.max && root->val<right.min){
        ans=max(ans,root->val+left.sum+right.sum);
        return nodeVal(min(root->val,left.min),max(root->val,right.max),left.sum+root->val+right.sum);
    }
    return nodeVal(INT_MIN,INT_MAX,max(left.sum,right.sum));
}
};