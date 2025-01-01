class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<int> row = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> col = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        
        int m = img.size();
        int n = img[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long sum = 0; 
                int count = 0; 
                for (int k = 0; k < 9; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        count++;
                    }
                }
                ans[i][j] = sum / count; 
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/image-smoother/
