class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
        }
        vector<vector<int>>ans(2);
        for(int i=0;i<matches.size();i++){
            if(mp.find(matches[i][0])==mp.end()) {
                ans[0].push_back(matches[i][0]);
                mp[matches[i][0]]=2;
            }
            if(mp[matches[i][1]]==1) ans[1].push_back(matches[i][1]);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};