class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                position[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCount(m, n); 
        vector<int> colCount(n, m); 
        
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            auto [r, c] = position[num]; 
            rowCount[r]--;
            colCount[c]--;
            if (rowCount[r] == 0 || colCount[c] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};

// https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20
