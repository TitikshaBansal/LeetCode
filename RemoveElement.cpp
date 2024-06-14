class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!= val){
                temp.push_back(nums[i]);
            }
        }
        int k= temp.size();
        int j=0;
        for(j; j<k; j++){
            nums[j]=temp[j];
        }
        while(j<nums.size()){
            nums[j++]=0;
        }
        return k;
