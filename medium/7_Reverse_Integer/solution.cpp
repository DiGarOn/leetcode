#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x < -2147483648 || x > 2147483647) {
            return 0;
        }
        int val;
        long long int y = x;
        long long int res;
        val = 1;
        if(y < 0) {
            val = -1;
            y *= -1;
        }
        res = 0;
        while(y > 0) {
            size_t a = y % 10;
            if(a == 0 && res == 0) {
                y /= 10;
                continue;
            }
            y /= 10;
            res *= 10;
            res += a;
        }
        if(res < -2147483648 || res > 2147483647) {
            return 0;
        }
        return res*val;
        
    }
};