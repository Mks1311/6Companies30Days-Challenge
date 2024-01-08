class Solution {
public:
    string getHint(string secret, string guess) {
        int n=guess.size(),bull=0,cow=0;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) bull++;
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto i:mp1){
            cow+=min(i.second,mp2[i.first]);
        }
        return to_string(bull)+'A'+to_string(cow)+'B';
    }
};