#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    string printMinNumberForPattern(string S){
        string res;
        S+='I';
        for(int i=0;i<S.size();i++){
            res+='0';
        }
        int cnt=1;
        for(int i=0;i<S.size();i++){
            if(S[i]=='I'){
                res[i]=('0'+cnt);
                cnt++;
                int j=i-1;
                while(j>=0 && S[j]=='D'){
                    res[j]=('0'+cnt);
                    cnt++;
                    j--;
                }
            }
        }
        return res;
    }
};