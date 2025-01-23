class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> startMasks;
        
        for (const string& word : startWords) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));  // Set the bit corresponding to the letter
            }
            startMasks.insert(mask);
        }
        
        int count = 0;
        
        // Check each string in targetWords
        for (const string& word : targetWords) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));  // Compute the bitmask for the target word
            }
            
            // Try removing each bit from the mask
            for (char ch : word) {
                int modifiedMask = mask & ~(1 << (ch - 'a'));  // Remove the bit for 'ch'
                if (startMasks.find(modifiedMask) != startMasks.end()) {
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};

// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
