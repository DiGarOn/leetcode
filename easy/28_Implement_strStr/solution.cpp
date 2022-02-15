#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") {
            return 0;
        }
        int i = haystack.find(needle) ;
        if(i >= 0) {
            return i;
        } else {
            return -1;
        }
    }
};