class Solution {
public:
    int countCollisions(string directions) {
        int ans=0,right=0,stay=0;
        for(char c:directions){
            if(c=='R') {
                right++;
                stay=0;
            }
            else if(c=='L'){
                if(stay) ans+=1;
                else if(right){
                    ans+=2;
                    ans+=(right-1);
                    stay=1;
                    right=0;
                }
            }else{
                ans+=right;
                right=0;
                stay=1;
            }
        }
        return ans;
    }
};