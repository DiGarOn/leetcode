
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res;
        res.val = head.val;
        res.next = head.next;
        
        while(head.next != nullptr) {
            ListNode *net;
            net.val = head.next.val;
            net.next = head.next.next;
            if(head.val != net.val) {
                
            }
        }
    }
};