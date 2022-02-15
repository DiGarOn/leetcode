#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int l = digits.length();
        
        vector<string> res;
        
        if(l == 0) {
            return res;
        } else if(l == 1) {
            for(char letter : letters[digits[0]-'0']) {
                res.push_back(string(1, letter));
            }
        } else if(l == 2) {
            for(char letter1 : letters[digits[0] - '0']) {
                for( char  letter2:letters[digits[1]-'0']) {
                    res.push_back(string(1, letter1) + string(1, letter2));
                }
            }
        } else if(l == 3) {
            for(char  letter1:letters[digits[0]-'0']) {
                for(char letter2:letters[digits[1]-'0']) {
                    for(char letter3:letters[digits[2]-'0']){
                        res.push_back(string(1, letter1) + string(1, letter2) + string(1, letter3));
                    }
                }
            }
        } else if(l == 4) {
            for(char letter1:letters[digits[0]-'0']) {
                for(char letter2:letters[digits[1]-'0']) {
                    for(char letter3:letters[digits[2]-'0']){
                        for(char letter4:letters[digits[3]-'0']){
                            res.push_back(string(1, letter1) + string(1, letter2) + string(1, letter3) + string(1, letter4));
                        }
                    }
                }
            }
        }
        return res;        
    }
};