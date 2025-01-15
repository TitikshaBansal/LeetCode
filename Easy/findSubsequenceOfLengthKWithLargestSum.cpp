class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums){
            pq.push(i);
            if(pq.size() > k ) pq.pop();
        }   
        unordered_map<int, int> mp;
        while( !pq.empty() ) {
            mp[pq.top()]++;
            pq.pop();
        }
        vector<int> v;
        for(auto i : nums) {
            if( mp[i] > 0 ){
                v.push_back(i);
                mp[i]--;
            }
        }
        return v;
    }
};

// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
