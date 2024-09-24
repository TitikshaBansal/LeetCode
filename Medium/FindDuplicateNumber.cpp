class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};


// optimized solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            slow= nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/
