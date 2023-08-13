/*
the last step is either 1 step or 2 steps.
If the last step is step 1, you can go from the beginning to step 3 in 3 ways
If the last step is 2 steps, you can go from the beginning to 2 in 2 ways.
You need to get the N-th Fibonacci number
*/
class Solution {
public:
    int climbStairs(int n) {
        int fib[50];
        fib[1] = 1;
        fib[2] = 2;
        for (int j = 3; j <= n; ++j) {
            fib[j] = fib[j - 1] + fib[j - 2];
        }
        return fib[n];
    }
};