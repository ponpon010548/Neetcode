#include "linkedList.h"
/*    dummy -> 1 -> 2 -> 3 -> 4 -> 5    n = 2   we want to find idx = 5 - 2 = 3
 *      pq      
 *                       q
 *
 *                       p         q
 *
 */
class Solution{
public:
    ListNode *removeNthFromEnd(ListNode* head, int n){
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* p = dummy, *q = dummy;
        for(int i = 0; i < n; i++){
            q = q -> next;
        }
        while(q -> next){
            p = p -> next;
            q = q -> next;
        }
        q = p -> next;
        p -> next = p -> next -> next;
        delete q;
        return dummy -> next;
    }
};