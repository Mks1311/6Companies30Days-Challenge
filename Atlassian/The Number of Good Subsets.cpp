class Solution {
public:
    long long mod=1e9+7;
    int numberOfGoodSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>primes{2,3,5,7,11,13,17,19,23,29};
        vector<long long>dp(1<<10);
        dp[0]=1;
        map<int,int>mp;
        for(int i:nums) mp[i]++;
        for(auto i:mp){
            if(i.first==1) continue;
            int c=0;
            bool flag=true;
            for(int j=0;j<10;j++){
                int cnt=0;
                int x=i.first;
                while(x%primes[j]==0){
                    cnt++;
                    x/=primes[j];
                }
                if(cnt==1) c+=(1<<j);
                else if(cnt>=2) flag=false;
            }
            if(!flag) continue;
            for(int mask=0;mask<(1<<10);mask++){
                if(dp[mask] && ((mask&c)==0)){
                    dp[mask^c]+=(dp[mask]*(i.second));
                    dp[mask^c]%=mod;
                }
            }
        }
        long long ans=0;
        for(int mask=1;mask<(1<<10);mask++){
            if(dp[mask]){
                ans+=dp[mask];
                ans%=mod;
            }
        }
        long long k=1;
        for(int i=1;i<=mp[1];i++){
            k*=2;
            k%=mod;
        }
        ans*=(k);
        ans%=mod;
        return ans; 
    }
};