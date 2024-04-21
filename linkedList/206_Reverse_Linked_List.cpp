#include "linkedList.h"
/*  1 -> 2 -> 3 -> 4 -> 5
 *  prev = nullptr, p = nullptr, p_next;
 *  1 -> 2 -> 3 -> 4 -> 5
 *  p
 *  p   p_next
 *  prev  p, p_next
 *  -----------------------------
 *  null <- 1     2 -------> 3 -> 4 -> 5
 *         prev   p,p_next
 * ...
 * null <- 1 <- 2 <-3 <-4     5
 *                            p
 *                            p_next
 *                      prev          
 *  p_next = p -> next;
 *  p -> next = prev
 *  prev = p
 *  p = p_next
 */
class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode *p = head, *prev = nullptr, *p_next = nullptr;
            while(p){
                p_next = p -> next;
                p -> next = prev;
                prev = p;
                p = p_next;
            }
            return prev;
        }
};
