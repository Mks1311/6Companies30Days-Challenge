class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot=1,n=preorder.size(),i=0;
        while(i<n){
            if(slot==0) return false;
            if(preorder[i]==',') {
                i++;
            }
            else if(preorder[i]=='#'){
                slot-=1;
                i++;
            }
            else{
                slot+=1;
                while(i<n && preorder[i]!=',') i++;
                i++;
            }
        }
        return slot==0;
    }
};