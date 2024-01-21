class Solution {
public:
    int eqVal(pair<int,int>&p1,pair<int,int>&p2,pair<int,int>p3){
        int x1=p1.first,x2=p2.first,x3=p3.first;
        int y1=p1.second,y2=p2.second,y3=p3.second;
        return ((y3-y2)*(x2-x1))-((y2-y1)*(x3-x2));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        deque<pair<int,int>>lower,upper;
        for(auto &point:trees){
            int l=lower.size(),u=upper.size();
            // pair<int,int>p3=;
            while(l>=2 && eqVal(lower[l-2],lower[l-1],{point[0],point[1]})<0){
                l--;
                lower.pop_back();
            }
            while(u>=2 && eqVal(upper[u-2],upper[u-1],{point[0],point[1]})>0){
                u--;
                upper.pop_back();
            }
            lower.push_back({point[0],point[1]});
            upper.push_back({point[0],point[1]});
        }
        set<pair<int,int>>st;
        for(auto i:lower) st.insert(i);
        for(auto i:upper) st.insert(i);
        vector<vector<int>>ans;
        for(auto i:st) ans.push_back({i.first,i.second});
        return ans;
    }
};