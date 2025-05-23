#include <bits/stdc++.h>

using namespace std;

int main() {
	// n, k - read input
	// ans - store answer
	// t - temp var
	// a_k - k-th nums

	int n, k, ans, t, a_k;
	cin >> n >> k;

	ans = 0;
	a_k = 0;

	// read first k values, only checking >0 condition
	for (int i = 0; i < k; i++) {
		cin >> t;
		if (!t) {
			cout << ans;
			return 0;
		}
		ans++;
	}

	// check only case of t==a_k now since it must be >0
	a_k = t;
	while ((cin >> t) && (t == a_k)) {
		ans++;
	}

	cout << ans;
}