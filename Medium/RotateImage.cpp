class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i< n; i++){
            for(int j =i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0 ; i< n; i++){
            int s=0, e= m-1;
            while(s<e){
                swap(matrix[i][s++], matrix[i][e--]);
            }
        }
    }
};

// https://leetcode.com/problems/rotate-image/
