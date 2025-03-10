class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); 
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums1[a] < nums1[b]; 
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        int j = 0; 
        for (int idx : indices) {
            while (j < n && nums1[indices[j]] < nums1[idx]) {
                pq.push(nums2[indices[j]]);
                sum += nums2[indices[j]];
                
                if (pq.size() > k) {
                    sum -= pq.top(); 
                    pq.pop();
                }
                j++;
            }
            
            ans[idx] = sum;
        }

        return ans;
    }
};

// https://leetcode.com/problems/choose-k-elements-with-maximum-sum/
