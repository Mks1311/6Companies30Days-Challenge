class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),comp);
        for(int i=0;i<e.size();i++){
            cout<<e[i][0]<<' '<<e[i][1]<<endl;
        }
        vector<int>lis;
        for(int i=0;i<e.size();i++){
            if(lis.empty() || lis.back()<e[i][1]) lis.push_back(e[i][1]);
            else{
                auto it=lower_bound(lis.begin(),lis.end(),e[i][1]);
                *it=e[i][1];
            }
        }
        return lis.size();
    }
};