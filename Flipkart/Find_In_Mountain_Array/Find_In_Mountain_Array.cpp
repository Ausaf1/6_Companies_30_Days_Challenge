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
    int binaryL(MountainArray &mountainArr,int s,int e,int target){
         while(s<=e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==target) 
                return mid;
           else if(mountainArr.get(mid)<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }
    int binaryR(MountainArray &mountainArr,int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target)
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n-1,peak;
        while(s < e){
            int mid = (s + e) >> 1;
            if(mountainArr.get(mid + 1) > mountainArr.get(mid)){
                s = mid + 1;
                peak = mid + 1;
            }
            else e = mid;
        }
        int left = binaryL(mountainArr,0,peak,target);
        int right = binaryR(mountainArr,peak,n-1,target);
        return left >= 0 ? left : right;
    }
};