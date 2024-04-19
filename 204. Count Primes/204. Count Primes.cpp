class Solution {
public:
    int countPrimes(int n) {

        // Create a vector of boolean values, filled with '1', representing prime status
        vector<bool> isPrime(n, true);

        // Init a count of prime numbers
        int primeCount = 0;

        // Use Sieve of Eratosthenes algo, to find all primes less than N
        for (int j = 2; j < n; ++j) {
            // If the number is marked as prime
            if (isPrime[j]) {
                ++primeCount;

                // Mark all multiples of J as not prime starting J^2 to avoid redundant work
                for (long long i = (long long)j * j; i < n; i += j) {
                    isPrime[i] = false;
                }
            }
        }
        return primeCount;
    }
};