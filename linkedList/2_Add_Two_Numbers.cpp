#include "linkedList.h"

class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        int carry = 0, sum = 0;
        ListNode *p1 = l1, *p2 = l2, *cur = new ListNode(0), *head = cur;
        while(p1 || p2 || carry){
            sum = 0;
            if(p1){
                sum += p1 -> val;
            }
            if(p2){
                sum += p2 -> val;
            }
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            cur -> next = new ListNode(sum);
            cur = cur -> next;
            if(p1){
                p1 = p1 -> next;
            }
            if(p2){
                p2 = p2 -> next;
            }        
        }
        return head -> next;
    }
};
