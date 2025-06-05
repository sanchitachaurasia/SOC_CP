#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool firstSmallerOrEqual = (long long)a * d <= (long long)b * c;

    int numerator_k, denominator_k;
    if (firstSmallerOrEqual) {
        numerator_k = a;
        denominator_k = c;
    } else {
        numerator_k = b;
        denominator_k = d;
    }

    long long movie_area_num = (long long)numerator_k * numerator_k * c * d;
    long long movie_area_den = (long long)denominator_k * denominator_k;

    long long total_area = (long long)a * b;

    long long empty_area_num = total_area * movie_area_den - movie_area_num;
    long long empty_area_den = movie_area_den * total_area / total_area; 

    long long p = (long long)a * b * denominator_k * denominator_k - movie_area_num;
    long long q = (long long)a * b * denominator_k * denominator_k;

    long long g = gcd(abs(p), q);
    p /= g;
    q /= g;

    cout << p << "/" << q << "\n";

    return 0;
}
