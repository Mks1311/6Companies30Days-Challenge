class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        map<int,vector<int>>mp;
        for(int i=0;i<seats.size();i++){
            mp[seats[i][0]].push_back(seats[i][1]);
        }
        int ans=(n-mp.size())*2;
        for(auto i:mp){
            bool flag=false;
            vector<bool>book(11,true);
            for(auto j:i.second){
                book[j]=false;
            }
            if(book[2]&&book[3]&&book[4]&&book[5]){
                ans++;
                flag=true;
            } 
            if(book[6]&&book[7]&&book[8]&&book[9]) {
                ans++;
                flag=true;
            }
            if(!flag){
                if(book[4]&&book[5]&&book[6]&&book[7]) ans++;
            }
        }
        return ans;
    }
};