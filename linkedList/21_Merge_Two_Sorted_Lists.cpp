#include "linkedList.h"
/* 1 -> 2 -> 4,     1 -> 3 -> 4
 * l1               l2
 * new list l3
 * if(l1 < l2)
 *   l3 = l1
 * else
 *   l3 = l2
 *
 *
 */
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* head = nullptr, *p;
        if(list1 == nullptr && list2 == nullptr){
            return head;
        }
        if(list1 == nullptr){
            return list2;
            
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1 -> val < list2 -> val){
            head = list1;
            list1 = list1 -> next;
        }
        else{
            head = list2;
            list2 = list2 -> next;
        }
        p = head;
        while(list1 && list2){
            if(list1 -> val < list2 -> val){
                p -> next = list1;
                list1 = list1->next;
            }
            else{
                p -> next = list2;
                list2 = list2->next;
            }
            p = p -> next;
        }
        if(list1){
            p -> next = list1;
        }
        if(list2){
            p -> next = list2;
        }
        return head;
    }
};
