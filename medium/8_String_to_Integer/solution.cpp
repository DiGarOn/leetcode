#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long int res = 0;
        int v = 1;
        int count = 0;
        bool flag = false;
        string digits = "0123456789";
        //vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 0; i < s.size(); i++) {
            if(count > 1) break;
            if(s[i] == '-') {if(flag){break;} v = -1; count++; flag = true;}
            else if(s[i] == '+') {if(flag){break;} count++; flag = true;}
            else {    
                cout << "digits.find(s[i]): " << (digits.find(s[i])) << endl; 
                if(digits.find(s[i]) < digits.size()) {
                    flag = true;
                    res *= 10;
                    res += int(s[i] - '0');
                    if(res*v > 2147483647) return 2147483647;
                    if(res*v < -2147483648) return -2147483648;
                    cout << res << " ; ";
                } else if(s[i] != ' ' && s[i] != '+' || flag) break; 
            }
        }
        if(res*v > 2147483647) return 2147483647;
        if(res*v < -2147483648) return -2147483648;
        return res*v;
        
    }
};