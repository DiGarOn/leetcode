#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<long long> prime(long long a) {
    long long b = 2;
    vector<long long> res = {1};
    while(a > 1) {
        if(b * b > a) break;
        if(a % b == 0) {
            res.push_back(b);
            a /= b;
        } else b++;
    }
    if(a != 1 && a != 0) res.push_back(a);
    return res;
}

long long func(long long a, long long b) {
    vector<long long> v1, v2;
    v1 = prime(a);
    v2 = prime(b);
    
    long long c = 1;
    int i = 0;
    int j = 0;
    while(true) {
        if(v1.size() == i || v2.size() == j) break;
        if(v1[i] == v2[j]) {
            c *= v1[i];
            v1.erase(v1.begin() + i);
            v2.erase(v2.begin() + j);
        } else {
            if(v1[i] < v2[j]) {
                if(i + 1 < v1.size()) {
                    i += 1;
                } else break;
            } else {
                if(j + 1 < v2.size()) {
                    j += 1;
                } else break;
            }
        }
    }
    if(v1.size() == 0) {
        if(v2.size() == 0) {
            return c;
        } else return c*v2.back();
    } else {
        if(v2.size() == 0) {
            return c*v1.back();
        } else return c * max(v1.back(), v2.back());
    }
}

int main() {

    int t, a, b;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        if( a == 1 && b == 1) cout << 1 << endl;
        else cout << func(a, b) << endl;    
    }

    return 0;
}