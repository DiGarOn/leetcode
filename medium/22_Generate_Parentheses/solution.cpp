#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> res;
    void func(int no, int ne, string str) {
        if (no == 0 && ne == 0) {
            res.push_back(str);
        }
        if(no > ne) {
            return;
        }
        if(no>0) {
            func(no-1, ne, str+"(");
        }
        func(no, ne-1, str+")");
    }
    
    vector<string> generateParenthesis(int n) {
        func(n,n,"");
        return res;
        
    }
};