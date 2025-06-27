#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> factorials(21);

// Precompute factorials
void compute_factorials() {
    factorials[0] = 1;
    for (int i = 1; i <= 20; ++i)
        factorials[i] = factorials[i - 1] * i;
}

// Get k-th permutation (1-based)
vector<int> get_kth_permutation(int n, ll k) {
    vector<int> elements;
    for (int i = 1; i <= n; ++i) elements.push_back(i);
    vector<int> result;
    k--;  // 0-based index for calculation

    for (int i = n; i >= 1; --i) {
        ll fact = factorials[i - 1];
        int index = k / fact;
        result.push_back(elements[index]);
        elements.erase(elements.begin() + index);
        k %= fact;
    }

    return result;
}

// Get permutation index (1-based)
ll get_permutation_index(int n, vector<int>& perm) {
    ll k = 1;
    vector<int> elements;
    for (int i = 1; i <= n; ++i) elements.push_back(i);

    for (int i = 0; i < n; ++i) {
        int pos = find(elements.begin(), elements.end(), perm[i]) - elements.begin();
        k += pos * factorials[n - i - 1];
        elements.erase(elements.begin() + pos);
    }

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_factorials();

    int t;
    cin >> t;
    while (t--) {
        int type, n;
        cin >> type >> n;

        if (type == 1) {
            ll k;
            cin >> k;
            vector<int> perm = get_kth_permutation(n, k);
            for (int x : perm)
                cout << x << " ";
            cout << "\n";
        } else {
            vector<int> perm(n);
            for (int i = 0; i < n; ++i) cin >> perm[i];
            cout << get_permutation_index(n, perm) << "\n";
        }
    }

    return 0;
}
