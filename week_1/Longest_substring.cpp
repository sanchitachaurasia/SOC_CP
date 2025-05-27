class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int curr = 0;
        vector<char> store;

        for (int i = 0; i < s.length(); i++) {

            for (int j=0;j<store.size();j++) {
                if (s[i] == store[j]) {
                    store.erase(store.begin(),store.begin()+j+1);
                    if (curr > max) {
                        max = curr;
                    }
                    curr = curr-j-1;

                    break;
                }
            }
            store.push_back(s[i]);
            curr++;
        }
        if (curr > max) {
            max = curr;
            curr = 0;
        }

        return max;
    }
};