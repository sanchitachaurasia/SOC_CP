#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t, mx, mx_i, mn, mn_i;
	cin >> n;

	// initialize
	cin >> t;
	mn = t;
	mx = t;
	mn_i = 0;
	mx_i = 0;

	for (int i = 1; i < n; i++) {
		cin >> t;
		// include equality to get rightmost i
		if (t <= mn) {
			mn = t;
			mn_i = i;
		}
		// exclude equality to get leftmost i
		if (t > mx) {
			mx = t;
			mx_i = i;
		}
	}
	
	// if no crossover, simply add; otherwise subtract one for common swap
	if (mn_i > mx_i) cout << mx_i + n - 1 - mn_i;
	else cout << mx_i + n - 1 - mn_i - 1;
}