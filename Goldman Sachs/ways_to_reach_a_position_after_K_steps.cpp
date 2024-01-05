#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int mod=1e9+7;
long long solve(int  curr,int end,int k,vector<vector<int>>&dp){
    if(k==0) return curr==end;
    if(dp[999+curr][k]!=-1){
        return dp[999+curr][k];
    }
    long long forw=solve(curr+1,end,k-1,dp);
    long long back=solve(curr-1,end,k-1,dp);
    dp[999+curr][k]=(forw+back)%mod;
    return dp[999+curr][k];
}
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3000,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp)%mod;
    }
};