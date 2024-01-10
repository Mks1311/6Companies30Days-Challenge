class Solution {
public:
    void FloyWar(vector<vector<long long>>&adjMat,vector<char>&o,vector<char>&c,vector<int>&cost){
        for(int i=0;i<o.size();i++){
            int src=o[i]-'a';
            int des=c[i]-'a';
            adjMat[src][des]=min(adjMat[src][des],(long long)cost[i]);
        }
        for(int via=0;via<26;via++){
            for(int src=0;src<26;src++){
                for(int des=0;des<26;des++){
                    if(adjMat[src][via]!=INT_MAX&&adjMat[via][des]!=INT_MAX)
                        adjMat[src][des]=min(adjMat[src][des],adjMat[src][via]+adjMat[via][des]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adjMat(26,vector<long long>(26,INT_MAX));
        FloyWar(adjMat,original,changed,cost);
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            long long price=adjMat[source[i]-'a'][target[i]-'a'];
            if(price==INT_MAX) return -1;
            ans+=price;
        }
        return ans;
    }
};