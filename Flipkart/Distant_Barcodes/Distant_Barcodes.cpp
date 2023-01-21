class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        if(n == 0 || n == 1) return barcodes;
        map<int,int> mp;
        for(auto i : barcodes) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto it: mp) pq.push({it.second,it.first});
        barcodes.clear();
        while(pq.top().first > 0){
            pair<int,int> p = pq.top();
            pq.pop();
            barcodes.push_back(p.second);
            p.first--;
            pair<int,int> p2 = pq.top();
            pq.pop();
            if(p2.first > 0){
                barcodes.push_back(p2.second);
                p2.first--;
            }
            pq.push(p),pq.push(p2);
        }
        return barcodes;
    }
};