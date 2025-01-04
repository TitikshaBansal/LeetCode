class Solution {
public:
    string getHint(string secret, string guess) {
        int bull =0, cow =0;
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]) {
                bull++;
                secret.erase(secret.begin()+i);
                guess.erase(guess.begin()+i);
                i--;
            }
        }
        for(int i=0; i< secret.length(); i++){
            int idx = guess.find(secret[i]);
            if(idx != string::npos) {
                cow++;
                guess.erase(guess.begin()+ idx);
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

// https://leetcode.com/problems/bulls-and-cows/
