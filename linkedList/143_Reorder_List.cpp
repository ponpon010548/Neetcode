#include "linkedList.h"
/* 1 -> 2 -> 3 -> 4
 * p              q
 * 
 * 1 -> 2 <- 3 <- 4
 * p              q
 * 1 -> 4 -> 2 -> 3
 * s    s
 * f         f
 * 1 -> 4 -> 2 <- 3 <- 5
 * s    s    s
 *           f          f
 * 1 -> 5 -> 4 -> 3 -> 2       
 */          
class Solution{
private:
    void revertList(ListNode **head){
        ListNode *p = *head, *p_next = nullptr, *prev = nullptr;
        while(p){
            p_next = p -> next;
            p -> next = prev;
            prev = p;
            p = p_next;
        }
        *head = prev;
    }
public:
    void reorderList(ListNode* head){
        if(head -> next == nullptr){
            return;
        }
        ListNode* slow = head, *fast = head, *p = head, *q, *tmp;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //prev -> next = nullptr;
        q = slow->next;
        revertList(&q);
        slow -> next = nullptr;
        while(p && q){
            tmp = p -> next;
            p -> next = q;
            p = tmp;
            tmp = q -> next;
            q -> next = p;
            q = tmp;
        }
    }
};
