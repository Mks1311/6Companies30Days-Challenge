#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>qt;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    qt.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!qt.empty()){
            auto it=qt.front();
            qt.pop();
            int x=it.first,y=it.second;
            for(int i=0;i<4;i++){
                int xi=x+dx[i],yi=y+dy[i];
                if(xi>=0 && xi<m && yi>=0 && yi<n){
                    if(ans[xi][yi]==-1){
                        ans[xi][yi]=ans[x][y]+1;
                        qt.push({xi,yi});
                    }
                }
            }
        }
        return ans;
    }
};