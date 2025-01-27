class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValueFreq; // {key -> {value, frequency}}
    unordered_map<int, list<int>> freqToKeys;         // {frequency -> list of keys}
    unordered_map<int, list<int>::iterator> keyToIter; // {key -> iterator in freqToKeys}
    
    void updateFrequency(int key) {
        int freq = keyToValueFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        
        if (freqToKeys[freq].empty() && freq == minFreq) {
            freqToKeys.erase(freq);
            minFreq++;
        }
        
        keyToValueFreq[key].second++;
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = --freqToKeys[freq + 1].end();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyToValueFreq.find(key) == keyToValueFreq.end()) return -1;

        updateFrequency(key);
        return keyToValueFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValueFreq.find(key) != keyToValueFreq.end()) {
            keyToValueFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        if (keyToValueFreq.size() == capacity) {
            int lfuKey = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();

            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);

            keyToValueFreq.erase(lfuKey);
            keyToIter.erase(lfuKey);
        }

        keyToValueFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyToIter[key] = --freqToKeys[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// https://leetcode.com/problems/lfu-cache/
