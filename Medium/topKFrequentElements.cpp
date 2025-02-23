class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) freqMap[num]++; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (auto& it : freqMap) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop(); 
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// https://leetcode.com/problems/top-k-frequent-elements/
