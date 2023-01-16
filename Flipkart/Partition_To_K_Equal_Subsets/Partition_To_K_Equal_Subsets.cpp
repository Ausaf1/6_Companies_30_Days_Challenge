class Solution {
public:
    bool backtrack(vector<int> &nums,int k,int target,int currSum,int i,int n,vector<int> &visited){
        if(k == 1) return true;
        if(i >= n) return false;
        if(currSum == target) return backtrack(nums,k-1,target,0,0,n,visited);
        for(int j = i;j < n;j++){
            if(!visited[j] && nums[j] + currSum <= target){
                visited[j] = true;
                if(backtrack(nums,k,target,currSum + nums[j],j+1,n,visited)) return true;
                visited[j] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(),sum = accumulate(nums.begin(),nums.end(),0);
        if(n < k || sum % k) return false;
        vector<int> visited(n,false);
        return backtrack(nums,k,sum/k,0,0,n,visited);
    }
};