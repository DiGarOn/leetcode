#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    vector<int> prefixes(n);
    prefixes[0] = 0;
    int s_one = 0;
    int s_zero = 0;
    for(int i = 1; i < n; i++) {
        if(s[i-1] == '0') {
            s_zero++;
        } else {
            s_one++;
        }
        prefixes[i] = s_one-s_zero;
    }

    cout << -1 << " ";

    if(s[0] == s[1]) cout << 1 << " ";
    else cout << -1 << " ";

    for(int i = 2; i < n; i++) {
        if(s[i] == '1') {
            bool flag = true;
            for(int j = 0; j < i; j++) {
                if(prefixes[i] + 1 - prefixes[j] > 0) {
                    cout << j + 1 << " ";
                    flag = false;
                    break;
                }
            }
            if(flag) cout << -1 << " ";
        } else {
            bool flag = true;
            for(int j = 0; j < i; j++) {
                if(prefixes[i] - 1 - prefixes[j] < 0) {
                    cout << j + 1 << " ";
                    flag = false;
                    break;
                }
            }
            if(flag) cout << -1 << " ";
        }
    }

    return 0;
}