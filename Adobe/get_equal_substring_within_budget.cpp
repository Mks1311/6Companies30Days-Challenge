class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size(),i=0,j=0,currCost=0,maxi=0;
        for(j;j<n;j++){
            currCost+=abs(s[j]-t[j]);
            while(i<=j && currCost>maxCost){
                currCost-=abs(s[i]-t[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;

    }
};