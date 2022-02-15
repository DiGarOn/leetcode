#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();
        int m = (r + l)/2;
        bool flag = false;
        while(r-l > 1 && !flag) {
            if(nums[m] > target) {
                r=m;
            } else {
                l=m;
            }
            m = (r+l)/2;
            flag = nums[m] == target;
        }
        if(!flag) {
            if(target> nums[m]) {
                m++;
            } else {
                if(m > 0) m--;
            }
        }
        return m;
    }
};