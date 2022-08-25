#include <iostream>
#include <vector>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mas(n, vector<char>(m)), mas_1(n, vector<char>(m)), mas_2(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    // cout << "\n1\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mas_1[i][j] = mas[n-i-1][j];
            // if(mas_1[i][j] == "/") mas_1[i][j] = "\\";
            // else if(mas_1[i][j] == "\\") mas_1[i][j] = "/";
            // cout << mas_1[i][j];
        }
        // cout << endl;
    }
    // cout << "\n2\n";
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            
            if(mas_1[i][j] == '/') {mas_1[i+1][j] = '/'; mas_1[i][j] = '.';}
            else if(mas_1[i][j] == '\\') {mas_1[i+1][j] = '\\'; mas_1[i][j] = '.';}
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << mas_1[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "\n3\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mas_2[i][j] = mas_1[i][m-j-1];
            cout << mas_2[i][j];
        }
        cout << endl;
    }

    return 0;
}