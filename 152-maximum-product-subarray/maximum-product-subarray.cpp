class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0]; 
        int minProduct = nums[0]; 
        int result = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            int num = nums[i]; 
            if (num < 0){
                swap(maxProduct, minProduct);
            }
            maxProduct = max(num, num * maxProduct);
            minProduct = min(num, num * minProduct);
            
            result = max(result, maxProduct); 
        }
        return result;
    }
};