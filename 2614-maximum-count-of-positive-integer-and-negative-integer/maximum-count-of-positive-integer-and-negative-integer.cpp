class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto [first, last] = equal_range(nums.begin(), nums.end(), 0);
        return max(distance(nums.begin(), first), distance(last, nums.end()));
    }
};