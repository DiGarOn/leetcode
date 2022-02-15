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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 1;
        ListNode* v = head;
        while(v->next) {
            v = v->next;
            k++;
        }
        
        ListNode* res = head;
        if(k-n == 0) {
            res = head->next;
            return res;
        }
        
        int count = 1;
        while(head->next) {
            if(count == k-n) {
                if(n == 1) {
                    head->next = nullptr;
                    break;
                } else {
                    head->next = head->next->next;
                }
            }
            count++;
            head = head->next;
        }
        return res;
        
    }
};