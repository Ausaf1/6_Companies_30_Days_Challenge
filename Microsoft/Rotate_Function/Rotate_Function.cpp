class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0,original = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            original += i*nums[i];
        }
        long mx = original,n = nums.size();
        for(int i = n-1;i >= 0;i--){
            original += sum - (nums[i] * n);
            mx = max(mx,original);
        }
        return mx;
    }
};