class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int,int>mp;
        int sum=0,cnt=0;
        mp[sum]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};