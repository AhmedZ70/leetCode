class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counter; 
        for (int num : nums){
            counter[num]++;
        }
        for (auto [_, num] : counter){
            if (num % 2 != 0){
                return false;
            }
        }
        return true;
    }
};