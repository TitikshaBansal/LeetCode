class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); 
        deque<pair<int, int>> dq;
        
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nx = x + dirX[d], ny = y + dirY[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int new_cost = dist[x][y] + grid[nx][ny];

                    if (new_cost < dist[nx][ny]) {
                        dist[nx][ny] = new_cost;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny}); 
                        } else {
                            dq.push_back({nx, ny});  
                        }
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
