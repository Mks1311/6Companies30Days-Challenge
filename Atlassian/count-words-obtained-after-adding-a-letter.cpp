class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<string>st;
        for(int i=0;i<startWords.size();i++){
            sort(startWords[i].begin(),startWords[i].end());
            st.insert(startWords[i]);
        }
        int cnt=0;
        for(int i=0;i<targetWords.size();i++){
            for(int j=0;j<targetWords[i].size();j++){
                string target=targetWords[i].substr(0,j)+targetWords[i].substr(j+1);
                sort(target.begin(),target.end());
                if(st.find(target)!=st.end()){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};