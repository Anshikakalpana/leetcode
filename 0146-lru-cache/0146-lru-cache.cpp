class LRUCache {
private:
    int cap;  
  

    list<pair<int, int>> dll;  
    

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        
    }

    int get(int key) {
        // if key not present, return -1
        if (mp.find(key) == mp.end())
            return -1;

       
        auto it = mp[key];
        int value = it->second;

        dll.erase(it);

        
        dll.push_front({key, value});

        mp[key] = dll.begin();

    
        return value;
    }

    void put(int key, int value) {
        // if key already exists
        if (mp.find(key) != mp.end()) {
         
            dll.erase(mp[key]);
        }
        // if cache is full and key is new
        else if (dll.size() == cap) {
          
            auto lru = dll.back();

            
            mp.erase(lru.first);

            // remove LRU node from list
            dll.pop_back();
        }

  //   updated key-value pair at front (MRU)
        dll.push_front({key, value});

        // store iterator of the new node in the map
        mp[key] = dll.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */