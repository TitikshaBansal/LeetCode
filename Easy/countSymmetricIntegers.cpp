class Solution {
public:
    bool isValid(string num){
        int n = num.length();
        int sum = 0;
        int sum1 = 0;
        for(int i=0; i<n; i++){
            if(i<n/2) sum1+= num[i]-'0';
            sum += num[i]-'0';
        }
        return sum == 2*sum1;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(low; low<=high; low++){
            string num = to_string(low);
            if(num.length()%2==1) continue;
            else if(isValid(num)) count++;
        }
        return count;
    }
};

// https://leetcode.com/problems/count-symmetric-integers/?envType=daily-question&envId=2025-04-11
