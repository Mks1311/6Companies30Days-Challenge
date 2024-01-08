class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),median=0,ans=0;
        sort(nums.begin(),nums.end());
        median=nums[n/2];
        // if(n%2==0){
        //     median=(nums[(n/2)-1]+nums[((n/2))])/2;
        // }else median=nums[n/2];
        for(auto i:nums){
            ans+=(abs(median-i));
        }
        return ans;
    }
};