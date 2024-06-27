class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size()==k) return points;
        priority_queue<pair<double, vector<int>>> maxHeap;
        for(int i=0; i< points.size(); i++){
            int x= points[i][0];
            int y= points[i][1];
            double dist= sqrt((x*x)+(y*y));
            maxHeap.push({dist, points[i]});
            
            if (maxHeap.size() > k) maxHeap.pop();
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
