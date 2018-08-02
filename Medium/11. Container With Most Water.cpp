class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        int start = 0, end = size-1;
        while(start < end){
            int h = min(height[start],height[end]);
            ans = max(ans, h * (end-start));
            if(height[start] < height[end]){
                start++;
            }else if(height[start] > height[end]){
                end--;
            }else{
                start++;
                end--;
            }
        }
        return ans;
    }
};
