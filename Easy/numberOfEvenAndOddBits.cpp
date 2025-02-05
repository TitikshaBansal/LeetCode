class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd= 0;
        string s = bitset<64> (n).to_string();
        const auto loc1 = s.find('1');
        if(loc1 != string::npos) s = s.substr(loc1);
        else s = "0";
        int index= 0;
        for(int i= s.length()-1; i>=0; i--){
            if(s[i]=='1'){
                if(index%2==0) even++;
                else odd++;
            }
            index++;
        }

        return {even,odd};
    }
};

// https://leetcode.com/problems/number-of-even-and-odd-bits/
