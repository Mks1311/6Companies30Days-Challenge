class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans,idx_a,idx_b;
        int x=s.size(),y=a.size(),z=b.size();
        for(int i=0;i<=(x-y);i++){
            if(s.substr(i,y)==a) idx_a.push_back(i);
        }
        for(int i=0;i<=(x-z);i++){
            if(s.substr(i,z)==b) idx_b.push_back(i);
        }
        for(int i=0;i<idx_a.size();i++){
            for(int j=0;j<idx_b.size();j++){
                if(abs(idx_a[i]-idx_b[j])<=k) {
                    ans.push_back(idx_a[i]);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
//          vector<int>res;
//         int i=0,n=s.size();
//         while(i<n){
//             size_t fndA=s.find(a,i);
//             if(fndA==string::npos) break;
//             int j=0;
//             while(j<n){
//                 size_t fndB=s.find(b,j);
//                 if(fndB==string::npos) break;
//                 if( (fndB-fndA)<=k || (fndA-fndB)<=k ) {
//                     res.push_back(fndA);
//                     break;
//                 }
//                 j=fndB+1;
//             }
//             i=fndA+1;
//         }
//         return res;
    }
};