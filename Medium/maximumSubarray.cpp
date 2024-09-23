// first approac...............
// kedane's algo...........................
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = INT_MIN;
        int sum =0;
        for(int num : nums){
            sum += num;
            ans = max(ans, sum);
            if(sum < 0) sum =0;
        }
        return ans;
    }
};


// second approach............
// divide and concure
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        for(int i = mid-1, curSum = 0; i >= L; i--){
            curSum += A[i];
            leftSum=max(leftSum, curSum);
        }
        for(int i = mid+1, curSum = 0; i <= R; i++){
            curSum += A[i];
            rightSum = max(rightSum, curSum);
        }        
        return max({ maxSubArray(A, L, mid-1), maxSubArray(A, mid+1, R), leftSum + A[mid] + rightSum });
    }	
};

// https://leetcode.com/problems/maximum-subarray/
