/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mI=0,end=mountainArr.length()-1;
        while(mI<=end){
            int mid=mI+(end-mI)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                mI=mid+1;
            } 
            else{
                end=mid-1;
            }
        }
        int start=0,ans=-1;
        end=mI;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target){
                ans=mid;
                end=mid-1;
            }
            else if(mountainArr.get(mid)>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        if(ans!=-1){
            return ans;
        }
        start=mI,end=mountainArr.length()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target){
                ans=mid;
                end=mid-1;
            }
            else if(mountainArr.get(mid)<target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};Stone Game VI