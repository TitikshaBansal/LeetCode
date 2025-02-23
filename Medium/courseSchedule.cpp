class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course(n);
        vector<int> pre(n,0);
        for(vector<int> curr : prerequisites){
            course[curr[1]].push_back(curr[0]);
            pre[curr[0]]++;
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
        return ans.size()==n;
    }
};

// https://leetcode.com/problems/course-schedule/
