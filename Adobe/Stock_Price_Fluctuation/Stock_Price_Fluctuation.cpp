class StockPrice {
public:
    map<int,int> stock,prices;
    pair<int,int> curr = {-1,-1};
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp >= curr.first) curr = {timestamp,price};
        if(stock.find(timestamp) != stock.end()){
            int old = stock[timestamp];
            prices[old]--;
            if(prices[old] == 0) prices.erase(old);
        }
        prices[price]++;
        stock[timestamp] = price;
    }
    
    int current() {
        return curr.second;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */