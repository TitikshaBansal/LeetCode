class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        vector<pair<int, int>> zero, one;
        for(int i=0; i< n; i++){
            for(int j=0; j<m; j++){
                int live = 0;
                for(int k=0; k<8; k++){
                    int row = i+ directions[k].first;
                    int col = j+ directions[k].second;
                    if(row>=0 && row<n && col>=0 && col<m && board[row][col] == 1) live++;
                }
                if (board[i][j] == 1 && (live<2 || live>3)) zero.push_back({i,j});
                else if(board[i][j]==0 && live==3) one.push_back({i,j});
            }
        }
        for(auto i : one) board[i.first][i.second]=1;
        for(auto i : zero) board[i.first][i.second]=0;
    }
};
