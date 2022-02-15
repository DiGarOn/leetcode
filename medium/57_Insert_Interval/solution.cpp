#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    vector<int> func(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        for(int i = 0; i < intervals.size(); i++) {
            if(res[0] == -1) {
                if(newInterval[0] <= intervals[i][0]) res[0] = newInterval[0];
                else if(newInterval[0] <= intervals[i][1]) res[0] = intervals[i][0];
            } else {
                break;
            }
        }
        if(res[0] == -1) {
            res[0] = newInterval[0];
        }
        for(int i = intervals.size()-1; i >= 0; i--) {
            if(res[1] == -1) {
                if(newInterval[1] >= intervals[i][1]) res[1] = newInterval[1];
                else if(newInterval[1] >= intervals[i][0]) res[1] = intervals[i][1];
            } else {
                break;
            }
        }
        if(res[1] == -1) {
            res[1] = newInterval[1];
        }
        
        cout << res[0] << " " << res[1] << endl;
        return res;
    }
    
    vector<vector<int>> connect(vector<int> &mas, vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        bool flag = true;
        if(mas[1] < intervals[0][0]) {
            cout << "0" << endl;
            res.push_back(mas);
            flag = false;
        }
        for(int i = 0; i < intervals.size(); i++) {
            if(i+1 < intervals.size()) {
                cout << "1" << endl;
                if(intervals[i][1] < mas[0] && intervals[i+1][0] > mas[1]) {
                    cout << "2" << endl;
                    res.push_back(intervals[i]);
                    if(flag) res.push_back(mas);
                    flag = false;
                } else if(!(intervals[i][1] < mas[0] || intervals[i][0] > mas[1])) {
                    if(flag) res.push_back(mas);
                    flag = false;
                } else if(intervals[i][1] < mas[0] || intervals[i][0] > mas[1]) {
                    cout << "3" << endl;
                    res.push_back(intervals[i]);
                }
            } else {
                cout << "4" << endl;
                if(intervals[i][1] < mas[0] || intervals[i][0] > mas[1])res.push_back(intervals[i]);
            }
        }
        if(flag) {
            cout << "here";
            res.push_back(mas);
        }
        return res;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) {
            vector<vector<int>> res;
            res.push_back(newInterval);
            return res;
        };
        
        vector<int> mas = func(intervals, newInterval);
        return connect(mas, intervals);
        
    }
};