#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Maximum: One big team, rest are 1-member teams
    long long big_team = n - (m - 1);
    long long kmax = big_team * (big_team - 1) / 2;

    // Minimum: Divide as evenly as possible
    long long x = n / m;
    long long r = n % m;
    long long kmin = r * x * (x + 1) / 2 + (m - r) * x * (x - 1) / 2;

    cout << kmin << " " << kmax << "\n";
    return 0;
}
