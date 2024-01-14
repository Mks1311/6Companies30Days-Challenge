class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<pair<int,char>>mp(256,{0,' '});
        for(int i=0;i<s.length();i++){
            mp[s[i]].first++;
            mp[s[i]].second=s[i];
        }
        sort(mp.rbegin(),mp.rend());
        string ans="";
        for(int i=0;i<mp.size();i++){
            if(mp[i].first==0) continue;
            ans+=string(mp[i].first,mp[i].second);
        }
        mp.clear();
        return ans;
    }
};