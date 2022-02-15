#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string func(string str) {
        string res = "";
        int l = str.length();
        cout << l << "\n";
        int count = 1;
        char b = str[0];
        for(int i = 1; i < l; i++) {
            char a = b;
            b = str[i];
            cout << a << " " << b << "\n";
            if(a != b) {
                cout << "here\n";
                res += to_string(count) + a; 
                count = 1;
            } else {
                count++;
            }
        }
        res += to_string(count) + str[l-1];
        return res;
        
    }
    
    string countAndSay(int n) {
        string res = "1";
        for(int i = 2; i < n+1; i++) {
            cout << "res : " << res << "\n";
            res = func(res);
            
        }   
        return res;
    }
};  