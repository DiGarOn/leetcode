#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool bin_search(vector<int> &mas, int target) {
        int left = -1;
        cout << "\nsize" << endl;
        cout << mas.size();
        cout << "size1" << endl;
        int right = mas.size()-1;
        
        int med = (left + right)/2;
        cout << "med: " << med;
        while(left < right-1) {
            if(target <= mas[med]) {
                right = med;
            } else {
                left = med;
            }
            med = (left + right)/2;
        }
        return mas[right] == target;
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int l = matrix.size();
        int l_ = matrix[0].size();
        if(l == 1 && l_ == 1) return matrix[0][0] == target;
        if(target > matrix[l-1][l_-1]) return false;
        int row;
        for(int i = 0; i < l; i++) {
            if(i == 0){
                if(target <= matrix[i][l_-1]) {
                    row = i;
                    break;
                    }
            } else {
                if(target > matrix[i-1][l_-1] && target <= matrix[i][l_-1]) {
                    row = i;
                    break;
                }
            }
        }
        cout << "here";
        cout << "row: " << row << endl;
        return bin_search(matrix[row], target);
        
        
    }
};