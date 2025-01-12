class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> numbers(nums.begin(), nums.end());
        auto it = numbers.end();
        if (numbers.size() > 2){
            advance(it, -3);
            return *it;
        } 
        return *(numbers.rbegin());
    }
};