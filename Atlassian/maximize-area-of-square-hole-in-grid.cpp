class Solution {
public:
    int cons(vector<int>& Bars){
        int cons=0,temp=1;
        for(int i=0;i<Bars.size()-1;i++){
            if(Bars[i+1]-Bars[i]==1){
                temp++;
            }else{
                cons=max(cons,temp+1);
                temp=1;
            }
        }
        return max(cons,temp+1);
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int cons_a=cons(hBars);
        int cons_b=cons(vBars);
        int res=min(cons_a,cons_b);
        return res*res;
        
    }
};