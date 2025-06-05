#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    // Maximum
    long long team_size = n - m + 1;
    long long kmax = team_size * (team_size - 1) / 2;

    // Minimum
    long long x = n / m;
    long long r = n % m;
    long long kmin = r * (x + 1) * x / 2 + (m - r) * x * (x - 1) / 2;

    cout << kmin << " " << kmax << endl;
    return 0;
}
