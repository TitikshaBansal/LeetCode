class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<= 'z'; ch++){
                    word[i] = ch;
                    if(s.count(word)){
                        q.push({word, step +1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

// https://leetcode.com/problems/word-ladder/
