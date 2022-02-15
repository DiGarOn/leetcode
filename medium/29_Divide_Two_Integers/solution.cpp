#include <iostream>

using namespace std;

class Solution {
public:
    int sgn(int a) {
        if(a >= 0) return 1;
        else return -1;
    }
    
    long long Mult(long long a, long long b) {
        if (b == 0) {
            return 0;
        }
        if((b&1) == 0) {
            long long x = Mult(a, b>>1);
            return x+x;
        } else {
            long long x = Mult(a, b>>1);
            return x + x + a;
        }
    }
    
    int divide(long long dividend, long long divisor) {
        int val= 1;
        if(sgn(dividend) != sgn(divisor)) {
            val = -1;
        }
        if(dividend == 0) return 0;
        /*
        if(dividend <= -2147483648 || divisor <= -2147483648) {
            if(val > 0) return 2147483647;
            else return -2147483648;
        }
        */
        // if(dividend > 2147483647 || divisor > 2147483647) return 2147483647*val;
        // if(dividend == -2147483648) dividend++;
        // if(divisor == -2147483648) divisor++;
        
        cout << "1 " << abs(dividend) <<" "<< abs(divisor) << '\n';;
        if(abs(dividend) < abs(divisor)) return 0;
        if(abs(dividend) == abs(divisor)) return val;
        long long div = abs(dividend);
        long long dov = abs(divisor);
        cout << div << ' ' << dov << '\n';
        
        long long left = 0;
        long long right = (long long)div + 1;
        long long  med = (right + left)/2;
        cout << "med=" << med << '\n';
        while(right-left > 1 && !(div - Mult(dov,med) < dov && div-Mult(dov,med)>=0)) {
            long long ba = Mult(dov, med);
            cout << '\n' << ba << ' ' << div << '\n';
            if(ba > div) {
                right = med;
            } else {
                left = med;
                cout << "here\n";
            }
            med = (right + left)/2;
        }
        cout << Mult(val,med);
        return min((long long)INT_MAX, max((long long)INT_MIN, Mult(val,med)));
    }
};