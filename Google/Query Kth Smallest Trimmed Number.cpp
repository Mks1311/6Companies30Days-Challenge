class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            vector<pair<string,int>>p;
            for(int j=0;j<nums.size();j++){
                int trim=nums[j].size()-queries[i][1];
                string s=nums[j].substr(trim);
                p.push_back({s,j});
            }
            sort(p.begin(),p.end());
            ans.push_back(p[queries[i][0]-1].second);
        }
        return ans;
    }
};