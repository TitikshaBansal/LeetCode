class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i=0; i<boxes.length(); i++){
            int moves = 0;
            for(int j=0; j<boxes.length(); j++){
                if(boxes[j] == '1') moves += abs(i-j);
            }
            ans.push_back(moves);
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06
