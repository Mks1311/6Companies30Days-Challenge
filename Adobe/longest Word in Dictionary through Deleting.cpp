class Solution {
public:
    static bool comp(string&s1,string&s2){
        if(s1.size()==s2.size()){
            return s1<s2;
        }
        return s1.size()>s2.size();
    }
    bool eq(string&s,string&dicS){
        int i=0,j=0;
        while(i<s.size()&&j<dicS.size()){
            if(s[i]==dicS[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j>=dicS.size() && i<=s.size()) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),comp);
        for(auto i:dictionary){
            if(eq(s,i)) return i;
        }
        return "";
    }
};