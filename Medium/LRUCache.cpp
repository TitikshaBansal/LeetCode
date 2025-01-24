class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; 
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; 

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1; 

        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);

        return it->second; 
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            it->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it);
            return;
        }

        if (cacheList.size() == capacity) {
            auto lru = cacheList.back();
            cacheMap.erase(lru.first);
            cacheList.pop_back(); 
        }

        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// https://leetcode.com/problems/lru-cache/
