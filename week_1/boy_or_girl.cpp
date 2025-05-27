#include <bits/stdc++.h>

using namespace std;

int main() {
	unordered_set<char> uniq;
	char c;

	while (cin >> c) {
		uniq.insert(c);
	}

	cout << ((uniq.size() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!");
}