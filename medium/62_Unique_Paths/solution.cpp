#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int func(vector<vector<int> > &mas, int row, int col, int m, int n) {
        static int count = 0;
        
        cout << "--------row: " << row << endl;
        cout << "--------col: " << col << endl;

        if(row > 0) {
            mas[row][col] += mas[row-1][col];
        }
        if(col > 0) {
            mas[row][col] += mas[row][col-1];
        }
        
        if(row < m-1) {
            if(col < n-1) {
                cout << "col: " << col << endl;
                count += func(mas, row, col+1, m, n);
            }
            cout << "row: " << row << endl;
            count += func(mas, row+1, 0, m, n);
        } 
        
        cout << "+row+" << row << "+col+" << col << endl;
        return count;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int> >mas;
        for(int i = 0; i < n; i++) {
            vector<int> val;
            for(int j = 0; j < m; j++) {
                val.push_back(0);
            }
            mas.push_back(val);
        }
        mas[0][0] = 1;
        
        return func(mas, 0, 0, m, n);
        
        
    }
}A;


int main() {

    int m, n;
    m = 3;
    n = 7;

    cout << A.uniquePaths(m, n);

    return 0;
}