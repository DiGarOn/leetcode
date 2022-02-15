#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* last = NULL;
        ListNode* start = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry != 0){
            int d1 = (l1==NULL ? 0 : l1->val);
            int d2 = (l2==NULL ? 0 : l2->val);
            int d = d1 + d2 + carry;
            carry = d/10;
            d %= 10;
            ListNode* arch = new ListNode(d);
            if(start == NULL){
                start = arch;
                last = arch;
            }
            else{
                last->next = arch;
                last = last->next;
            }
            if(l1!= NULL) l1= l1->next;
            if(l2!= NULL) l2= l2->next;
        }
        return start;
    }
};