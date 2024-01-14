class Solution {
public:
    static bool comp(pair<int,string>a,pair<int,string>b){
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(string i:words){
            mp[i]++;
        }
        vector<pair<int,string>>mp1;
        for(auto i:mp){
            mp1.push_back({i.second,i.first});
        }
        sort(mp1.rbegin(),mp1.rend(),comp);
        vector<string>res;
        int i=0;
        while(k--&&i<mp1.size()){
            res.push_back(mp1[i++].second);
        }
        return res;
    }
};