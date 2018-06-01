class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)return 0;
        int ans = 0;
        int left = 1;
        int right = (int)height.size()-2;
        int leftHeight = height[0];
        int rightHeight = height[(int)height.size()-1];
        while(left <= right){
            if(leftHeight < rightHeight){
                if(height[left] < leftHeight){
                    ans += leftHeight - height[left];
                }else{
                    leftHeight = height[left];
                }
                ++left;
            }else{
                if(height[right] < rightHeight){
                    ans += rightHeight - height[right];
                }else{
                    rightHeight = height[right];
                }
                --right;
            }
        }
        return ans;
    }
};
