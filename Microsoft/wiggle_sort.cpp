class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        vector<int>temp(nums);
        sort(temp.begin(),temp.end());
        int high=n-1;
        for(int i=0;i<n;i++){
            if(i%2!=0) nums[i]=temp[high--];
        }
        for(int i=0;i<n;i++){
            if(i%2==0) nums[i]=temp[high--];
        }
    }
};