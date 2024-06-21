class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i=0; i<s.length(); i++){
            if(s[i]>= 'A' && s[i]<= 'Z') temp.push_back(s[i]- 'A'+ 'a');
            else if(s[i]>= 'a' && s[i]<= 'z') temp.push_back(s[i]);
            else if(s[i]>='0' && s[i]<='9')temp.push_back(s[i]);
        }
        int start=0, end= temp.length()-1;
        while(start<=end){
            if(temp[start]!= temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
