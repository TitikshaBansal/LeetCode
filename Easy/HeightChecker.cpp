class Solution {
    
public:
    int heightChecker(vector<int>& heights) {
        // storing vector in a temporary vector and merge sorting it.
        vector<int> temp= heights;
        sort(heights.begin(), heights.end());
        int count=0;
        // comparing the temporary vector with the original vector.
        for(int i=0; i<heights.size(); i++){
            if( heights[i]!= temp[i]){
                count++;
            }
        }
        return count;
    }
};
