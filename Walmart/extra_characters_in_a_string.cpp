class Solution {
public:
    int solve(int idx,string &s,unordered_set<string>&st,vector<int>&dp,int &n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        string currS="";
        int minExtra=n;
        for(int i=idx;i<n;i++){
            currS+=s[i];
            int currExtra=0;
            if(st.find(currS)==st.end()) currExtra+=currS.size();
            int nextExtra=solve(i+1,s,st,dp,n);
            minExtra=min(minExtra,currExtra+nextExtra);
        }
        return dp[idx]=minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        for(auto i:dictionary) st.insert(i);
        vector<int>dp(51,-1);
        int n=s.size();
        return solve(0,s,st,dp,n);
    }
};