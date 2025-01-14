class Solution {
public:
    using ll = long long; 
    string fractionToDecimal(int numerator, int denominator) {
        // if num = 0 return 0 
        if (numerator == 0) return "0"; 
        string result; 
        if (numerator < 0 ^ denominator < 0){
            result += "-";
        }
        ll num = abs((ll)numerator); 
        ll den = abs((ll)denominator); 
        
        result += to_string(num / den); 
        ll remainder = num % den; 
        if (remainder == 0) return result;
        result += "."; 
        unordered_map<ll, int> remMap; 
        while (remainder != 0){
            if (remMap.find(remainder) != remMap.end()){
                result.insert(remMap[remainder], "("); 
                result += ")";
                break; 
            }
            remMap[remainder] = result.size(); 
            remainder *= 10; 
            result += to_string(remainder / den); 
            remainder %= den; 
        }
        return result;
    }
};