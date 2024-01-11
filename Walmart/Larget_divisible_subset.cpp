class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1),hash(n+1);
        sort(nums.begin(),nums.end());
        int last=0,maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>res;
        while(hash[last]!=last){
            res.push_back(nums[last]);
            last=hash[last];
        }
        res.push_back(nums[last]);
        return res;
    }
};