class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(auto i : row){
            matrix[i].assign(matrix[i].size(),0);
        }
        for(auto i : col){
            for(int j=0; j<matrix.size(); j++){
                matrix[j][i]=0;
            }
        }
    }
};
