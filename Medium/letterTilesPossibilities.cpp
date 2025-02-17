class Solution {
public:
    set<string> uniqueSequences;
    void dfs(string& tiles, string current, vector<bool>& used) {
        if (!current.empty()) { 
            uniqueSequences.insert(current);
        }
        
        for (int i = 0; i < tiles.length(); i++) {
            if (used[i]) continue; 
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;  

            used[i] = true;  
            dfs(tiles, current + tiles[i], used);  
            used[i] = false; 
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());  
        vector<bool> used(tiles.length(), false);  
        dfs(tiles, "", used); 
        return uniqueSequences.size(); 
    }
};

// https://leetcode.com/problems/letter-tile-possibilities/?envType=daily-question&envId=2025-02-17
