class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1)); 
        queue<pair<int, int>> q; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0; 
                    q.push({i, j}); 
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1; 
                    q.push({nx, ny}); 
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22
