class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // Remove from the end if k > 0
        while (k-- > 0 && !stack.empty()) {
            stack.pop_back();
        }

        // Build result and remove leading zeros
        string result = "";
        while (!stack.empty()) {
            if (result.empty() && stack.front() == '0') {
                stack.pop_front();
            } else {
                result += stack.front();
                stack.pop_front();
            }
        }

        return result.empty() ? "0" : result;
    }
};

// https://leetcode.com/problems/remove-k-digits/
