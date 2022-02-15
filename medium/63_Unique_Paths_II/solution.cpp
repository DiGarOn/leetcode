#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverce_solution(vector<vector<int> >& mas, int i, int j, int m, int n) {
        while(i <= m-1) {
            cout << "i: " << i << " j: " << j << endl;
            if(i == 0) {
                while(j <= n-1) {
                    cout << "here1 " << "i: " << i << " j: " << j << endl;
                    if(j > 0) if(mas[i][j] == -1) mas[i][j] = 0;
                        else mas[i][j] += mas[i][j-1];
                    j++;
                }
            }
            else {
                cout << "here2 " << "i: " << i << " j: " << j << endl;
                while(j <= n-1) {
                    cout << "here1 " << "i: " << i << " j: " << j << endl;
                    if(j > 0) { 
                        if(mas[i][j] == -1) mas[i][j] = 0;
                        else {
                            mas[i][j] += mas[i-1][j];
                            mas[i][j] += mas[i][j-1];
                        }
                    }
                    else if(mas[i][j] == -1) mas[i][j] = 0;
                        else mas[i][j] += mas[i-1][j];
                    j++;
                }
            }
            i++;
            j = 0;
        }
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
            }
        }
        obstacleGrid[0][0] = 1;
        
        
        reverce_solution(obstacleGrid, 0, 0, m ,n);
        return obstacleGrid[m-1][n-1];
    }
};