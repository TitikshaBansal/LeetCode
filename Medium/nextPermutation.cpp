// using inbuilt function
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// better approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        // finding the dip, where we need to change.
        for(int i = n-2; i >= 0; --i){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        
        if(index == -1){
            // if there is no dip.
            sort(nums.begin(), nums.end());
        } else{
            // if dip present.
            // finding the smallest element greater than the dip element. and swapping it with dip element.
            for(int i= n-1; i>index; --i){
                if(nums[i] > nums[index]){
                    swap(nums[i] , nums[index]);
                    break;
                }
            }
            // sorting the elements after the dip.
            sort(nums.begin()+index+1, nums.end());
        }
    }
};


// https://leetcode.com/problems/next-permutation/
