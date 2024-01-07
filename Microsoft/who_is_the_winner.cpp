#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,int k){
        if(n==1) return 1;
        return (solve(n-1,k)+(k-1))%n +1; 
    }
    int findTheWinner(int n, int k) {
        // return solve(n,k);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=(ans+k)%i;
        }
        return ans+1;
        // queue<int>qt;
        // for(int i=1;i<=n;i++){
        //     qt.push(i);
        // }
        // while(qt.size()>1){
        //     int K=k-1;
        //     while(K--){
        //         int ele=qt.front();
        //         qt.push(ele);
        //         qt.pop();
        //     }
        //     qt.pop();
        // }
        // return qt.front();
    }
};