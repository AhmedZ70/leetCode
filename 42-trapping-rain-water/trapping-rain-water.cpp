class Solution {
public:
    int trap(vector<int>& height) {
        int waterTrapped = 0; 
        int left = 0; 
        int right = height.size() - 1; 
        int leftMax = 0, rightMax = 0; 
        while (left < right){
            if (height[left] < height[right]){
                height[left] > leftMax ? leftMax = height[left] : 
                waterTrapped += (leftMax - height[left]);
                left++; 
            }
            else {
                height[right] > rightMax ? rightMax = height[right]:
                waterTrapped += rightMax - height[right];
                right--; 
            }
        }
        return waterTrapped;
    }
};