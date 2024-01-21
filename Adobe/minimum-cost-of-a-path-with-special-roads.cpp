class Solution {
public:
    int minimumCost(vector<int>& st, vector<int>& tar, vector<vector<int>>& spcl) {
        map<string,int>vis;
        queue<vector<int>>q;
        q.push({st[0],st[1],0});
        vis[to_string(st[0])+"-"+to_string(st[1])]=0;
        int minCost=INT_MAX;
        while(!q.empty()){
            vector<int>curr=q.front();
            q.pop();
            if(curr[2]>=minCost) continue;
            int costDir=curr[2]+abs(curr[0]-tar[0])+abs(curr[1]-tar[1]);
            minCost=min(minCost,costDir);
            for(int i=0;i<spcl.size();i++){
                int x1=spcl[i][0],y1=spcl[i][1],x2=spcl[i][2],y2=spcl[i][3],cost=spcl[i][4];
                int costX2Y2=curr[2]+abs(curr[0]-x1)+abs(curr[1]-y1)+cost;
                string pos=to_string(x2)+"-"+to_string(y2);
                if(vis.count(pos) && vis[pos]<=costX2Y2) continue;
                vis[pos]=costX2Y2;
                q.push({x2,y2,costX2Y2});
            }
        }
        return minCost;
    }
};