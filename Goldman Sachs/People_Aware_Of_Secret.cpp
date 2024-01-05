#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1);
        int mod=1e9+7,ans=0;
        long long NumOfShare=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            long long NumOfNewShare=dp[max(0,i-delay)];
            long long Forget=dp[max(0,i-forget)];
            NumOfShare=(NumOfShare+NumOfNewShare-Forget+mod)%mod;
            dp[i]=NumOfShare;
        }
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};