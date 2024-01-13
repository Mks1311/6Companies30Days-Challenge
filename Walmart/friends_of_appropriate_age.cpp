class Solution {
public:
bool check(int x,int y){
    if(y<=0.5*x+7) return false;
    if(y>x) return false;
    if(y>100 && x<100) return false;
    return true;
}
    int numFriendRequests(vector<int>& ages) {
        int ans=0,n=ages.size();
        sort(ages.begin(),ages.end());
        for(int i=0;i<n;i++){
            int low=upper_bound(ages.begin(),ages.end(),(ages[i]*0.5)+7)-ages.begin();
            int high=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
            cout<<low<<' '<<high<<endl;
            ans+=max(high-low-1,0);
        }
        return ans;

        // vector<int>mp(121,0);
        // for(int i:ages) mp[i]++;
        // for(int i=0;i<121;i++){
        //     for(int j=0;j<121;j++){
        //         if(check(i,j)){
        //             if(i!=j) ans+=mp[i]*mp[j];
        //             else ans+=mp[i]*(mp[i]-1);
        //         }
        //     }
        // }
        // return ans;
    
        
        // for(int x=0;x<n;x++){
        //     for(int y=x+1;y<n;y++){
        //         if(ages[x]<=(0.5*ages[y]+7) || ages[x]>ages[y] || (ages[x]>100&&ages[y]<100)){
        //             continue;
        //         }
        //         else if(ages[x]==ages[y])ans+=2;
        //         else ans++;
        //     }
        // }
        // return ans;
    }
};