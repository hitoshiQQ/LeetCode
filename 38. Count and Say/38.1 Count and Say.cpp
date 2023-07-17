/*
We generate all terms from 1 to n.

First two terms are initialized as "1" and "11"
all other terms are generated using the previous terms.

To generate a term using the previous term, we scan the previous term.

When scanning a term, we simply keep track of the number of all consecutive characters.

There is a counter for the same ones
*/

class Solution {
public:
    string countAndSay(int n) {

        //Base case 
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }

        string s = "11";
        for (int j = 3; j <= n; ++j) {
            // in below for loop, previous character is processed in current iteration
            s += '$';
            int len = s.length();

            int co = 1;
            string tmp = "";

            // previous term to find the next term
            for (int i = 1; i < len; ++i) {

                // if current doesn't match
                if (s[i] != s[i - 1]) {
                    tmp += co + '0';
                    tmp += s[i - 1];
                    co = 1;
                }
                else {
                    ++co;
                }
            }
            s = tmp;
        }
        return s;
    }
};