class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while(cur->val != val){
            pre = cur, cur = cur->next;
        }
        pre->next = cur->next;
        return dummy->next;
    }
};