/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode*& root, int key)
    {
        TreeNode* node = new TreeNode(key);
        if (!root) {
            root = node;
            return;
        }
        TreeNode* prev = NULL;
        TreeNode* temp = root;
        while (temp) {
            if (temp->val > key) {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->val < key) {
                prev = temp;
                temp = temp->right;
            }
        }
        if (prev->val > key)
            prev->left = node;
        else
            prev->right = node;
    }
    void solve(TreeNode* root,TreeNode* &ans,int l,int h){
        if(!root) return;
        if(root->val>=l && root->val<=h) insert(ans,root->val);
        solve(root->left,ans,l,h);
        solve(root->right,ans,l,h);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode *ans=nullptr;
        solve(root,ans,low,high);
        return ans;
    }
};