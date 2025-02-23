class Solution {
public:
    int count = 0;
    string result = "";

    void generate(int n, int k, string s) {
        if (s.length() == n) {
            count++;
            if (count == k) result = s;
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch) { 
                generate(n, k, s + ch);
                if (!result.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        generate(n, k, "");
        return result;
    }
};

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19
