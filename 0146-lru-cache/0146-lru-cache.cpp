class LRUCache {
public:
    int cap;
    list<int> dll;  
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // move key to front
        dll.erase(mp[key].second);
        dll.push_front(key);
        mp[key].second = dll.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
        // key already exists
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key].second);
        }
        else if (dll.size() == cap) {
            int lru = dll.back();
            dll.pop_back();
            mp.erase(lru);
        }

        dll.push_front(key);
        mp[key] = {value, dll.begin()};
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */