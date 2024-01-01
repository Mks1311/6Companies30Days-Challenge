// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

// Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
// Output: 4
// Explanation: 
// We can distribute the first 4 natural numbers into arr1 and arr2.
// arr1 = [1] and arr2 = [2,3,4].
// We can see that both arrays satisfy all the conditions.
// Since the maximum value is 4, we return it.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll s=1,e=1e12,ans=0;
        ll lcm=(1LL*divisor1*divisor2)/__gcd(divisor1,divisor2);
        while(s<=e){
            ll mid=(s+e)/2;
            ll DivByBoth=mid/lcm;
            ll DivByA=mid/divisor2 - DivByBoth;
            ll DivByB=mid/divisor1 - DivByBoth;
            ll neither=max(0LL,uniqueCnt1-DivByA)+max(uniqueCnt2-DivByB,0LL);
            if(mid-DivByA-DivByB>=neither+DivByBoth){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return (int)ans;
    }
};

int main(){
    int divisor1,divisor2,uniqueCnt1,uniqueCnt2;
    cin>>divisor1>>divisor2>>uniqueCnt1>>uniqueCnt2;
    Solution sol;
    cout<<sol.minimizeSet(divisor1,divisor2,uniqueCnt1,uniqueCnt2)<<endl;
}