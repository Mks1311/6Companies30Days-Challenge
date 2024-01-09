class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool chk=true;
                int last=-1;
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j) continue;
                    if(last>=nums[k]){
                        chk=false;
                        break;
                    }else last=nums[k];
                }
                if(chk) ans++;
            }
        }
        return ans;
    }
};