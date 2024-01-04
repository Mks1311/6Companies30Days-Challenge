#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // Time Complexity:O(n+n(log n))
        //                :O(n(log n))
        // Space Complexity=O(n);
        //         map<int,int>mp;
        //         for(auto i:arr) mp[i]++;
        //         int r=0,m=0;
        //         for(int i=1;i<=n;i++){
        //             if(mp[i]==0){
        //                 m=i;
        //             }
        //             if(mp[i]==2){
        //                 r=i;
        //             }
        //             if(r!=0 && m!=0) break;
        //         }
        //         return {r,m};
        //
        // Time Complexity:O(n+n)
        //                 :O(n)
        // Space Complexity=O(1);
        sort(arr.begin(), arr.end());
        int missing = 0, repeating = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1] && repeating == 0)
            {
                cnt--;
                repeating = arr[i];
            }
            if (missing == 0 && arr[i] != cnt)
            {
                missing = cnt;
                cnt--;
            }
            if (repeating != 0 && missing != 0)
                break;
            cnt++;
        }
        if (missing == 0)
            missing = n;
        return {repeating, missing};
    }
};