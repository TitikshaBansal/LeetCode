class Solution {
public:
    bool check(vector<int> arr){
        for(int num : arr) if(num != 0) return false;
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        for (int index = 0; index < n; index++) {
            while (sum + differenceArray[index] < nums[index]) {
                k++;
                if (k > queries.size()) return -1;
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            sum += differenceArray[index];
        }
        return k;
    }
};

// https://leetcode.com/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-03-13
