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
    int count = 0 ;
    vector<int> solve(TreeNode* root , int d){
        if(root == NULL) return {0};
        if(root->left == NULL and root->right == NULL) return {1};
        vector<int> left = solve(root->left, d);
        vector<int> right = solve(root->right , d);
        for(int x : left){
            for(int y : right){
                if(x > 0 and y > 0 ) if(x+y <= d) count+=1;
            }
        }
        vector<int> ans;
        for(int x : left){
            if(x > 0 && x < d)
                ans.push_back(x+1);
        }
        for(int x : right){
            if( x > 0 && x < d )
                ans.push_back(x+1);
        }
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root , distance); 
        return count;
    }
};