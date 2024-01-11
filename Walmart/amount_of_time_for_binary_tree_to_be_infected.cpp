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
    void convert(TreeNode* root,unordered_map<int,vector<int>>&graph){
        if(!root) return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        convert(root->left,graph);
        convert(root->right,graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        convert(root,graph);
        queue<int>qt;
        unordered_set<int>st;
        qt.push(start);
        st.insert(start);
        int minute=-1;
        while(!qt.empty()){
            int lvlsize=qt.size();
            while(lvlsize>0){
                int curr=qt.front();
                qt.pop();
                for(auto i:graph[curr]){
                    if(st.find(i)==st.end()){
                        st.insert(i);
                        qt.push(i);
                    }
                }
                lvlsize--;
            }
            minute++;
        }
        return minute;
    }
};