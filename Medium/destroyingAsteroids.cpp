class Solution {
public:
    bool asteroidsDestroyed(int initial, vector<int>& asteroids) {
        long long mass = initial;
        sort(asteroids.begin(), asteroids.end());
        for(int curr : asteroids){
            if(mass < curr) return false;
            mass += curr;
        }
        return true;
    }
};

// https://leetcode.com/problems/destroying-asteroids/
