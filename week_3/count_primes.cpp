class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime;
        vector<bool> checked(n, false);
        for (long long i = 2; i < n; i++) {
            if (checked[i])
                continue;
            prime.push_back(i);
            for (long long  j = i * i; j < n; j += i) {
                checked[j] = true;
            }
        }
        return prime.size();
    }
};