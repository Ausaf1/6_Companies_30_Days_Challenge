class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums.size(),q = queries.size();
    vector<int> ans;
    for(int i = 0;i < q;i++){
        priority_queue<pair<string,int>> pq;
        int l = queries[i][0],a = queries[i][1];
        for(int k = 0;k < n;k++){
           int t = nums[k].length() - a;
           string b = nums[k].substr(t,a);
           if(pq.size() < l) pq.push({b,k});
           else{
               if(pq.top().first > b){
                   pq.pop();
                   pq.push({b,k});
               }
           }
        }
        ans.push_back(pq.top().second);
     }
     return ans;
    }
};