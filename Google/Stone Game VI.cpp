class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp.push_back({aliceValues[i]+bobValues[i],i});
        }
        sort(mp.rbegin(),mp.rend());
        int alice=0,bob=0;
        for(int i=0;i<n;i++){
            int idx=mp[i].second;
            if(i&1) bob+=bobValues[idx];
            else alice+=aliceValues[idx];
        }
        if(alice==bob) return 0;
        return alice>bob?1:-1;
    }
};