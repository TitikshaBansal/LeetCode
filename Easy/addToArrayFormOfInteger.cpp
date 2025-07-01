class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        int carry = 0;

        while (i >= 0 || k > 0) {
            int digit = k % 10;
            int sum = digit + carry + (i >= 0 ? num[i] : 0);
            if (i >= 0) num[i] = sum % 10;
            else num.insert(num.begin(), sum % 10);
            carry = sum / 10;
            k /= 10;
            i--;
        }

        if (carry) num.insert(num.begin(), carry);
        return num;
    }
};


// https://leetcode.com/problems/add-to-array-form-of-integer/
