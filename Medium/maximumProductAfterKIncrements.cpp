class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        while (k--) {
            int smallest = minHeap.top();
            minHeap.pop();
            minHeap.push(smallest + 1);
        }
        long long product = 1;
        while (!minHeap.empty()) {
            product = (product * minHeap.top()) % MOD;
            minHeap.pop();
        }

        return product;
    }
};

// https://leetcode.com/problems/maximum-product-after-k-increments/
