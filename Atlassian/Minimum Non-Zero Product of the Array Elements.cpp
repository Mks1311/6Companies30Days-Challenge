class Solution {
public:
    long long M=1e9+7;
    long long mod(long long a){
        return (a%M + M)%M;
    }
    long long mul(long long a,long long b){
        return mod(mod(a)*mod(b));
    }
    long long modPow(long long a,long long b){
        if(b==0) return 1LL;
        if(b==1) return a;
        a%=M;
        long long res=1;
        while(b){
            if(b&1) res=mul(res,a);
            b/=2;
            a=mul(a,a);
        }
        return res;
    }
    int minNonZeroProduct(int p) {
        long long maxi=(1LL<<p)-1;
        return ((maxi%M)*modPow(maxi-1,maxi/2)%M)%M;
    }
};