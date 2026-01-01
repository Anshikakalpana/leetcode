class StockPrice {
public:
    unordered_map<int, int> u;

    multiset<int> mini;
    multiset<int, greater<int>> maxi;

    priority_queue<pair<int,int>> p; 

    int currTime = 0;

    StockPrice() {}

    void update(int timestamp, int price) {

        // if timestamp already exists
        if (u.find(timestamp) != u.end()) {
            int oldPrice = u[timestamp];
            mini.erase(mini.find(oldPrice));
            maxi.erase(maxi.find(oldPrice));
        }

        u[timestamp] = price;
        mini.insert(price);
        maxi.insert(price);

        p.push({timestamp, price});
        currTime = max(currTime, timestamp);
    }

    int current() {
        // remove stale entries
        while (!p.empty()) {
            auto top = p.top();
            if (u[top.first] == top.second) {
                return top.second;
            }
            p.pop();
        }
        return -1;
    }

    int maximum() {
        return *maxi.begin();
    }

    int minimum() {
        return *mini.begin();
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