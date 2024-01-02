#include <bits/stdc++.h>
using namespace std;
class DataStream {
public:
    int val=0,Kth=0,Cnt=0;
    DataStream(int value, int k) {
        this->val=value;
        this->Kth=k;
    }
    
    bool consec(int num) {
        if(num==val) Cnt++;
        else Cnt=0;
        return Cnt>=Kth;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */