class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (int ans : answers) m[ans]++;

        int count = 0;
        for (auto& [x, freq] : m) {
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize; 
            count += groups * groupSize;
        }

        return count;
    }
};

// https://leetcode.com/problems/rabbits-in-forest/?envType=daily-question&envId=2025-04-20
