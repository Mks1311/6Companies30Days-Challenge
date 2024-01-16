class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int x, int y) {
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans.push_back({i,j});
            }
        }
        sort(ans.begin(),ans.end(),[&](vector<int>&a,vector<int>&b){
            return (abs(x-a[0])+abs(y-a[1])<abs(x-b[0])+abs(y-b[1]));
        });
        return ans;
    }
};