class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums) mp[i]++;
        int ans=0;
        for(auto i:mp){
            cout<<i.first<<' '<<i.second<<endl;
            if(k==0){
                if(i.second>1) ans++;
            }
            else if(mp.find(i.first+k)!=mp.end()) ans++;
        }
        return ans;
        // int cnt=0,n=nums.size();
        // set<pair<int,int>>st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int maxy=max(nums[i],nums[j]);
        //         int mini=min(nums[i],nums[j]);
        //         if(maxy-mini==k && st.find({maxy,mini})==st.end()) {
        //             cnt++;
        //             st.insert({maxy,mini});
        //         }
        //     }
        // }
        // return  cnt;
    }
};