#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;
        for(int i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
                case 0:
                    count_zero++;
                    break;
                case 1:
                    count_one++;
                    break;
                case 2:
                    count_two++;
                    break;
            }
        }
        for(int i = 0; i < count_zero; i++) {
            nums[i] = 0;
        }
        for(int j = 0; j < count_one; j++) {
            nums[count_zero + j] = 1;
        }
        for(int k = 0; k < count_two; k++) {
            nums[count_zero + count_one+ k] = 2;
        }
        
    }
};