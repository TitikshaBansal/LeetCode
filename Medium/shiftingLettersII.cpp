class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> netShifts(n + 1, 0);  
        for (auto& shift : shifts) {
            int i = shift[0];
            int j = shift[1];
            int direction = shift[2];
            netShifts[i] += (direction ? 1 : -1);  
            netShifts[j + 1] -= (direction ? 1 : -1);
        }
        for (int i = 1; i < n; i++) {
            netShifts[i] += netShifts[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int shift = netShifts[i] % 26; 
            if (shift < 0) shift += 26;  
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};

// https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05
