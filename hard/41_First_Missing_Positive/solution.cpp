#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mi = 1;
        unordered_set<int> mas;
        for(int i = 0; i < nums.size(); i++) {
            mas.insert(nums[i]);
            if(nums[i] == mi) {
                mi++;
            }
            if(mas.find(mi) != mas.end()) {
                mi++;
            }
        }
        
        while(mas.find(mi) != mas.end()) {
            mi++;
        }
        
        return mi;
    }
};