#include "linkedList.h"
/* fast & slow pointer
 * if linked has cycle -> fast pointer must meet slow pointer in the cycle
 * if linked has no cycle -> slow pointer traversal the list until null
 * 
 */
class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
               return true;
            }
        }
        return false;
    }
};
