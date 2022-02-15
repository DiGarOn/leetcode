#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int k = 0;
        int k_ma = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            char a = s[i];
            if (last[a] == -1) {
                k += 1;
            } else {
                //[last[a] + 1; i]
                left = max(left, last[a] + 1);
                k = i - left + 1;
            }
            last[a] = i;
            k_ma = max(k_ma, k);
        }
        return k_ma;
    }
};