class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = (nums.size()-1)/2;
        return nums[mid];
    }
};

// better approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int ele;
        for(int num : nums){
            if(count == 0)  ele = num;
            if(ele == num) count++;  
            else count--;
        }
        return ele;
    }
};

// https://leetcode.com/problems/majority-element/
