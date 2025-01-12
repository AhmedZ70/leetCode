class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN; 
        // first > second > third
        for (int num : nums){
            if (num == first || num == second || num == third){
                continue;
            }
            if (num > first){
                third = second; 
                second = first; 
                first = num;
            }
            else if (num > second){
                third = second; 
                second = num;
            }
            else if (num > third){
                third = num;
            }
        }
        if (third == LONG_MIN){
            return first;
        }
        return third;
    }
};