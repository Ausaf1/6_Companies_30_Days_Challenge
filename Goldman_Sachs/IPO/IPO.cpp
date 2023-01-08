class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = profits.size();
        for(int i = 0;i < n;i++) v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());
        priority_queue<int> q;
        int ans = 0,i = 0;
        while(i < n && k){
            if(w >= v[i].first) q.push(v[i++].second);
            else{
                if(q.empty()) return w;
                w += q.top();
                q.pop();
                k--;
            }
        }
        while(k-- && !q.empty()){
            w += q.top();
            q.pop();
        }
        return w;
    }
};