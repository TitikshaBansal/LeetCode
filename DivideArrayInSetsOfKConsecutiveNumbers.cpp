class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        map<int,int> m;
        for(int i: nums){
            m[i]++;
        }
        for(auto & [num, count]: m){
            if(count>0){
                for(int i=1; i<k; i++){
                    if(m[num+i]<count){
                        return false;
                    }
                    m[num+i]-= count;
                }
            }
        }
        return true;
    }
};
