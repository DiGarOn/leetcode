#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void recurse_solution(vector<vector<int> >& mas, int i, int j, int m, int n) {
        while(i <= m-1) {
            cout << "i: " << i << " j: " << j << endl;
            if(i == 0) {
                while(j <= n-1) {
                    cout << "here1 " << "i: " << i << " j: " << j << endl;
                    if(j > 0) mas[i][j] += mas[i][j-1];
                    j++;
                }
            }
            else {
                cout << "here2 " << "i: " << i << " j: " << j << endl;
                while(j <= n-1) {
                    cout << "here1 " << "i: " << i << " j: " << j << endl;
                    if(j > 0) mas[i][j] += min(mas[i-1][j], mas[i][j-1]);
                    else mas[i][j] += mas[i-1][j];
                    j++;
                }
            }
            i++;
            j = 0;
        }
    }
    
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        recurse_solution(grid, 0, 0, m, n);
        return grid[m-1][n-1];
    }
};