class LRUCache {
private:
    int capacity;
    list<pair<int,int>> dll; //{key, value}
    unordered_map<int, list<pair<int,int>>::iterator> cache;

public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        dll.splice(dll.begin(), dll, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            // Update value and move to front
            cache[key]->second = value;
            dll.splice(dll.begin(), dll, cache[key]);
            return;
        }
        //If full, remove LRU
        if((int)dll.size() == capacity){
            auto lru = dll.back();
            cache.erase(lru.first);
            dll.pop_back();
        }
        // Insert new Node at front
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */