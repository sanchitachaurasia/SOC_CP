// Binomial Coefficient using DP+  memoization

#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int getnCk(int n, int k, vector<vector<int>> &memo) {
  
    // k can not be grater then k so we
  	// return 0 here
    if (k > n)
        return 0;
  
  	// base condition when k and n are 
  	// equal or k = 0
    if (k == 0 || k == n)
        return 1;
  	if(memo[n][k] != -1) return memo[n][k];
  
    // Recurvie add the value and store to memorize table
    return memo[n][k] = getnCk(n - 1, k - 1, memo) 
      					+ getnCk(n - 1, k, memo);
}
int binomialCoeff(int n, int k) {
  	
  	// Create table for memorization
	vector<vector<int>> memo(n + 1, vector<int> (k + 1, -1));
  
  	return getnCk(n, k, memo);
}
int main() {
    int n = 5, k = 2;
    cout << binomialCoeff(n, k);
    return 0;
}
