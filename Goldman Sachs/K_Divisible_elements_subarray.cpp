#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int currC=0;
            vector<int>temp;
            for(int j=i;j<nums.size();j++){
                temp.push_back(nums[j]);
                if(nums[j]%p==0) currC++;
                if(currC<=k && st.find(temp)==st.end()) cnt++;
                st.insert(temp);
            }
        }
        return cnt;
    }
};