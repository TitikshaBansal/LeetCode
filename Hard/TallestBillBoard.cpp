class Solution {

public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> m;
        m[0] = 0;

        for (int i : rods) {
            unordered_map<int, int> current(m);

            for (auto [diff, height] : current) {
                m[diff + i] = max(m[diff + i], height);
                m[diff - i] = max(m[diff - i], height + i);
            }
        }

        return m[0];
    }
};
