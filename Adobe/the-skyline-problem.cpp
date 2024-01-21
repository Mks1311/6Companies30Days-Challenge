class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>pts;
        for(auto pt:buildings){
            pts.push_back({pt[0],-pt[2]});
            pts.push_back({pt[1],pt[2]});
        }
        sort(pts.begin(),pts.end());
        multiset<int>st{0};
        vector<vector<int>>ans;
        int ongH=0;
        for(int i=0;i<pts.size();i++){
            int currP=pts[i].first;
            int currH=pts[i].second;
            if(currH<0){
                st.insert(-currH);
            }else st.erase(st.find(currH));
            auto sttop=*st.rbegin();
            if(ongH!=sttop){
                ongH=sttop;
                ans.push_back({currP,ongH});
            }
        }
        return ans;
    }
};