class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSum = 0; 
        int cumulativeSum = 0; 
        for (int num : nums){
            cumulativeSum += num;
            minSum = min(minSum, cumulativeSum);
        }
        return 1 + abs(minSum);
    }
};