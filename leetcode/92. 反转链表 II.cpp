class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        int u = 0;
        auto cur = dummy;
        while(u < left - 1){
            cur = cur->next;
            u++;
        }
        auto temp = cur, pre = cur;
        cur = cur->next;
        u++;
        
        while(u <= right){
            auto ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
            u++;
        }
        temp->next->next = cur;
        temp->next = pre;
        return dummy->next;
    }
};