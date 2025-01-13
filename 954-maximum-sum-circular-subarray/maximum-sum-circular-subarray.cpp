class Solution {
private: 
    int maxSubarraySum(vector<int>& nums){
        int maxSum = nums[0]; 
        int currMax = 0;
        for (int num : nums){
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);
        }
        return maxSum;
    }
    int minSubarraySum(vector<int>& nums){
        int minSum = nums[0]; 
        int currMin = 0;
        for (int num : nums){
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }
        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); 
        int maxSum = maxSubarraySum(nums); 
        int minSum = minSubarraySum(nums);

        int maxSumCircular = totalSum - minSum;

        if (maxSumCircular == 0) return maxSum;

        return max(maxSum, maxSumCircular);
    }
};