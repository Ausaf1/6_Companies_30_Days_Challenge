class Solution {
private:
    bool isPossible(string s,string b){
        bool t = 0;
        for(int i = 0;i < 8;i++){
            if(s[i] != b[i]){
                if(t) return 0;
                t = 1;
            }
        }
        return t;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<int,string>> q;
        q.push({0,startGene});
        int len = bank.size();
        while(!q.empty()){
            pair<int,string> t = q.front();
            if(t.second == endGene) return t.first;
            q.pop();
            for(int i = 0;i < len;i++){
                if(isPossible(t.second,bank[i])){
                    q.push({t.first + 1,bank[i]});
                    bank.erase(bank.begin() + i);
                    i--,len--;
                }
            }
        }
        return -1;
    }
};