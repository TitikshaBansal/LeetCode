class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string merge = "";

        while (i < word1.size() && j < word2.size()) {
            if (word1.substr(i) > word2.substr(j)) {
                merge += word1[i++];
            } else {
                merge += word2[j++];
            }
        }
        
        merge += word1.substr(i);
        merge += word2.substr(j);

        return merge;
    }
};

// https://leetcode.com/problems/largest-merge-of-two-strings/
