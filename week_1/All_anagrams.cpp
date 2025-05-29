class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> values;

        int pl = p.length();
        int sl = s.length();
        int store[26] = {0};

        for (char x : p) {
            store[x - 'a']++;
        }

        for (int i = 0; i < sl - pl + 1; i++) {

            int check[26] = {0};
            int sum = 0;
            for (int j = i; j < i + pl; j++) {
                check[s[j] - 'a']++;
            }
            for (int j = i; j < i + pl; j++) {
                if (check[s[j] - 'a'] == store[s[j] - 'a']) {
                    sum++;
                }
            }
            if (sum == pl) {
                values.push_back(i);
            }
        }

        return values;
    }
};