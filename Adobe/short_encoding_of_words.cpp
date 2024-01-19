class Solution {
public:
    static bool comp(string&s1,string&s2){
        if(s1.size()==s2.size()) return s1>s2;
        return s1.size()>s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        string ref=words[0]+"#";
        for(int i=1;i<words.size();i++){
            string s=words[i]+"#";
            if(ref.find(s)==string::npos){
                ref+=s;
            }
        }
        return ref.size();
    }
};