class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        bool vowel = false, consonant = false;
        for (char c : word) {
            if (!isdigit(c) && !isalpha(c)) return false;
            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') vowel = true;
                else consonant = true;
            }
        }
        return vowel && consonant;
    }
};


// https://leetcode.com/problems/valid-word/?envType=daily-question&envId=2025-07-15
