#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1, l2;
    
        l1 = nums1.size();
        l2 = nums2.size();
            vector<int> val;

            int count_l1, count_l2;
            count_l1 = count_l2 = 0;

            while(count_l2 < l2 || count_l1 < l1) {
                if(count_l1 < l1) {
                    if(count_l2<l2) {
                        if(nums1[count_l1] <= nums2[count_l2]) {
                            val.push_back(nums1[count_l1]);
                            count_l1++;
                        } else {
                            val.push_back(nums2[count_l2]);
                            count_l2++;
                        }
                    } else {
                        val.push_back(nums1[count_l1]);
                        count_l1++;
                    }
                } else {
                    val.push_back(nums2[count_l2]);
                    count_l2++;
                }
            }
        for(int i = 0; i < val.size(); i++){
            cout << val[i] << " ";    
        }        
        cout << l1 << " "<< l2 << "\n";
        if((l1+l2) % 2 != 0) {
            cout << "-1-" << val[(l1+l2)/2]*1.0;
            return val[(l1+l2)/2]*1.0;
        } else {
            cout << "-0-" << (val[(l1+l2)/2] + val[(l1+l2)/2-1])*1.0/2;
            return (val[(l1+l2)/2] + val[(l1+l2)/2-1])*1.0/2;
        }
                
        
    }
};