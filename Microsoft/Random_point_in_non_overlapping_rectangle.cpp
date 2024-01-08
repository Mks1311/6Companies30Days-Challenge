class Solution {
public:
    vector<vector<int>>r;
    int i=0,x,y;
    Solution(vector<vector<int>>& rects) {
        r=rects;
        x=r[i][0];
        y=r[i][1];
    }
    
    vector<int> pick() {
        vector<int>res={x,y};
        x++;
        if(x>r[i][2]){
            x=r[i][0];
            y++;
        }
        if(y>r[i][3]){
            if(i+1<r.size()) i++;
            else i=0;
            x=r[i][0];
            y=r[i][1];
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */