class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (string& word : words) freqMap[word]++;
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) return a.first > b.first; 
            return a.second < b.second; 
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);

        for (auto& [word, freq] : freqMap) minHeap.push({word, freq});
        
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};

// https://leetcode.com/problems/top-k-frequent-words/
