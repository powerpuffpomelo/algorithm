// ###################################################### 版本1 ###################################################### //
// 我的初版
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        if(!n) return head;
        k %= n;
        if(!k) return head;
        auto new_head = head, pre = dummy;
        for(int i = 0; i < n - k; i++) pre = new_head, new_head = new_head->next;
        pre->next = nullptr;
        auto p = new_head;
        while(p->next) p = p->next;
        p->next = head;
        return new_head;
    }
};