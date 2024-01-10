class Solution {
public:
    bool isPal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string &s1,string &s2,string &s,int &ans){
        if(i>=s.size()){
            if(isPal(s1) && isPal(s2)){
                int prod=s1.size()*s2.size();
                ans=max(ans,prod);
            }
            return;
        }
        solve(i+1,s1,s2,s,ans);
        s1+=s[i];
        solve(i+1,s1,s2,s,ans);
        s1.pop_back();
        s2+=s[i];
        solve(i+1,s1,s2,s,ans);
        s2.pop_back();
    }
    int maxProduct(string s) {
        int ans=0;
        string s1="",s2="";
        solve(0,s1,s2,s,ans);
        return ans;
    }
};