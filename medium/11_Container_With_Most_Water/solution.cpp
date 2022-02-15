#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int func(const vector<int>& mas) {
        int res = 0;
        int n = mas.size();

        vector<vector<int>> val;
        int ma = 0;
        for(int i = n-1; i >= 0; i--) {
            if(mas[i] > ma) {
                vector<int> as = {mas[i], i};
                val.push_back(as);
                ma = mas[i];
            }
        }
        reverse(val.begin(), val.end());

        for(int i = 0; i < val[0][1]; i++) {
            
            while (mas[i] > val.back()[0]) {
                val.pop_back();
            }

            int pl = mas[i] * (val.back()[1]-i);
            res = max(res, pl);
        }

        return res;
    }

    int maxArea(vector<int>& height) {
        int n = height.size();
        int res1 = func(height);
        reverse(height.begin(), height.end());
        int res2 = func(height);

        return max(res1, res2);
        
    }
};