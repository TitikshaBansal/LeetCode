class Solution {
public:
    int n,m;
    bool check(vector<vector<char>>& board, string word, int i, int j, int pos){
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        if(board[i][j] != word[pos]) return false;
        if (pos == word.size()-1) return true;
        char temp = board[i][j];
        board[i][j] = '#';
        bool left = check(board, word, i-1, j, pos+1);
        bool right = check(board, word, i+1, j, pos+1);
        bool top = check(board, word, i, j-1, pos+1);
        bool buttom = check(board, word, i, j+1, pos+1);
        board[i][j] = temp;
        return left || right || top || buttom ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]) flag = check(board, word, i,j,0);
                if(flag) return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/word-search/
