#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int res_left = 0;
        int res_right = 0;
        string res = "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int right = 0; right < s.size(); right++) {
            for (int left = right; left >= 0; left--){
                if (right == left) {
                    dp[right][left] = true;  
                } else {
                    if ((left+1==right || dp[right-1][left+1] == true) && s[right] == s[left]) {
                        dp[right][left] = true;
                        if (right - left > res_right - res_left) {
                            res_right = right;
                            res_left = left;
                        }
                    } else {
                        dp[right][left] = false;
                    }
                } 
                
            }
        }
        for (int i = res_left; i <= res_right; i++){
            res += s[i];
        }
        return res;
    }
};