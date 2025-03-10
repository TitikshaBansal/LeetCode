class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        set<int> available;
        for (int i = 0; i < n; i++) {
            available.insert(i);
        }
        
        int last = INT_MAX;
        int unplaced = 0;
        for (int fruit : fruits) {
            if (fruit >= last) {
                unplaced++;
                continue;
            }
            
            bool placed = false;
            for(auto it = available.begin(); it != available.end(); ++it) {
                int idx = *it;
                if(baskets[idx] >= fruit) {
                    available.erase(it);
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                last = fruit;
                unplaced++;
            }
        }
        return unplaced;
    }
};

// https://leetcode.com/problems/fruits-into-baskets-iii/
