/*
    Each binary bit of an integer can only represent 2 states, 0 or 1.
    However, we need to represent the sum of the j-th bit of all integers traversed
    so far modulo 3.
    Therefore, we can use two integers a && b to represent it.

    A(i)  B(i)  C(i)   new A(i)  new B(i)
    0     0     0      0         0
    0     0     1      0         1
    0     1     0      0         1
    0     1     1      1         0
    1     0     0      1         0
    1     0     1      0         0
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int a = 0, b = 0;

        for (int c : nums) {
            int aa = (~a & b & c) | (a & ~b & ~c);
            int bb = ~a & (b ^ c);
            a = aa;
            b = bb;
        }
        return b;
    }
};