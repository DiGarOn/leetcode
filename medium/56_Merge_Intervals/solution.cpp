#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> now;
        
        sort(intervals.begin(), intervals.end());
        
        now.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= now[now.size()-1][1]) {
                now[now.size()-1][1] = max(intervals[i][1], now[now.size()-1][1]);
            } else {
                now.push_back(intervals[i]);
            }
        }
        
        return now;
    }
};