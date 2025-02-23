class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course(n);
        vector<int> pre(n,0);
        for(vector<int> i : prerequisites) {
            course[i[1]].push_back(i[0]);
            pre[i[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<n; i++) if(pre[i]==0) q.push(i);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int i : course[curr]){
                pre[i]--;
                if(pre[i]==0) q.push(i);
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};

// https://leetcode.com/problems/course-schedule-ii/
