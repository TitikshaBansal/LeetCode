class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        int j = 0;
        while(i>=0 && j< matrix[0].size()){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) j++;
            else if(matrix[i][j] > target) i--;
        }
        return false;
    }
};

// one more approach
// but earlier is better imo
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int e = matrix.size()*matrix[0].size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) e = mid-1;
            else s= mid+1;
        }
        return false;
    }
};

// https://leetcode.com/problems/search-a-2d-matrix/
