#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            int l1 = strs[i].length();
            int l2 = common.length();
            string val = "";
            for(int j = 0; j < min(l1,l2); j++) {
                    if(strs[i][j] == common[j]) {
                        val += common[j];
                    } else {
                        common = val;
                        break;
                    }
                }
                common = val;
        }
        return common;
    }
};