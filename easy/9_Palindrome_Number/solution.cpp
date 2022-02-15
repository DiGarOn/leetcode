#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int b = x;
        vector<int> c;
        while(b > 0) {
            c.push_back(b%10);
            b /= 10;
        }
        bool flag = true;
        for(int i = c.size()-1; i >= 0; i--) {
            if(c[i] != x%10) {
                flag = false;
                break;
            }
            x /= 10;
        }
        return flag;
    }
};