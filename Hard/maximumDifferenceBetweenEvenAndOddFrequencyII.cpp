const int INF = 1e9;  
struct Fenw {
    int n;
    vector<int> tree;
    Fenw(int n): n(n), tree(n+1, INF) { }
    
    void update(int pos, int value) {
        pos++; 
        for(; pos <= n; pos += pos & -pos) {
            tree[pos] = min(tree[pos], value);
        }
    }
    int query(int pos) {
        int res = INF;
        pos++; // 1-indexed
        for(; pos > 0; pos -= pos & -pos) {
            res = min(res, tree[pos]);
        }
        return res;
    }
};

class Solution {
public:
    int maxDifference(string s, int k) {
        string zynthorvex = s;
        
        int n = s.size();
        vector<vector<int>> pref(n+1, vector<int>(5, 0));
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            for (int d2 = 0; d2 < 5; d2++) {
                pref[i+1][d2] = pref[i][d2];
            }
            pref[i+1][d]++;
        }
        int ans = -INF;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if(a == b) continue;
                vector<int> A(n+1), B(n+1), pA(n+1), pB(n+1), X(n+1);
                for (int i = 0; i <= n; i++) {
                    A[i] = pref[i][a];
                    B[i] = pref[i][b];
                    pA[i] = A[i] & 1;
                    pB[i] = B[i] & 1;
                    X[i] = A[i] - B[i];
                }
                vector<vector<Fenw>> fenw(2, vector<Fenw>(2, Fenw(n+1)));
                
                int ptr = 0;  
                for (int j = 0; j <= n; j++) {
                    while (ptr <= j - k) {
                        int u = pA[ptr], v = pB[ptr];
                        fenw[u][v].update(B[ptr], X[ptr]);
                        ptr++;
                    }
                    if(j < k) continue;
                    int reqA = 1 - pA[j];
                    int reqB = pB[j];
                    if(B[j] > 0) {
                        int bestX = fenw[reqA][reqB].query(B[j]-1);
                        if(bestX < INF) {
                            int cand = (A[j] - B[j]) - bestX;
                            ans = max(ans, cand);
                        }
                    }
                } 
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/
