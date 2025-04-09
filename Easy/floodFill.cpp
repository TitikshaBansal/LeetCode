class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor){
        int m = image.size();
        int n = image[0].size();

        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor)
            return;

        image[sr][sc] = color;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        for(int i=0; i<4; i++){
            dfs(image, sr + dx[i], sc + dy[i], color, originalColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};

// https://leetcode.com/problems/flood-fill/
