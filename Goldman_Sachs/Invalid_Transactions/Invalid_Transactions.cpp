class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        int n = transactions.size();
        vector<int> time,amount;
        vector<string> name,city;
        int flag = 0;
        for(auto str : transactions){
            stringstream ss(str);
            string st;
            while(getline(ss,st,',')){
                if(flag == 0){
                    name.emplace_back(st);
                    flag = 1;
                }
                else if(flag == 1){
                    time.emplace_back(stoi(st));
                    flag = 2;
                }
                else if(flag == 2){
                    amount.emplace_back(stoi(st));
                    flag = 3;
                }
                else if(flag == 3){
                    city.emplace_back(st);
                    flag = 0;
                }
            }
        }
        int j = 0;
        for(auto it : amount){
            if(it > 1000){
                res.push_back(transactions[j]);
            }
            j++;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(name[i] == name[j] && city[i] != city[j]){
                    if(abs(time[i] - time[j]) <= 60){
                        if(amount[i] <= 1000){
                            res.push_back(transactions[i]);
                            break;
                        } 
                    }
                }
            }
        }
        return res;
    }
};