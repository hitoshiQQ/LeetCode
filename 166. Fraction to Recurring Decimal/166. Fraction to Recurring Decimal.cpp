class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        // Case when the fraction is zero
        if (numerator == 0) {
            return "0";
        }

        // Result string to accumulate the answer
        string res;

        // Determine if res is negative, and if true, prepend a minus sign
        // XOR func is true if the characters are different
        bool is_negative = (numerator > 0) ^ (denominator > 0);
        if (is_negative) {
            res += "-";
        }

        // Convert both parts to positive longlong to avoid overflow
        long long numeratorLL = std::llabs(static_cast<long long>(numerator));
        long long denominatorLL = std::llabs(static_cast<long long>(denominator));

        // Add the integer part to the RES
        res += std::to_string(numeratorLL / denominatorLL);

        // Calculate the remainder and process the fractional part
        numeratorLL %= denominatorLL;
        if (numeratorLL == 0) {
            return res;
        }

        // Since there is a fractional part, append the decimal point
        res += ".";

        // Map to store numerators, and their respective positions in case of repeat
        std::unordered_map<long long, int> numerators_map;

        while (numeratorLL) {
            // Store the position of the numerator before the multiply
            numerators_map[numeratorLL] = res.size();

            // Update the numerator to get next digit after the decemal point
            numeratorLL *= 10;

            // Add the digit to RES
            res += std::to_string(numeratorLL / denominatorLL);

            // Update reminder
            numeratorLL %= denominatorLL;

            // If numerators repeats, a repeating cycle is found
            if (numerators_map.count(numeratorLL)) {

                // insert the opening parenthesis at the start index of the repeat part
                int start_index = numerators_map[numeratorLL];
                res.insert(start_index, "(");

                // append the closing parenthesis
                res += ")";
                break;
            }
        }
        // Return decimal representation of the fraction
        return res;
    }
};