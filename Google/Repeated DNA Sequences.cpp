class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>temp;
        string t;
        int i=0,j=0;
        while(i<s.size()){
            if(t.size()<10 && j<s.size()){
                t+=s[j++];
            }
            else if(s.size()>=10){
                temp.push_back(t);
                t.erase(t.begin());
                i++;
            }else break;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<temp.size();i++){
            mp[temp[i]]++;
        }
        vector<string>ans;
        for(auto i:mp){
            if(i.second>1) ans.push_back(i.first);
        }  
        return ans;
    }
};