class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len= nums.size();
        vector<int> temp;
        int ele= nums[0];
        int count=1;
        temp.push_back(ele);
        for(int i=0; i<len; i++){
            if(nums[i]!= ele){
                temp.push_back(nums[i]);
                ele= nums[i];
                count++;
            }
        }
        while(temp.size()<=len){
            temp.push_back(9);
        }
        int len2=0;
        while(len2<len){
            nums[len2]=temp[len2];
            len2++;
        }
        return count;
        
    }
};

// better approach
#include<vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
