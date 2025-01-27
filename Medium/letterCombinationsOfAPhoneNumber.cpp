class Solution {
private:
    vector<string> digitToLetters = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz" // 9
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = digitToLetters[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);         
            backtrack(digits, index + 1, current, result); 
            current.pop_back();         
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
