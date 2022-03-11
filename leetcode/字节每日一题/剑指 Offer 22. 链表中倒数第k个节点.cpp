class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head, *q = head;
        for(int i = 0; i < k; i++) q = q->next;
        while(q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};