// ###################################################### 版本2 ###################################################### //
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy, cur = head;
        for(int i = 0; i < left - 1; i++){
            pre = cur;
            cur = cur->next;
        }
        auto a = pre;
        for(int i = left; i <= right; i++){
            auto ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        a->next->next = cur;
        a->next = pre;
        return dummy->next;
    }
};

// ###################################################### 版本1 ###################################################### //
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
