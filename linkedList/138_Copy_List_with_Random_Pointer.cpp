#include "linkedList.h"
#include <unordered_map>
#include <vector>

class Solution{
public:
    Node* copyRandomList(Node *head){
        Node *p = head, *copy_node, *q;
        std::unordered_map<Node*, Node*> umap;
        umap[nullptr] = nullptr;
        while(p){
            copy_node = new Node(p -> val);
            umap[p] = copy_node;
            p = p -> next;
        }
        p = head;
        while(p){
            q = umap[p];
            q -> next = umap[p -> next];
            q -> random = umap[p ->random];
            p = p -> next;
        }
        return umap[head];
    }
};
