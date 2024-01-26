class Solution {
public:
    long long M=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int mini=pq.top();
            pq.pop();
            mini++;
            pq.push(mini);
        }
        long long res=1;
        while(!pq.empty()){
            res*=pq.top();
            res%=M;
            pq.pop();
        }
        return (int)res;
    }
};