class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int num : asteroids) {
            bool destroyed = false;

            while (!st.empty() && num < 0 && st.top() > 0) {
                if (st.top() < -num) {
                    st.pop(); // Smaller right-moving asteroid explodes
                    continue;
                } else if (st.top() == -num) {
                    st.pop(); // Both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Left-moving asteroid explodes
                    break;
                }
            }

            if (!destroyed) st.push(num);
        }

        vector<int> result(st.size());
        for(int i = st.size()-1; i>=0; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

// https://leetcode.com/problems/asteroid-collision/
