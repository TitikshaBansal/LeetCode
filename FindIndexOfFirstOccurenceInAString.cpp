class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; i< haystack.length(); i++){
            if(haystack[i]==needle[0]){
                if( needle== haystack.substr(i, needle.length())){
                    return i;
                }
            }
        }
        return -1;
    }
};
