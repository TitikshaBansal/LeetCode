class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i=0; i< matrix.size(); i++){
            int num= INT_MAX;
            for(int j=0; j<matrix[0].size(); j++){
                num= min(num, matrix[i][j]);
            }
            row.insert(num);
        }
        for(int i=0; i< matrix[0].size(); i++){
            int num= INT_MIN;
            for(int j=0; j<matrix.size(); j++){
                num= max(num, matrix[j][i]);
            }
            col.insert(num);
        }
        vector<int> ans;
        for(auto i: row){
            if(col.find(i)!= col.end()) ans.push_back(i);
        }
        return ans;
    }
};
