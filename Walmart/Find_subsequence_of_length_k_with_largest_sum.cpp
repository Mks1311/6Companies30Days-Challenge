class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>temp;
        while(!pq.empty()){
            temp.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        vector<int>ans;
        while(!temp.empty()){
            ans.push_back(temp.top().second);
            temp.pop();
        }
        return ans;

    }
};