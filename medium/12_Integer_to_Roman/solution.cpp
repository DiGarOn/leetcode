#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int count = 0;
        int x = num;
        string res;
        while(x > 0) {
            int a = x % 10;
            x /= 10;
            count++;
            if(a == 0) continue;
            if(a == 1) {
                if(count == 1) {
                    res.insert(0, "I");
                } else if(count == 2) {
                    res.insert(0, "X");
                } else if(count == 3) {
                    res.insert(0, "C");
                } else if(count == 4) {
                    res.insert(0, "M");
                }
            } else if(a == 2) {
                if(count == 1) {
                    res.insert(0, "II");
                } else if(count == 2) {
                    res.insert(0, "XX");
                } else if(count == 3) {
                    res.insert(0, "CC");
                } else if(count == 4) {
                    res.insert(0, "MM");
                }
            } else if(a == 3) {
                if(count == 1) {
                    res.insert(0, "III");
                } else if(count == 2) {
                    res.insert(0, "XXX");
                } else if(count == 3) {
                    res.insert(0, "CCC");
                } else if(count == 4) {
                    res.insert(0, "MMM");
                }
            } else if(a == 4) {
                if(count == 1) {
                    res.insert(0, "IV");
                } else if(count == 2) {
                    res.insert(0, "XL");
                } else if(count == 3) {
                    res.insert(0, "CD");
                } 
            } else if(a == 5) {
                if(count == 1) {
                    res.insert(0, "V");
                } else if(count == 2) {
                    res.insert(0, "L");
                } else if(count == 3) {
                    res.insert(0, "D");
                } 
            } else if(a == 6) {
                if(count == 1) {
                    res.insert(0, "VI");
                } else if(count == 2) {
                    res.insert(0, "LX");
                } else if(count == 3) {
                    res.insert(0, "DC");
                } 
            } else if(a == 7) {
                if(count == 1) {
                    res.insert(0, "VII");
                } else if(count == 2) {
                    res.insert(0, "LXX");
                } else if(count == 3) {
                    res.insert(0, "DCC");
                } 
            } else if(a == 8) {
                if(count == 1) {
                    res.insert(0, "VIII");
                } else if(count == 2) {
                    res.insert(0, "LXXX");
                } else if(count == 3) {
                    res.insert(0, "DCCC");
                } 
            } else if(a == 9) {
                if(count == 1) {
                    res.insert(0, "IX");
                } else if(count == 2) {
                    res.insert(0, "XC");
                } else if(count == 3) {
                    res.insert(0, "CM");
                } 
            }
        }
        return res;
    }
};