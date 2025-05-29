#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        //we need some kind of window
        int left = 0;
        int right = 0;
        //window is [left, right] both inclusive
        int max_window_size = 0;

        unordered_set<char> window_elements;
        //this contains all the chars in the window

        int n = s.size();

        while (right < n) {
            if (window_elements.find(s[right]) == window_elements.end()) {
                window_elements.insert(s[right]);
                max_window_size = max(max_window_size, right - left + 1);
                right++;
            } else {
                window_elements.erase(s[left]);
                left++;
            }
        }

        return max_window_size;

    }

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we need some kind of window
        int left = 0;
        int right = 0;
        //window is [left, right] both inclusive
        int max_window_size = 0;

        unordered_set<char> window_elements;
        //this contains all the chars in the window

        int n = s.size();

        while (right < n) {
            //not present
            if (window_elements.find(s[right]) == window_elements.end()) {
                window_elements.insert(s[right]);
                max_window_size = max(max_window_size, right - left + 1);
                right++;

            //present
            } else {
                window_elements.erase(s[left]);
                left++;
            }
        }

        return max_window_size;

    }
};

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}