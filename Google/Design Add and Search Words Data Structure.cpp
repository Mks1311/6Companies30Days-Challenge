class WordDictionary {
public:
    unordered_map<int,unordered_map<char,vector<string>>>store;
    bool match(const string&s1,const string&s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i] && s2[i]!='.') return false;
        }
        return true;
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        store[word.size()][word[0]].push_back(word);
    }
    
    bool search(string word) {
        if(store.find(word.size())==store.end()) return false;
        if(word[0]=='.'){
            for(auto &j:store[word.size()]){
                for(auto &i:j.second){
                    if(match(i,word)) return true;
                }
            }
            return false;
        }
        if(store[word.size()].find(word[0])==store[word.size()].end()) return false;
        auto &j=store[word.size()][word[0]];
        for(auto &i:j) if(match(i,word)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */