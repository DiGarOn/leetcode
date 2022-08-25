#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

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
        // cout << prefixes[i] << " ";
    }
    // cout << "\n_________________________\n";
    vector<vector<int>> maxs(n, vector<int>(2));
    vector<vector<int>> mins(n, vector<int>(2));
    maxs[1][0] = mins[1][0] = prefixes[1];
    maxs[1][1] = mins[1][1] = 1;
    for(int i = 2; i < n; i++) {
        if(prefixes[i] > maxs[i-1][0]) {
            maxs[i][0] = prefixes[i];
            maxs[i][1] = i;
        } else {
            maxs[i][0] = maxs[i-1][0];
            maxs[i][1] = maxs[i-1][1];
        }
        if(prefixes[i] < mins[i-1][0]) {
            mins[i][0] = prefixes[i];
            mins[i][1] = i;
        } else {
            mins[i][0] = mins[i-1][0];
            mins[i][1] = mins[i-1][1];
        }
    //     cout << maxs[i][0] << " " <<  maxs[i][1] << endl;
    //     cout << mins[i][0] << " " <<  mins[i][1] << endl;
    //     cout << "________________________\n";
    }
    
    cout << -1 << " ";
    for(int i = 1; i < n; i++) {
        if(s[i] == '1') {
            if(prefixes[i] + 1 > 0) {
                cout << 1 << " ";
            } else {
                if(mins[i][1] != i && prefixes[i] - mins[i][0] + 1 >= 0) {
                    cout << mins[i][1] + 1 << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        } else {
            if(prefixes[i] - 1 < 0) {
                cout << 1 << " ";
            } else {
                if(maxs[i][1] != i && prefixes[i] - maxs[i][0] - 1 <= 0) {
                    cout << maxs[i][1] + 1 << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        }
    }

    return 0;
}