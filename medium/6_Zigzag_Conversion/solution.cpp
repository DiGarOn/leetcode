#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        } else{
            int l = s.size();
            int pov = -1;
            int row = 0;
            string res = "";
            vector<vector<char>> a (numRows, vector<char>());

            for (int i = 0; i < l; i++){
                a[row].push_back(s[i]);
                if (i % (numRows-1) == 0){
                    pov *= -1;
                }
                row += pov;
            }
            for (int i = 0; i < numRows; i++){
                for (int j = 0; j < a[i].size(); j++){
                    res += a[i][j];
                }
            }
            return res;    
        }
    }
};