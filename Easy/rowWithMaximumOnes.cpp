class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = 0;
        int count = 0;
        for(int i =0; i< mat.size(); i++){
            vector<int> curr = mat[i];
            int one = accumulate(curr.begin(), curr.end(), 0);
            if(one > count){
                count = one;
                index = i;
            }
        }
        return {index, count};
    }
};

// https://leetcode.com/problems/row-with-maximum-ones/
