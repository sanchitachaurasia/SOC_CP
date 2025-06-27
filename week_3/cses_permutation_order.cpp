#include <bits/stdc++.h>
using namespace std;

vector<long long> fact(21);

void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
}

void find_kth_permutation(int n, long long k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    k--;  // Convert to 0-based index

    vector<int> result;
    for (int i = 0; i < n; i++) {
        long long f = fact[n - i - 1];
        int idx = k / f;
        k %= f;

        result.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}

void find_rank_of_permutation(int n, vector<int>& perm) {
    vector<bool> used(n + 1, false);
    long long rank = 1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 1; j < perm[i]; j++) {
            if (!used[j]) count++;
        }
        rank += count * fact[n - i - 1];
        used[perm[i]] = true;
    }

    cout << rank << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    compute_factorials();

    int t;
    cin >> t;
    while (t--) {
        int type, n;
        cin >> type >> n;
        if (type == 1) {
            long long k;
            cin >> k;
            find_kth_permutation(n, k);
        } else {
            vector<int> perm(n);
            for (int i = 0; i < n; i++) cin >> perm[i];
            find_rank_of_permutation(n, perm);
        }
    }

    return 0;
}
