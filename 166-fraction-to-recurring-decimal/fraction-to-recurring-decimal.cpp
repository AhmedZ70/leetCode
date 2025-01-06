class Solution {

using ll = long long;

public:
    string fractionToDecimal(int numerator, int denominator) {
        // handle 0 numerator
        if (numerator == 0) return "0"; 
        // handle sign
        string result; 
        if (numerator < 0 ^ denominator < 0){
            result += "-";
        }
        // convert to pos values to avoid over flow
        ll num = abs((ll)numerator); 
        ll den = abs((ll)denominator);
        // add integer part to result string 
        result += to_string(num/den);
        // store remainder if it's zero return result
        ll remainder = num % den;
        unordered_map<ll, int> remMap; 
        if (remainder == 0) return result;
        result += ".";

        while (remainder != 0){
            // found same remainder
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
        // else add "." to result 
        // long division
        // if same remainder again then insert "(" at after the "."
    }
};

// 4 / 333
//          0.(012)012012 (.012) repeating 
//        ------ r = 67
//     333| 4.00000
//        | 0   
//          ---
//          400
//          333
//          ---
//          670
//          666
//          ---
//          400

// map: 
