typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode *next): val(x), next(next){};
}ListNode;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};