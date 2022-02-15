#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
         if(nums.size() < 3) {
            return res;
        }
         int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                count++;
            }
        }
         if(count >= 3) {
             vector<int> val = {0,0,0};
             res.push_back(val);
             if(nums.size() == count) {
                 return res;
             }
         }
        vector<int> plus, minus;
        unordered_set<int> un_plus, un_minus;

        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] >= 0) {
        		plus.push_back(nums[i]);
        		un_plus.insert(nums[i]);
        	} else {
        		minus.push_back(nums[i]);
        		un_minus.insert(nums[i]);
        	}
        }
    
         if(plus.size() == 0 || minus.size() == 0) {
             return res;
         }
         
        for(int i = 0; i < plus.size()-1; i++) {
        	for(int j = i+1; j < plus.size(); j++) {
        		auto index = un_minus.find(-plus[i] - plus[j]);
        		if(index != un_minus.end()) {
        			vector<int> val = {plus[i], plus[j], *index};
                    sort(val.begin(), val.end());
                    res.push_back(val);
                }
        	}
        }

        for(int i = 0; i < minus.size()-1; i++) {
        	for(int j = i+1; j < minus.size(); j++) {
        		auto index = un_plus.find(-minus[i] - minus[j]);
        		if(index != un_plus.end()) {
        			vector<int> val = {minus[i], minus[j], *index};
                    sort(val.begin(), val.end());
                    res.push_back(val);
        		}
        	}
        }
         sort(res.begin(), res.end());
         res.erase(unique(res.begin(), res.end()), res.end());
         
        return res;
    }
};