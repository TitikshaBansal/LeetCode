class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> rows, cols;
        for(auto& b : buildings){
            int x = b[0], y = b[1];
            rows[x].insert(y);
            cols[y].insert(x);
        }

        int covered = 0;

        for(auto& b : buildings){
            int x = b[0], y = b[1];
            auto& row = rows[x];
            auto& col = cols[y];

            bool hasLeft = false, hasRight = false, hasUp = false, hasDown = false;
            
            auto it = row.lower_bound(y);
            if(it!= row.begin()) hasLeft=true;

            it = row.upper_bound(y);
            if(it != row.end()) hasRight = true;

            auto it2 = col.lower_bound(x);
            if(it2!= col.begin()) hasUp = true;

            it2 = col.upper_bound(x);
            if(it2!= col.end()) hasDown = true;
            if(hasLeft && hasRight && hasUp && hasDown) covered++;
        }
        return covered;
    }
};

// https://leetcode.com/problems/count-covered-buildings/
