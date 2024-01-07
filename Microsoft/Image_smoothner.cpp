class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        int x[8]{-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                int sm=img[i][j],cnt=1;
                for(int d=0;d<8;d++){
                    int dx=i+x[d];
                    int dy=j+y[d];
                    if(dx>=0 && dx<n && dy>=0 && dy<m){
                        sm+=img[dx][dy];
                        cnt++;
                    }
                }
                res[i][j]=(sm/cnt);
            }
        }
        return res;
    }
};