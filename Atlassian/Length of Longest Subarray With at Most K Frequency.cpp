class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k>=nums.size()) return nums.size();
        map<int,int>mp;
        int maxy=0,i=0,j=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                maxy=max(maxy,j-i);
                while(i<j && mp[nums[j]]>k){
                    if(mp[nums[i]]==1){
                        mp.erase(nums[i]);
                    }else{
                        mp[nums[i]]--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(mp.size()!=0){
            maxy=max(maxy,j-i);
        }
        return maxy;
    }
};