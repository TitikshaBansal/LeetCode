class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            string temp = to_string(num);
            if(temp.length()%2 == 0) count++;
        }
        return count;
    }
};

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30
