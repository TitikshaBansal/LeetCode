 class Solution {
public:
    int maxArea(vector<int>& height) {
        int vol= INT_MIN;
        int s=0, e= height.size()-1;
        while(s<e){
            int l= min(height[s], height[e]);
            int b= e-s;
            int temp= l*b;
            vol= max(vol, temp);
            if(height[s]<height[e]) s++;
            else e--;
        }
        return vol;
    }
};
