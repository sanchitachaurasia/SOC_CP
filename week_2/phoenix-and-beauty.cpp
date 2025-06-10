#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> uniq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            uniq.insert(a[i]);
        }
 
        if ((int)uniq.size() > k) {
            cout << -1 << '\n';
        } else {
            vector<int> pattern(uniq.begin(), uniq.end());
            while ((int)pattern.size() < k)
                pattern.push_back(1);
 
            vector<int> result;
            while ((int)result.size() < 10000 && (int)result.size() < n * k) {
                for (int i = 0; i < (int)pattern.size(); ++i)
                    result.push_back(pattern[i]);
            }
 
            cout << result.size() << '\n';
            for (int num : result)
                cout << num << ' ';
            cout << '\n';
        }
    }
    return 0;
}
