#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;
        int ma = height[0];
        left.push_back(0);
        for(int i = 1; i < height.size(); i++) {
            if(height[i] > ma) {
                ma = height[i];
                left.push_back(i);
            }
        }
        ma = height[height.size()-1];
        right.push_back(height.size()-1);
        for(int i = height.size()-2; i>=0; i--) {
            if(height[i] > ma) {
                ma = height[i];
                right.push_back(i);
            }
        }
        
        vector<int> res;
        if(left.size() == 0 || left[0] == right[0]) return 0; 
        if(left.size() == 1 || right.size() == 1) {
            if(left.size() == 1) {
                if(right.size() == 1) {
                    res.push_back(left[0]);
                    cout << "here1 " << right[0];
                    res.push_back(right[0]);
                }
                else {
                    res.push_back(left[0]);
                    if(left[0] != right[right.size()-1]) res.push_back(right[right.size()-1]);
                    for(int i = right.size()-2; i>= 0; i--) {
                        res.push_back(right[i]);
                    }
                }
            } else {
                res = left;
                if(left[left.size()-1] != right[0]) res.push_back(right[0]); 
            }
        } else {
            for(int i = 0; i < left.size(); i++) {
                res.push_back(left[i]);
            }
            if(left[left.size()-1] != right[right.size()-1]) res.push_back(right[right.size()-1]);
            for(int i = right.size()-2; i >= 0; i--) {
                res.push_back(right[i]);
            }
        }
        
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        
        int s = 0;
        
        for(int i = 0; i < res.size()-1; i++) {
            int val = min(height[res[i]], height[res[i+1]]) * (res[i+1] - res[i]-1);
            if(val == 0) continue;
            for(int j = res[i] + 1; j < res[i+1]; j++) {
                val -= height[j];
            }
            s += val;
            //cout << s << " ";
        }
        
        return s;
        
        
    }
};