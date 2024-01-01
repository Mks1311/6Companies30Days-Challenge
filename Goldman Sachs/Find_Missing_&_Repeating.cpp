class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int>mp;
        for(auto i:arr) mp[i]++;
        int r=0,m=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                m=i;
            }
            if(mp[i]==2){
                r=i;
            }
            if(r!=0 && m!=0) break;
        }
        return {r,m};
    }
};