class Solution {
public:
    bool solve(int idx,string&s,set<string>&st,int n,vector<int>&dp){
        if(idx>=n){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s)!=st.end()) return true;
        for(int i=1;i<=n;i++){
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end()&&solve(idx+i,s,st,n,dp)){
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        int n=s.size();
        for(auto i:wordDict) st.insert(i);
        vector<int>dp(301,-1);
        return solve(0,s,st,n,dp);
    }
};