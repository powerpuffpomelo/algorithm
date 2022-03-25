class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        for (int i = 0; i < m - 1; i ++ )
            p = p->next;
        ListNode *a = p, *b = a->next, *c = b->next;
        for (int i = m + 1; i <= n; i ++ )
        {
            ListNode *d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};
