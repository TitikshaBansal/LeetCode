class Solution {
private:
    int m, n, totalCells;
    unordered_map<int, int> flippedMap;

public:
    Solution(int m, int n) : m(m), n(n), totalCells(m * n) {}

    vector<int> flip() {
        int randIndex = rand() % totalCells; 
        --totalCells; 
        int mappedIndex = flippedMap.count(randIndex) ? flippedMap[randIndex] : randIndex;

        flippedMap[randIndex] = flippedMap.count(totalCells) ? flippedMap[totalCells] : totalCells;

        return {mappedIndex / n, mappedIndex % n};
    }

    void reset() {
        flippedMap.clear(); 
        totalCells = m * n; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

// https://leetcode.com/problems/random-flip-matrix/
