class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int dis=arr1.size();
        for(int i:arr1){
            bool flag=false;
            for(int j:arr2){
                if(abs(i-j)<=d){
                    flag=true;
                    break;
                }
            }
            if(flag) dis--;
        }
        return dis;
    }
};