#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int row,col;
    set<pair<int,int>>st;
    Solution(int m, int n) {
        row=m;
        col=n;
    }
    vector<int> flip() {
        int i=rand()%row;
        int j=rand()%col;
        if(st.find({i,j})==st.end()){
            st.insert({i,j});
            return {i,j};
        }else return flip();
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */