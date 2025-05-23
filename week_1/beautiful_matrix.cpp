#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n, t;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> t;
			if (t) {
				m = i; n = j; break;
			}
		}
	}
	cout << abs(m - 2) + abs(n - 2);
}