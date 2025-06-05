#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD
long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    long long screen_area = 1LL * a * b;
    long long movie_area;

    // Try scaling by width
    if (1LL * a * d <= 1LL * b * c) {
        // Movie fits when width = a
        movie_area = 1LL * a * a * d / c;
    } else {
        // Movie fits when height = b
        movie_area = 1LL * b * b * c / d;
    }

    long long empty_area = screen_area - movie_area;

    // Reduce fraction empty_area / screen_area
    long long g = gcd(empty_area, screen_area);
    empty_area /= g;
    screen_area /= g;

    cout << empty_area << "/" << screen_area << "\n";

    return 0;
}
