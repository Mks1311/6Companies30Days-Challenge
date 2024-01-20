class Solution {
public:
    int mod=1e9+7;
    int solve(int cnt,int mask,int prev,vector<vector<int>>&dp,vector<int>&nums){
        if(cnt==nums.size()) return 1;
        if(dp[prev+1][mask]!=-1) return dp[prev+1][mask];
        long long count=0;
        for(int i=0;i<nums.size();i++){
            if(mask&(1<<i)) continue;
            if(mask!=0 && nums[i]%nums[prev]!=0 && nums[prev]%nums[i]!=0) continue;
            count=(count+solve(cnt+1,mask|(1<<i),i,dp,nums))%mod;
        }
        return dp[prev+1][mask]=count;
    }
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>((1<<n),-1));
        int mask=0;
        int prev=-1;
        return solve(0,mask,prev,dp,nums);
    }
};