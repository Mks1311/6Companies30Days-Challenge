#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<access_times.size();i++){
            string a=access_times[i][1];
            int min=stoi(a.substr(0,2))*60+stoi(a.substr(2,2));
            mp[access_times[i][0]].push_back(min);
        }
        vector<string>res;
        for(auto i:mp){
            if(i.second.size()<3){
                continue;
            }
            vector<int>time=i.second;
            sort(time.begin(),time.end());
            for(int j=0;j<time.size()-2;j++){
                if(time[j+2]-time[j]<60){
                    res.push_back(i.first);
                    break;
                }
            }
        }
        return res;
    }
};