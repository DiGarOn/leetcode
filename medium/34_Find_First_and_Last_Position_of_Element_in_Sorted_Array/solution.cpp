#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l = -1;
        int r = nums.size();
        int m = (l+r)/2;
        bool flag = false;
        while(r-l>1 && !flag) {
            if(nums[m] > target) {
                r = m;
            } else if(nums[m] < target){
                l = m;
            } 
            m = (r+l)/2;
            if(nums[m] == target) {
                flag = true;
            }
        }
        if(! flag) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        l = m-1;
        bool flag1 = true;
        r = m+1;
        bool flag2 = true;
        while(flag1 || flag2) {
            if(l >= 0 && flag1) {
                if(nums[l] == target) {
                    l -=1;
                } else {
                    l += 1;
                    flag1 = false;
                }
            } else {
                flag1 = false;
            }
            if(r < nums.size() && flag2) {
                cout << nums[r];
                if(nums[r] == target) {
                    r += 1;
                } else {
                    r-=1;
                    flag2 = false;
                }
            } else {
                flag2 = false;
            }
        }
        if(l<0) l = 0;
        if(r >= nums.size()) r = nums.size()-1;
        res.push_back(l);
        res.push_back(r);
        return res;
        
    }
};