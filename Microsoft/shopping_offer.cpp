class Solution {
public:
    int solve(vector<int>& p, vector<vector<int>>& s, vector<int>& need,int idx,int n,int m){
        if(idx==m){
            int temp=0;
            for(int i=0;i<n;i++){
                temp+=need[i]*p[i];
            }
            return temp;
        }
        bool flag=true;
        for(int j=0;j<n;j++){
            if(s[idx][j]>need[j]){
                flag=false;
                break;
            }
        }
        int op1=INT_MAX;
        if(flag){
            for(int j=0;j<n;j++){
                need[j]-=s[idx][j];
            }
            op1=s[idx][n]+solve(p,s,need,idx,n,m);
            for(int j=0;j<n;j++){
                need[j]+=s[idx][j];
            }
        }
        int op2=solve(p,s,need,idx+1,n,m);
        return min(op1,op2);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size(),m=special.size();
        int ans=solve(price,special,needs,0,n,m);
        return ans;
    }
};