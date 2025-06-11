class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for(int i = num.length(); i>= 0; i--){
            if((num[i] - '0') % 2 == 1){
                index = i;
                break;
            }
        }
        if(index == -1) return "";
        return num.substr(0, index+1);
    }
};


// https://leetcode.com/problems/largest-odd-number-in-string/
