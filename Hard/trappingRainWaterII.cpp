class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0; 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        int totalWater = 0;
        vector<int> directions = {-1, 0, 1, 0, -1}; 

        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int height = cell[0], x = cell[1], y = cell[2];

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d];
                int ny = y + directions[d + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    totalWater += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }
        return totalWater;
    }
};

// https://leetcode.com/problems/trapping-rain-water-ii/
