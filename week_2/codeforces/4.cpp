#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long max_team = n - m + 1;
    long long kmax = max_team * (max_team - 1) / 2;

    long long a = n / m;
    long long b = n % m;
    long long kmin = b * (a + 1) * a / 2 + (m - b) * a * (a - 1) / 2;

    cout << kmin << " " << kmax << "\n";
}
