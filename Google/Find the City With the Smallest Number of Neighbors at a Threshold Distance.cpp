class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjMat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0],des=edges[i][1];
            adjMat[src][des]=edges[i][2];
            adjMat[des][src]=edges[i][2];
        }
        for(int i=0;i<n;i++) adjMat[i][i]=0;
        for(int via=0;via<n;via++){
            for(int src=0;src<n;src++){
                for(int des=0;des<n;des++){
                    if(adjMat[src][via]!=INT_MAX && adjMat[via][des]!=INT_MAX)
                        adjMat[src][des]=min(adjMat[src][des],adjMat[src][via]+adjMat[via][des]);
                }
            }
        }
        int city=0,cityCnt=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=cityCnt){
                cityCnt=cnt;
                city=i;
            }
        }
        return city;
    }
};