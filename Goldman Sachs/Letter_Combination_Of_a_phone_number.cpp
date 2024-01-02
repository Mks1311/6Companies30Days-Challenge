#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string &digits,vector<string> &ans,string op,int idx,map<int,string> &numpad){
        if(idx>=digits.size()){
            ans.push_back(op);
            return;
        }
        int key=digits[idx]-'0';
        string val=numpad[key];
        for(int i=0;i<val.size();i++){
            solve(digits,ans,op+val[i],idx+1,numpad);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()<=0){
            return ans;
        }
        map<int,string>numpad;
        numpad[2]="abc";
        numpad[3]="def";
        numpad[4]="ghi";
        numpad[5]="jkl";
        numpad[6]="mno";
        numpad[7]="pqrs";
        numpad[8]="tuv";
        numpad[9]="wxyz";
        solve(digits,ans,"",0,numpad);
        return ans;
    }
};