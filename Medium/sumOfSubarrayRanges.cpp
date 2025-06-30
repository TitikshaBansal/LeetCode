class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n, -1), nextGreater(n, n);
        vector<int> prevSmaller(n, -1), nextSmaller(n, n);

        // Next Greater
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Prev Greater
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Next Smaller
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Prev Smaller
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            maxSum += left * right * (long long)nums[i];

            left = i - prevSmaller[i];
            right = nextSmaller[i] - i;
            minSum += left * right * (long long)nums[i];
        }

        return maxSum - minSum;
    }
};

// https://leetcode.com/problems/sum-of-subarray-ranges/
