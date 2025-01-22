class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        int lenA = a.length(), lenB = b.length();
        vector<int> indicesA, indicesB, result;

        for (int i = 0; i <= n - lenA; i++) {
            if (s.substr(i, lenA) == a) indicesA.push_back(i);
        }

        for (int i = 0; i <= n - lenB; i++) {
            if (s.substr(i, lenB) == b) indicesB.push_back(i);
        }

        int j = 0;
        for (int i : indicesA) {
            while (j < indicesB.size() && indicesB[j] < i - k) {
                j++;
            }
            int temp = j;
            while (temp < indicesB.size() && indicesB[temp] <= i + k) {
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/
